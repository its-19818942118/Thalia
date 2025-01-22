#include <vector>
#include <cstdlib>
#include <iostream>
#include <string_view>

#define _attribute_maybe_unused_ [[maybe_unused]]

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
        std::cout << "Compiling Build System\n";

        const char * cmdBuilder = R"(
            g++ -std=c++23 -static -march=native -mtune=native -o3 -oz -ofast -DNDEBUG \
            build.cpp \
            -o builder \
        )";

        int result = system ( cmdBuilder );
        if ( result != 0 )
        {
            std::cerr << "Error: Failed to compile the build system. Return code: " << result << "\n";
            return;
        }

        std::cout << "Build System Compiled Successfully\n"
            << "Exited with return code 0\n";
    }

    void buildRelease ( )
    {
        std::cout << "Building Release Executable\n";

        const char * cmdBuild = R"(
            g++ -std=c++23 -flto -ftree-vectorize -funroll-loops -floop-strip-mine -o3 \
            -fstrict-aliasing -fomit-frame-pointer -march=native -mtune=native -oz -ofast \
            -fno-exceptions -fno-rtti -fdata-sections -ffunction-sections -Wl,--gc-sections \
            -g include/functions/donut.cpp include/functions/kbInput.cpp -static -DNDEBUG \
            -I ./include src/main.cpp \
            -o build/bin/Thalia \
        )";

        int result = system ( cmdBuild );
        if ( result != 0 )
        {
            std::cerr << "Error: Failed to build the release executable. Return code: " << result << "\n";
            return;
        }

        std::cout << "Successfully Built Executable Binary ...\n"
            << "Compiled binary is on ./build/bin\n"
            << "Project builder exited with return code 0\n";
    }

    void cleanBuild ( )
    {
        std::cout << "Starting Clean Build Of The Project \"Thalia\" ...\n";
        std::cout << "Recursively removing `build` ... `bin` ... `objects` Files/Folders ...\n";

        const char * cmdClean = R"(
            rm -rf build
        )";

        int result = system ( cmdClean );
        if ( result != 0 )
        {
            std::cerr << "Error: Failed to clean the build directory. Return code: " << result << "\n";
            return;
        }

        std::cout << "Setting up environment\n";

        result = system ( "mkdir -p build/bin" );
        if ( result != 0 )
        {
            std::cerr << "Error: Failed to create build/bin directory. Return code: " << result << "\n";
            return;
        }

        result = system ( "mkdir -p build/objects" );
        if ( result != 0 )
        {
            std::cerr << "Error: Failed to create build/objects directory. Return code: " << result << "\n";
            return;
        }

        Thalia::buildRelease ( );
    }
}

int main ( _attribute_maybe_unused_ int argc , _attribute_maybe_unused_ char * argv [ ] )
{
    std::cout
        <<  "Thalis Version 0.0.10"
    ;
    
    Thalia::builderArguments ( argc , argv );
    return 0;
}
