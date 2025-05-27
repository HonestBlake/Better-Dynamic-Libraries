// #file: betterDynamicLibraries.hpp, project header file

#include "standardLibraries.hpp" // Project wide standard libraries
#include "externalLibraries.hpp" // Project wide external libraries

#pragma once

// #namespace: worTech, inline developer namespace
inline namespace worTech{

    // #namespace: betterCpp, project namespace
    namespace betterCpp{

        // #namespace: dynamicLibraries, inline module namespace
        inline namespace dynamicLibraries{
            namespace errorMessages{}
            namespace error = errorMessages; // alias errorMessages to error
            class DynamicLibrary;
        } // #end: dynamicLibraries

    } // #end: betterCpp
    namespace better = betterCpp; // alias betterCpp to better
    namespace btr = betterCpp; // alias betterCpp to btr
    
} // #end: worTech
namespace wt = worTech; // alias worTech to wt

#define WT_ODR_IGNORE inline