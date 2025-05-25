// #file: source/betterDynamicLibraries.hpp, module source file

#pragma once

#include "../header/dynamicLibraries.hpp" // Module header file

namespace worTech::betterDynamicLibraries::dynamicLibraries{

// #from: DynamicLibrary, method definitions

// #div: public factory methods

    // #func: DynamicLibrary(const std::string&), noexcept constructor
    // #param: const std::string& p_file, library file path
    DynamicLibrary::DynamicLibrary(const std::string& p_file)noexcept{
        loadLibrary(p_file);
    } // #end: DynamicLibrary(const std::string&)

    // #func: ~DynamicLibrary(), no except destructor
    DynamicLibrary::~DynamicLibrary()noexcept{
        freeLibrary();
    } // #end: ~DynamicLibrary()

// #div: public operators

    // #func: operator=(const DynamicLibrary&), const operator
    // #return: bool, if the library is loaded
    DynamicLibrary::operator bool()const{
        return m_loaded;
    } // #end: operator=(const DynamicLibrary&)

// #div: public static methods

    // #func: load(const std::string&), method
    // #param: const std::string& p_file, library file path
    // #return: DynamicLibrary, created dynamic library object
    DynamicLibrary DynamicLibrary::load(const std::string& p_file){
        return DynamicLibrary(p_file);
    }

    // #func: load(const std::filesystem::path&), method
    // #param: const std::filesystem::path& p_file, library file path
    // #return: DynamicLibrary, created dynamic library object
    DynamicLibrary DynamicLibrary::load(const std::filesystem::path& p_file){
        return DynamicLibrary(p_file.string());
    } // #end: load(const std::filesystem::path&)

// #div: public methods

    // #func: loadLibrary(const std::string&), method
    // #param: const std::string& p_file, library file path
    void DynamicLibrary::loadLibrary(const std::string& p_file){
        #ifdef _WIN32
            m_handle = LoadLibraryA(p_file.c_str());
        #else
            m_handle = dlopen(p_file.c_str(), RTLD_LAZY);
        #endif
        m_loaded = m_handle? true : false;
    } // #end: loadLibrary(const std::string&)

    // #func: loadLibrary(const std::filesystem::path&), method
    // #param: const std::filesystem::path& p_file, library file path
    void DynamicLibrary::loadLibrary(const std::filesystem::path& p_file){
        load(p_file.string());
    } // #end: loadLibrary(const std::filesystem::path&)

    // #func: freeLibrary(), method
    void DynamicLibrary::freeLibrary(){
        if(m_loaded){
            #ifdef _WIN32
                FreeLibrary(static_cast<HMODULE>(m_handle));
            #else
                dlclose(m_handle);
            #endif
            m_loaded = false;
        }
    } // #end: freeLibrary()

    // #func: loaded(), method
    // #return: bool, if the library is loaded
    bool DynamicLibrary::loaded()const{
        return m_loaded;
    }

    // #func: getFunction(const std::string&), template const method
    // #template: typename T_function, function type to retrieve
    // #param: const std::string& p_functionName, function name to retrieve
    // #return: std::function<T_function>, retrieved function pointer
    template<typename T_function> std::function<T_function> DynamicLibrary::getFunction(const std::string& p_functionName)const{
        if(!m_loaded){
            // TODO error call
        }
        #ifdef _WIN32
            return std::function<T_function>(reinterpret_cast<T_function*>(GetProcAddress(static_cast<HMODULE>(m_handle), p_functionName.c_str())));
        #else
            return reinterpret_cast<T_function>(dlsym(m_handle, p_functionName.c_str()));
        #endif
    } // #end: getFunction(const std::string&)

} // namespace worTech::betterDynamicLibraries::dynamicLibraries