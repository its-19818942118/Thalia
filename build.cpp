#include <vector>
#include <cstdlib>
#include <iostream>
#include <string_view>

#define _attribute_maybe_unused_ [[ maybe_unused ]]

namespace Thalia
{
    
    void compileBuilder ( );
    void buildRelease ( );
    void cleanBuild ( );
    
    void builderArguments ( int argc , char * argv [ ] )
    {
        for ( int i = 1; i < argc; ++i )
        {
            
            std::string_view args = argv [ i ];
            
            if ( args == "--compile" || args == "-c" )
            {
                
                Thalia::compileBuilder ( );
                return;
                
            }
            
            else if ( args == "--build==release" || args == "-b" )
            {
                
                Thalia::buildRelease ( );
                
            }
            
            else if ( args == "--build==clean" || args == "-b" || args == "-cb" )
            {
                
                Thalia::cleanBuild ( );
                
            }
            
            else if ( args == "--build==cleanCompile" || args == "-ccb" )
            {
                
                Thalia::cleanBuild ( );
                
            }
            
        }
    }
    
    void compileBuilder ( )
    {
        
        std::cout
            <<  "Compiling Build System"
            <<  "\n"
        ;
        
        const char * cmdBuilder
        {
            
            R"(
                g++ -std=c++23 -march=native -mtune=native -o3 -oz -ofast -DNDEBUG \
                build.cpp \
                -o builder \
            )"
            
        };
        
        system ( cmdBuilder );
        
        std::cout
            <<  "Build System Compiled Successfully"
            <<  "\n"
            <<  "Exited with return code 0"
        ;
        
    }
    
    void buildRelease ( )
    {
        
        std::cout
            <<  "Building Release Executable"
            <<  "\n"
        ;
        
        const char * cmdBuild
        {
            
            R"(
                g++ -std=c++23 -flto -ftree-vectorize -funroll-loops -floop-strip-mine -o3 \
                -fstrict-aliasing -fomit-frame-pointer -march=native -mtune=native -oz -ofast \
                -fno-exceptions -fno-rtti -fdata-sections -ffunction-sections -Wl,--gc-sections \
                -g include/functions/donut.cpp include/functions/kbInput.cpp -DNDEBUG \
                -I ./include src/main.cpp \
                -o build/bin/Thalia \
            )"
            
        };
        
        system ( cmdBuild );
        
        std::cout
            <<  "Successfully Built Executable Binary ..."
            <<  "\n"
            <<  "Compiled binary is on ./build/bin"
            <<  "\n"
            <<  "Project builder exited with return code 0"
        ;
        
    }
    
    void cleanBuild ( )
    {
        
        std::cout
            <<  "Starting Clean Build Of The Project \"Thalia\" ... "
            <<  "\n"
        ;
        
        std::cout
            <<  "Recursively removing `build` ... `bin` ... `objects` Files/Folders ... "
            <<  "\n"
        ;
        
        const char * cmdClean
        {
            
            R"(
                rm -rf build
            )"
            
        };
        
        system ( cmdClean );
        
        std::cout
            <<  "Setting up evironment"
            <<  "\n"
        ;
        
        system ("mkdir -p build/bin" );
        system ("mkdir -p build/objects" );
        
        Thalia::buildRelease ( );
        
    }
    
} // namespace Thalia


// int main ( [[ __attribute_maybe_unused__ ]] int argc , [[ __attribute_maybe_unused__ ]] char * argv [ ] )
int main ( _attribute_maybe_unused_ int argc , _attribute_maybe_unused_ char * argv [ ] )
{
    
    // system ( cmdBuild );
    
    // Thalia::compileBuilder ( );
    
    Thalia::builderArguments ( argc , argv );
    
    
    
}
