MACRO(LS_FOR_TESTS)
    SET(__next_base_dir_)
    SET(__base_dir_ "")
    SET(__dirs_)
    FOREACH(__item_ ${ARGN})
        IF ("${__item_}" STREQUAL "BASEDIR")
            SET(__next_base_dir_ yes)
        ELSE ()
            IF (__next_base_dir_)
                SET(__base_dir_ ${__item_})
                SET(__next_base_dir_)
            ELSE ()
                SET_APPEND(__dirs_ ${__item_})
            ENDIF ()
        ENDIF ()
    ENDFOREACH ()

    SET(__global_)
    FOREACH(__dir_ ${__dirs_})
        IF ("${__dir_}" STREQUAL "GLOBAL")
            SET(__global_ "GLOBAL")
        ELSE ()
            IF ("X${__base_dir_}X" STREQUAL "XX")
                SET(__rel_dir_ ${__dir_})
            ELSE ()
                SET(__rel_dir_ ${__base_dir_}/${__dir_})
            ENDIF ()

            IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${__rel_dir_})
                SET(__dir_abs_path_ ${CMAKE_CURRENT_SOURCE_DIR}/${__rel_dir_})
            ELSEIF (EXISTS ${ARCADIA_ROOT}/${__rel_dir_})
                SET(__dir_abs_path_ ${ARCADIA_ROOT}/${__rel_dir_})
            ELSEIF (EXISTS ${__rel_dir_})
                SET(__dir_abs_path_ ${__rel_dir_})
            ELSE ()
                MESSAGE("Absolute path to ${__rel_dir_} not found")
            ENDIF ()
            SET(__srcs_)
            AUX_SOURCE_DIRECTORY(${__dir_abs_path_} __srcs_)

            STRING(REPLACE "/" "\\" __group_name_ "${__dir_}")
            SOURCE_GROUP(${__group_name_} FILES ${__srcs_})

            FOREACH(__file_ ${__srcs_})
                FILE(RELATIVE_PATH __r_file_ ${CMAKE_CURRENT_SOURCE_DIR} ${__file_})
                SRCS(${__global_} ${__r_file_})
            ENDFOREACH ()
        ENDIF ()
    ENDFOREACH ()
ENDMACRO ()
