# src/CMakeLists.txt
add_executable(fs_test main.cpp)

# Windows MSVC 特定配置
if(MSVC)
    target_compile_options(fs_test PRIVATE 
        /W4     # 警告级别
        /utf-8  # UTF-8编码
    )
else()
    # GCC/Clang 配置
    target_compile_options(fs_test PRIVATE 
        -Wall 
        -Wextra
    )
endif()

# 如果启用了测试
if(CMAKE_TESTING_ENABLED)
    add_test(
        NAME FSTest
        COMMAND fs_test
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )
endif()