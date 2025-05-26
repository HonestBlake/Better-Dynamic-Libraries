// #file: betterDynamicLibraries.hpp, project header file

#include "header/standardLibraries.hpp" // Project wide standard libraries
#include "header/externalLibraries.hpp" // Project wide external libraries

#pragma once

// #namespace: worTech, inline developer namespace
inline namespace worTech{

    // #namespace: betterDynamicLibraries, project namespace
    namespace betterDynamicLibraries{

        // #namespace: dynamicLibraries, inline module namespace
        inline namespace dynamicLibraries{
            namespace errorMessages{}
            namespace error = errorMessages; // alias errorMessages to error
            class DynamicLibrary;
        } // #end: dynamicLibraries

    } // #end: betterDynamicLibraries
    namespace better = betterDynamicLibraries; // alias betterDynamicLibraries to better
    namespace btr = betterDynamicLibraries; // alias betterDynamicLibraries to btr
    
} // #end: worTech

#define WT_ODR_IGNORE inline