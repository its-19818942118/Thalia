#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>

#include "functions.hpp"

namespace ConfigurFN
{
    
    bool kbInput ( )
    {
        
        struct termios oldt , newt;
        int ch , oldf;
        
        // Get the terminal settings for stdin
        tcgetattr ( STDIN_FILENO , & oldt );
        newt = oldt;
        // Disable canonical mode and echo
        newt.c_lflag &= ~( ICANON | ECHO );
        // Set the new terminal settings
        tcsetattr ( STDIN_FILENO , TCSANOW , &newt );
        // Get the current file status flags
        oldf = fcntl ( STDIN_FILENO , F_GETFL , 0 );
        // Set non-blocking mode
        fcntl ( STDIN_FILENO , F_SETFL , oldf | O_NONBLOCK );
        
        ch = getchar ( );
        
        // Restore the old terminal settings
        tcsetattr ( STDIN_FILENO , TCSANOW , &oldt );
        // Restore the old file status flags
        fcntl ( STDIN_FILENO , F_SETFL , oldf );
        
        if ( ch != EOF )
        {
            
            ungetc ( ch , stdin );
            return true;
            
        }
        
        return false;
        
    }
    
} // namespace ConfigurFN
