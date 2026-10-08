include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(TP_MINIPROJ_2_PL4_G2_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(TP_MINIPROJ_2_PL4_G2_default_default_XC8_FILE_TYPE_assemble)
add_library(TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemble OBJECT ${TP_MINIPROJ_2_PL4_G2_default_default_XC8_FILE_TYPE_assemble})
    TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemble_rule(TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemble)
    list(APPEND TP_MINIPROJ_2_PL4_G2_default_library_list "$<TARGET_OBJECTS:TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(TP_MINIPROJ_2_PL4_G2_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemblePreprocess OBJECT ${TP_MINIPROJ_2_PL4_G2_default_default_XC8_FILE_TYPE_assemblePreprocess})
    TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemblePreprocess_rule(TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemblePreprocess)
    list(APPEND TP_MINIPROJ_2_PL4_G2_default_library_list "$<TARGET_OBJECTS:TP_MINIPROJ_2_PL4_G2_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(TP_MINIPROJ_2_PL4_G2_default_default_XC8_FILE_TYPE_compile)
add_library(TP_MINIPROJ_2_PL4_G2_default_default_XC8_compile OBJECT ${TP_MINIPROJ_2_PL4_G2_default_default_XC8_FILE_TYPE_compile})
    TP_MINIPROJ_2_PL4_G2_default_default_XC8_compile_rule(TP_MINIPROJ_2_PL4_G2_default_default_XC8_compile)
    list(APPEND TP_MINIPROJ_2_PL4_G2_default_library_list "$<TARGET_OBJECTS:TP_MINIPROJ_2_PL4_G2_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(TP_MINIPROJ_2_PL4_G2_default_image_P7_IJYBW ${TP_MINIPROJ_2_PL4_G2_default_library_list})

set_target_properties(TP_MINIPROJ_2_PL4_G2_default_image_P7_IJYBW PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${TP_MINIPROJ_2_PL4_G2_default_output_dir}")
target_link_libraries(TP_MINIPROJ_2_PL4_G2_default_image_P7_IJYBW PRIVATE ${TP_MINIPROJ_2_PL4_G2_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
TP_MINIPROJ_2_PL4_G2_default_link_rule( TP_MINIPROJ_2_PL4_G2_default_image_P7_IJYBW)



