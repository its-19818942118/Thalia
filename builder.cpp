#include <iostream>
#include <string_view>
#include <vector>

// Function declarations
void build(const std::vector<std::string_view>& positionalArgs) {
    std::cout << "Building the project..." << std::endl;
    if (!positionalArgs.empty()) {
        std::cout << "With arguments: ";
        for (const auto& arg : positionalArgs) {
            std::cout << arg << " ";
        }
        std::cout << std::endl;
    }
}

void clean() {
    std::cout << "Cleaning the project..." << std::endl;
}

void help() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "  --build, -b   Build the project" << std::endl;
    std::cout << "  --clean, -c   Clean the project" << std::endl;
    std::cout << "  --help, -h    Show this help message" << std::endl;
}

void parseArguments(int argc, char* argv[]) {
    std::vector<std::string_view> positionalArgs;
    bool commandFound = false;

    for (int i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];

        if (arg == "--build" || arg == "-b") {
            commandFound = true;
            build(positionalArgs);
            positionalArgs.clear(); // Clear positional arguments after command execution
        } else if (arg == "--clean" || arg == "-c") {
            commandFound = true;
            clean();
        } else if (arg == "--help" || arg == "-h") {
            help();
            return; // Exit after showing help
        } else {
            // Treat as a positional argument
            positionalArgs.push_back(arg);
        }
    }

    // If no command was found, show help
    if (!commandFound) {
        std::cout << "No command provided." << std::endl;
        help();
    }
}

int main(int argc, char* argv[]) {
    parseArguments(argc, argv);
    return 0;
}
