// #file: header/dynamicLibraries.hpp, module header file

#pragma once

#include "../betterDynamicLibraries.hpp" // Project header file
// Conditionally include platform-specific dll header
#ifdef _WIN32
    #include <libloaderapi.h> 
#else
    #include <dlfcn.h>
#endif

namespace worTech::betterDynamicLibraries::dynamicLibraries{

    // #class: DynamicLibrary, final class object
    class DynamicLibrary final{
    public:
    // public factory methods
        inline DynamicLibrary(const std::string& p_file)noexcept;
        inline DynamicLibrary()noexcept = default; // #default: DynamicLibrary(), default noexcept constructor
        inline DynamicLibrary(const DynamicLibrary&)noexcept = default; // #default: DynamicLibrary(const DynamicLibrary&), default noexcept constructor
        inline DynamicLibrary(DynamicLibrary&&)noexcept = default; // #default: DynamicLibrary(DynamicLibrary&&), default noexcept constructor
        inline ~DynamicLibrary()noexcept;
    // public operators
        inline DynamicLibrary& operator=(const DynamicLibrary&)noexcept = default; // #default: operator=(const DynamicLibrary&), default noexcept operator
        inline DynamicLibrary& operator=(DynamicLibrary&&)noexcept = default; // #default: operator=(DynamicLibrary&&), default noexcept operator
        inline explicit operator bool()const;
    // public static methods
        inline static DynamicLibrary load(const std::string& p_file);
        inline static DynamicLibrary load(const std::filesystem::path& p_file);
        inline void error();
    // public methods
        inline void loadLibrary(const std::string& p_file);
        inline void loadLibrary(const std::filesystem::path& p_file);
        inline void freeLibrary();
        inline bool loaded()const;
        template<typename T_function> inline std::function<T_function> getFunction(const std::string& p_functionName)const;
    private:
    // private members
        void* m_handle;
        bool m_loaded;
    }; // #end: DynamicLibrary

} // namespace worTech::betterDynamicLibraries::dynamicLibraries

#include "../source/dynamicLibraries.hpp" // Module source file