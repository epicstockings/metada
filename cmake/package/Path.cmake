# Get package path from common variables
function(get_package_path package out_var)
    string(TOUPPER ${package} PACKAGE_UPPER)
    
    if(DEFINED ${package}_DIR)
        set(path "${${package}_DIR}")
    elseif(DEFINED ${package}_ROOT)
        set(path "${${package}_ROOT}")
    elseif(DEFINED ${package}_PATH)
        set(path "${${package}_PATH}")
    # Special case for CUDA toolkit binary directory
    elseif(DEFINED ${package}_BIN_DIR)
        set(path "${${package}_BIN_DIR}")
    elseif(DEFINED ${PACKAGE_UPPER}_EXECUTABLE)
        set(path "${${PACKAGE_UPPER}_EXECUTABLE}")
    elseif(DEFINED ${package}_EXECUTABLE)
        set(path "${${package}_EXECUTABLE}")
    elseif(DEFINED _${package}_EXECUTABLE)
        set(path "${_${package}_EXECUTABLE}")
    else()
        set(path "")
    endif()
    
    set(${out_var} "${path}" PARENT_SCOPE)
endfunction() 