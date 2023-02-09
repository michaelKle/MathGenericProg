cmake_minimum_required(VERSION 3.18)

project(MathGenericProgramming)
set(PROJECT_VERSION 1.0)

set(CXX_STANDARD 17)

add_subdirectory(dependencies/doctest)
add_subdirectory(lib)


function(add_task Prefix main)
    set(TARGET ${Prefix}_${main}.test)
    add_executable(${TARGET})
    target_sources(${TARGET}
        PRIVATE ${main}.cpp
    )
    target_compile_features(${TARGET} PUBLIC cxx_std_17)
    target_link_libraries(${TARGET} doctest::doctest ${libraries})
    target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../Common)
    add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction()

enable_testing()


add_subdirectory(Test)
add_subdirectory(LeetCode)
add_subdirectory(GeeksForGeeks)
add_subdirectory(rsa)

enable_testing()