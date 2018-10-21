/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2017 - 2018 by Axel Kenzo, axelkenzo@mail.ru                                     */
/*                                                                                                 */
/*  Файл ak_context_manager.h                                                                      */
/*  - содержит описание функций для управления контекстами.                                        */
/* ----------------------------------------------------------------------------------------------- */
#ifndef __AK_CONTEXT_MANAGER_H__
#define __AK_CONTEXT_MANAGER_H__

/* ----------------------------------------------------------------------------------------------- */
 #include <ak_buffer.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Класс состояний контекста. */
 typedef enum {
  /*! \brief контект не определен */
   node_undefined,
  /*! \brief контекст совпадает с хранимым вариантом (только создан/считан/записан) */
   node_is_equal,
  /*! \brief контекст изменен в процессе работы */
   node_modified
} ak_context_node_status;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Элемент структуры, предназначенной для управления контекстами. */
 typedef struct context_node {
  /*! \brief указатель на контекст */
   ak_pointer ctx;
  /*! \brief дескриптор контекста */
   ak_handle id;
  /*! \brief oid объекта */
   ak_oid oid;
  /*! \brief пользовательское описание */
   struct buffer description;
  /*! \brief статус контекста */
   ak_context_node_status status;
} *ak_context_node;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Создание нового элемента структуры управления контекстами. */
 ak_context_node ak_context_node_new( ak_pointer , ak_handle , ak_oid_engine , const char * );
/*! \brief Уничтожение элемента структуры управления контекстами. */
 ak_pointer ak_context_node_delete( ak_pointer );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Структура, предназначенная для управления контекстами. */
/*! Менеджер контектов представляет собой массив указателей на произвольные контексты библиотеки,
    для которых
    механизмом OID определны стандартные действия (сохдания, удаления и т.п.).

    При инициализации библиотеки создается один объект данного типа, который используется
    для работы с контекстами пользователей.
    Доступ пользователям библиотеки к менеджеру контекстов закрыт.                                 */
/* ----------------------------------------------------------------------------------------------- */
 struct context_manager {
  /*! \brief массив указателей на структуры управления контекстами */
   ak_context_node *array;
  /*! \brief общее количество выделенной по структуры управления памяти */
   size_t size;
  /*! \brief генератор, используемый для выработки ключей */
   struct random key_generator;
};

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Указатель на структуру управления ключами. */
 typedef struct context_manager *ak_context_manager;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Инициализация структуры управления контекстами. */
 int ak_context_manager_create( ak_context_manager );
/*! \brief Уничтожение структуры управления контекстами. */
 int ak_context_manager_destroy( ak_context_manager );

/*! \brief Увеличение памяти для структуры управления контекстами. */
 int ak_context_manager_morealloc( ak_context_manager );
/*! \brief Добавление контекста в структуру управления контекстами. */
 ak_handle ak_context_manager_add_node( ak_context_manager , ak_pointer , ak_oid_engine ,
                                                        const char * , ak_function_free_object * );
/*! \brief Удаление контекста из структуры управления контекстами. */
 int ak_context_manager_delete_node( ak_context_manager , ak_handle );
/*! \brief Получение точного значения дескриптора по индексу массива. */
 ak_handle ak_context_manager_idx_to_handle( ak_context_manager , size_t );
/*! \brief Получение точного значения индекса массива по значению декскриптора. */
 size_t ak_context_manager_handle_to_idx( ak_context_manager , ak_handle );
/*! \brief Проверка корректности дескриптора контекста. */
 int ak_context_manager_handle_check( ak_context_manager , ak_handle , size_t * );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Инициализация глобальной структуры управления контекстами. */
 int ak_libakrypt_create_context_manager( void );
/*! \brief Удаление глобальной структуры управления контекстами. */
 int ak_libakrypt_destroy_context_manager( void );
/*! \brief Получение указателя на глобальную структуру управления контекстами. */
 ak_context_manager ak_libakrypt_get_context_manager( void );




/*! \brief Помещение созданного объекта в глоюальную структуру управления контекстами. */
 ak_handle ak_libakrypt_new_handle( ak_pointer , ak_oid_engine , const char * ,
                                                                        ak_function_free_object * );
/*! \brief Получение контекста по заданному дескриптору и типу контекста. */
 ak_pointer ak_handle_get_context( ak_handle, ak_oid_engine );

#endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                           ak_context_manager.h  */
/* ----------------------------------------------------------------------------------------------- */
