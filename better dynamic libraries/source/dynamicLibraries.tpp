// #file: dynamicLibraries.tpp, template implementation file

#pragma once

#include "dynamicLibraries.hpp" // Module header file

namespace worTech::betterCpp::dynamicLibraries{

// #from: DynamicLibrary, method definitions

// #div: public methods

    // #func: getFunction(const std::string&), template const method
    // #template: typename T_function, function type to retrieve
    // #param: const std::string& p_functionName, function name to retrieve
    // #return: std::function<T_function>, retrieved function pointer
    template<typename T_function> std::expected<std::function<T_function>, std::string> DynamicLibrary::getFunction(const std::string& p_functionName)const{
        if(!m_loaded){
            return std::unexpected(error::CANNOT_GET_FUNC_WHEN_NOT_LOADED);
        }
        #ifdef _WIN32
            T_function* function = reinterpret_cast<T_function*>(GetProcAddress(static_cast<HMODULE>(m_handle), p_functionName.c_str()));
            if(!function) return std::unexpected(std::vformat(error::FAILED_TO_GET_FUNC, std::make_format_args(p_functionName, m_name)));
            return std::function<T_function>(function);
        #else
            T_function* function = reinterpret_cast<T_function*>(dlsym(m_handle, p_functionName.c_str()));
            if(!function) return std::unexpected(std::format(error::FAILED_TO_GET_FUNC, p_functionName, m_name));
            return std::function<T_function>(function);
        #endif
    } // #end: getFunction(const std::string&)

} // worTech::betterCpp::dynamicLibraries
