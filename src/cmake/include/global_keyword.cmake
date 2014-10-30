MACRO (GET_GLOBAL_KEYWORD_PROPERTY property_name deps dir)
    IF (EXISTS ${ARCADIA_ROOT}/${dir})
        SET(__abs_dir ${ARCADIA_ROOT}/${dir})
    ELSEIF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
        SET(__abs_dir ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
    ELSEIF (EXISTS ${dir})
        SET(__abs_dir ${dir})
    ELSE ()
        MESSAGE(FATAL_ERROR "Absolute path to ${dir} not found")
    ENDIF ()

    GET_PROPERTY(${deps} DIRECTORY ${__abs_dir} PROPERTY ${property_name})
ENDMACRO ()

MACRO (ADD_GLOBAL_KEYWORD_PROPERTY property_name)
    GET_GLOBAL_KEYWORD_PROPERTY(${property_name} __list_ ${CMAKE_CURRENT_SOURCE_DIR})
    SET_APPEND(__list_ ${ARGN})
    LIST(REMOVE_DUPLICATES __list_)
    PROP_CURDIR_SET(${property_name} ${__list_}) # SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY ${property_name} ${__list_})
ENDMACRO ()

MACRO (ADD_OBJ_FOR_LINK)
    # get pathes to object files
    SET(__list_obj_for_progs_)
    SET(__list_obj_for_so_)
    FOREACH (__item_ ${ARGN})
        IF ("${__item_}" MATCHES "^${CMAKE_CURRENT_BINARY_DIR}")
            STRING(REPLACE "${CMAKE_CURRENT_BINARY_DIR}/" "" __item_ "${__item_}")
        ENDIF ()

        IF (NOT WIN32)
            SET(__obj_for_progs_ "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${REALPRJNAME}.dir/${__item_}.o")
            IF(PIC_FOR_ALL_TARGETS)
                SET(__obj_for_so_ ${__obj_for_progs_})
            ELSE ()
                SET(__obj_for_so_ "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${REALPRJNAME}_pic.dir/${__item_}.o")
            ENDIF ()
        ELSE ()
            GET_FILENAME_COMPONENT(__file_name_ "${__item_}" NAME)
            SPLIT_FILENAME(__item_name_ __item_ext_ "${__file_name_}")
            #Use VisualStudio variable - $(ConfigurationName) in __obj_path_
            SET(__obj_for_progs_ "${CMAKE_CURRENT_BINARY_DIR}/${REALPRJNAME}.dir/$(ConfigurationName)/${__item_name_}.obj")
            SET(__obj_for_so_ ${__obj_for_progs_})
        ENDIF ()
        SET_APPEND(__list_obj_for_progs_ "${__obj_for_progs_}")
        SET_APPEND(__list_obj_for_so_ "${__obj_for_so_}")
    ENDFOREACH ()
    ADD_GLOBAL_KEYWORD_PROPERTY("ExplicitDepsForProgs" ${__list_obj_for_progs_})
    ADD_GLOBAL_KEYWORD_PROPERTY("ExplicitDepsForSo" ${__list_obj_for_so_})
ENDMACRO ()
