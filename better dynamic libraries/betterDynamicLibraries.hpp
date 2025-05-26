// #file: betterDynamicLibraries.hpp, project header file

#include "header/standardLibraries.hpp" // Project wide standard libraries
#include "header/externalLibraries.hpp" // Project wide external libraries

#pragma once

// #namespace: worTech, inline developer namespace
inline namespace worTech{

    // #namespace: betterDynamicLibraries, project namespace
    namespace btr{

        // #namespace: dynamicLibraries, inline module namespace
        inline namespace dynamicLibraries{
            namespace errorMessages{}
            namespace error = errorMessages; // alias errorMessages to error
            class DynamicLibrary;
        } // #end: dynamicLibraries

    } // #end: betterDynamicLibraries
    
} // #end: worTech

#define WT_ODR_IGNORE inline