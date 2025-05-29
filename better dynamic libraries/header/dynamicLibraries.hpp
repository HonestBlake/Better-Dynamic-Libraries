// #file: dynamicLibraries.hpp, module header file

#pragma once

#include "betterDynamicLibraries.hpp" // Project header file
// Conditionally include platform-specific dll header
#ifdef _WIN32
    #include <libloaderapi.h> 
#else
    #include <dlfcn.h>
#endif

namespace worTech::betterCpp::dynamicLibraries{

    // #namespace: errorMessages(error), variable namespace
    namespace errorMessages{
        inline const std::string CANNOT_GET_FUNC_WHEN_NOT_LOADED = "Cannot get function when library is not loaded.";
        inline const std::string FAILED_TO_LOAD_LIBRARY = "Failed to load library: {}";
        inline const std::string FAILED_TO_GET_FUNC = "Failed to get function: {} from library: {}";
    } // #end: errorMessages

    // #class: DynamicLibrary, final class object
    class DynamicLibrary final{
    public:
    // public factory methods
        DynamicLibrary(const std::string& p_file)noexcept;
        DynamicLibrary()noexcept = default; // #default: DynamicLibrary(), default noexcept constructor
        DynamicLibrary(const DynamicLibrary&)noexcept = default; // #default: DynamicLibrary(const DynamicLibrary&), default noexcept constructor
        DynamicLibrary(DynamicLibrary&&)noexcept = default; // #default: DynamicLibrary(DynamicLibrary&&), default noexcept constructor
        ~DynamicLibrary()noexcept;
    // public operators
        DynamicLibrary& operator=(const DynamicLibrary&)noexcept = default; // #default: operator=(const DynamicLibrary&), default noexcept operator
        DynamicLibrary& operator=(DynamicLibrary&&)noexcept = default; // #default: operator=(DynamicLibrary&&), default noexcept operator
        explicit operator bool()const;
    // public static methods
        [[nodiscard]] static DynamicLibrary load(const char* p_file);
        [[nodiscard]] static DynamicLibrary load(const std::string& p_file);
        [[nodiscard]] static DynamicLibrary load(const std::filesystem::path& p_file);
        void error();
    // public methods
        void loadLibrary(const std::string& p_file);
        void loadLibrary(const std::filesystem::path& p_file);
        void freeLibrary();
        bool loaded()const;
        std::string name()const;
        template<typename T_function> std::expected<std::function<T_function>, std::string> getFunction(const std::string& p_functionName)const;
    private:
    // private members
        std::string m_name;
        void* m_handle;
        bool m_loaded;
    }; // #end: DynamicLibrary

} // namespace worTech::betterDynamicLibraries::dynamicLibraries

#include "dynamicLibraries.tpp" // Module source file