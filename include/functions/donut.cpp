#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <bits/algorithmfwd.h>
#include <bits/this_thread_sleep.h>
#include <cmath>
#include <iostream>

#include "functions.hpp"

namespace ConfigurFN
{
    
    // Function for Displaying a spinning donut
    void donut ( )
    {
        
        bool donutRunning = true;
        
        int k;
        float i , j;
        float A = 0 , B = 0;
        char b [ 1760 ] = { 0 };
        float z [ 1760 ] = { 0 };
        
        std::cout
            << "\x1b[2J"
        ;
        
        while ( donutRunning == true )
        {
            
            std::fill ( b , b + 1760 , ' ' );
            std::fill ( z , z + 1760 , 0.0f );
            
            for ( j = 0; j < 6.28; j += 0.07 )
            {
                
                for ( i = 0; i < 6.28; i += 0.02 )
                {
                    
                    float c = sin ( i );
                    float d = cos ( j );
                    float e = sin ( A );
                    float f = sin ( j );
                    float g = cos ( A );
                    float h = d + 2;
                    float D = 1 / ( c * h * e + f * g + 5 );
                    float l = cos ( i );
                    float m = cos ( B );
                    float n = sin ( B );
                    float t = c * h * g - f * e;
                    int x = 40 + 30 * D * ( l * h * m - t * n );
                    int y = 12 + 15 * D * ( l * h * n + t * m );
                    int o = x + 80 * y;
                    int N = 8 * ( ( f * e - c * d * g ) * m - c * d * e - f * g - l * d * n );
                    
                    if ( 22 > y && y > 0 && x > 0 && 80 > x && D > z [ o ] )
                    {
                        
                        z [ o ] = D;
                        b [ o ] = ".,-~:;=!*#$@" [ N > 0 ? N : 0 ];
                        
                    }
                    
                }
                
            }
            
            std::cout
                << "\x1b[H"
            ;
            
            for ( k = 0; k < 1761; k++ )
            {
                
                std::cout
                    << ( k % 80 ? b [ k ] : '\n' )
                ;
                
                A += 0.00004;
                B += 0.00002;
                
            }
            
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 30 ) );
            
            // Check for exit key press
            if ( ConfigurFN::kbInput ( ) && getchar ( ) == 'q' )
            {
                
                donutRunning = false;
                printf ( "\r" );
                
            }
            
        }
        
    }
    
} // namespace ConfigurFN
