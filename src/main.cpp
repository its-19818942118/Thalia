#include <iostream>
#include "functions.hpp"

int main ( )
{
    
    std::cout
        <<  "Hello, World"
    ;
    
    ConfigurFN::donut ( );
    
    #ifdef _ok_
    
    for ( int x { 0 }; x >= 0; x++ )
    {
        
        std::cout
            <<  x
            <<  '\n'
            <<  x
        ;
        
    }
    
    #endif
    
    return 0;
    
}
