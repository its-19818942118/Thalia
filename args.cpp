#include <iostream>
#include <string>
#include <vector>

void parseArguments ( int argc , char * argv [ ] )
{
    std::vector<std::string> positionalArgs;

    for ( int i = 1; i < argc; ++i )
    {
        std::string arg = argv [ i ];

        // Check for long options (e.g., --option=value)
        if ( arg.starts_with ( "--" ) )
        {
            size_t pos = arg.find ( '=' );
            if ( pos != std::string::npos )
            {
                std::string key = arg.substr ( 2 , pos - 2 );
                std::string value = arg.substr ( pos + 1 );
                std::cout << "Option: " << key << ", Value: " << value << std::endl;
            }
            else
            {
                std::cout << "Option: " << arg.substr ( 2 ) << ", Value: (no value provided)" << std::endl;
            }
        }
        // Check for short options (e.g., -o)
        else if ( arg.starts_with ( "-" ) )
        {
            std::cout << "Option: " << arg.substr ( 1 ) << ", Value: (no value provided)" << std::endl;
        }
        // Positional arguments
        else
        {
            positionalArgs.push_back ( arg );
        }
    }

    // Print positional arguments
    for ( const auto & posArg : positionalArgs )
    {
        std::cout << "Positional Argument: " << posArg << std::endl;
    }
}

int main ( int argc , char * argv [ ] )
{
    parseArguments ( argc , argv );
    return 0;
}
