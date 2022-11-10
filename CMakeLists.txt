cmake_minimum_required(VERSION 3.18)

project(MathGenericProgramming)
set(PROJECT_VERSION 1.0)

add_subdirectory(dependencies/doctest)


function(add_example Prefix main)
    set(TARGET ${Prefix}_${main}.test)
    add_executable(${TARGET})
    target_sources(${TARGET}
        PRIVATE ${main}.cpp
    )
    target_link_libraries(${TARGET} doctest::doctest)
    target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../Common)
    add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction()

enable_testing()

add_subdirectory(LeetCode)
add_subdirectory(GeeksForGeeks)
add_subdirectory(rsa)

enable_testing()