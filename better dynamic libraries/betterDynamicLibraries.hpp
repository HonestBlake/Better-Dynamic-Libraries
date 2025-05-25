// #file: betterDynamicLibraries.hpp, project header file

#include "header/standardLibraries.hpp" // Project wide standard libraries
#include "header/externalLibraries.hpp" // Project wide external libraries

#pragma once

// #namespace: worTech, inline developer namespace
inline namespace worTech{

    // #namespace: betterDynamicLibraries, project namespace
    namespace betterDynamicLibraries{

        // #namespace: debugging, inline module namespace
        inline namespace debugging{
            namespace errorMessages{}
            namespace error = errorMessages; // alias errorMessages to error
            namespace debugTools{}
            namespace debug = debugTools; // alias debugTools to debug
            namespace loggerValues{}
            namespace logger = loggerValues; // alias loggerValues to logger
            class BetterDynamicLibraryDebug;
        } // #end: debugging

        // #namespace: dynamicLibraries, inline module namespace
        inline namespace dynamicLibraries{
            class DynamicLibrary;
        } // #end: dynamicLibraries

    } // #end: betterDynamicLibraries
    namespace better = betterDynamicLibraries; // alias betterDynamicLibraries to better
    namespace btr = betterDynamicLibraries; // alias betterDynamicLibraries to btr
    
} // #end: worTech
