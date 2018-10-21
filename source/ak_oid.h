/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2014 - 2018 by Axel Kenzo, axelkenzo@mail.ru                                     */
/*                                                                                                 */
/*  Файл ak_oid.h                                                                                  */
/*  - содержит описания функций, реализующих операции с идентификаторами криптографических         */
/*    алгоритмов и параметров                                                                      */
/* ----------------------------------------------------------------------------------------------- */
#ifndef    __AK_OID_H__
#define    __AK_OID_H__

/* ----------------------------------------------------------------------------------------------- */
 #include <libakrypt.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Класс, контролирующий функционирование криптографических объектов библиотеки. */
/*! К криптографическим объектам в текущей версии библиотеки относятся:
    - класс \ref random (генератор случайных чисел),
    - класс \ref hash (бесключевая функция хеширования),
    - класс \ref skey (секретный ключ),
    - класс \ref hmac (ключевая функция хеширования HMAC),
    - класс \ref bckey (блочный алгоритм хеширования) и т.д.                                       */
/* ----------------------------------------------------------------------------------------------- */
 typedef struct object {
 /*! \brief Конструктор объекта. */
  ak_function_void *create;
 /*! \brief Деструктор объекта. */
  ak_function_void *destroy;
 /*! \brief Освобождение контекста. */
  ak_function_void *delete;
 /*! \brief Функция, выполняющая прямое преобразование. */
  ak_function_void *direct;
 /*! \brief Функция выполняющая обратное преобразование. */
  ak_function_void *reverse;
} *ak_object;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Класс для хранения идентификаторов объектов (криптографических механизмов) и их данных. */
/*! OID (Object IDentifier) это уникальная последовательность чисел, разделенных точками.
    OID'ы могут быть присвоены любому криптографическому механизму (алгоритму,
    схеме, протоколу), а также произвольным параметрам этих механизмов.
    Использование OID'в позволяет однозначно определять тип криптографического механизма или
    значения его параметров на этапе выполнения программы, а также
    однозначно связывать данные (как правило ключевые) с алгоритмами, в которых эти данные
    используются.                                                                                  */
/* ----------------------------------------------------------------------------------------------- */
 typedef struct oid {
  /*! \brief криптографический механизм   */
   ak_oid_engine engine;
  /*! \brief режим использования криптографического алгоритма */
   ak_oid_mode mode;
  /*! \brief читаемое имя (для пользователя) */
   const char *name;
  /*! \brief собственно OID (cтрока чисел, разделенных точками) */
   const char *id;
  /*! \brief соответствующая последовательность октетов в asn1 кодировке. */
   const ak_uint8 *asn1;
  /*! \brief указатель на данные. */
   ak_pointer *data;
  /*! \brief структура, контролирующая поведение объекта. */
   struct object func;
} *ak_oid;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Поиск OID его имени. */
 const ak_oid ak_oid_context_find_by_name( const char *name );
/*! \brief Поиск OID по его идентификатору (строке цифр, разделенных точками). */
 const ak_oid ak_oid_context_find_by_id( const char *id );
/*! \brief Поиск OID по типу криптографического механизма. */
 const ak_oid ak_oid_context_find_by_engine( const ak_oid_engine );
/*! \brief Продолжение поиска OID по типу криптографического механизма. */
 const ak_oid ak_oid_context_findnext_by_engine( const ak_oid, const ak_oid_engine );
/*! \brief Проверка соответствия заданного адреса корректному oid. */
 ak_bool ak_oid_context_check( const ak_oid );

#endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                                       ak_oid.h  */
/* ----------------------------------------------------------------------------------------------- */
