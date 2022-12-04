project(tests LANGUAGES CXX)

file(GLOB_RECURSE TEST_FILES "*.cpp")

foreach(_file ${TEST_FILES})
    get_filename_component(_exe_name ${_file} NAME_WE)

    add_executable(${_exe_name} EXCLUDE_FROM_ALL ${_file})
    target_link_libraries(${_exe_name} ntcore)

    add_test(NAME ${_exe_name} COMMAND ${_exe_name})
    list(APPEND TESTS ${_exe_name})
endforeach()

add_custom_target(unit_test ALL
        COMMAND ${CMAKE_CTEST_COMMAND} ${CMAKE_CTEST_ARGUMENTS}
        DEPENDS ${TESTS})
