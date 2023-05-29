#ifndef __MACROS_H_INCLUDED__
#define __MACROS_H_INCLUDED__

#define NOP void(0)

#define GUARD(expr)                                                                               \
    do {                                                                                          \
        expr;                                                                                     \
    } while (0)

#define COMMA() ,
#define EMPTY()
#define DEFER(id) id EMPTY()
#define REPEAT(...) __VA_ARGS__

#define STR(x) #x

// concatenation
#define CAT_(x, y) x##y
#define CAT(x, y) CAT_(x, y)

#define CHAIN_COMMA(LIST) CAT(CHAIN_COMMA_0 LIST, _END)
#define CHAIN_COMMA_0(...) DEFER(REPEAT)(__VA_ARGS__) CHAIN_COMMA_1
#define CHAIN_COMMA_1(...) DEFER(COMMA)() DEFER(REPEAT)(__VA_ARGS__) CHAIN_COMMA_2
#define CHAIN_COMMA_2(...) DEFER(COMMA)() DEFER(REPEAT)(__VA_ARGS__) CHAIN_COMMA_1
#define CHAIN_COMMA_0_END
#define CHAIN_COMMA_1_END
#define CHAIN_COMMA_2_END

// relies on definition of macro function SEPARATOR()
#define CHAIN_SEPARATOR(LIST) CAT(CHAIN_SEPARATOR_0 LIST, _END)
#define CHAIN_SEPARATOR_0(...) DEFER(REPEAT)(__VA_ARGS__) CHAIN_SEPARATOR_1
#define CHAIN_SEPARATOR_1(...) DEFER(SEPARATOR)() DEFER(REPEAT)(__VA_ARGS__) CHAIN_SEPARATOR_2
#define CHAIN_SEPARATOR_2(...) DEFER(SEPARATOR)() DEFER(REPEAT)(__VA_ARGS__) CHAIN_SEPARATOR_1
#define CHAIN_SEPARATOR_0_END
#define CHAIN_SEPARATOR_1_END
#define CHAIN_SEPARATOR_2_END

// relies on definition of macro functions PREFIX(ELEM, ...) AND SUFFIX(ELEM, ...)
#define CHAIN_PREFIX_SUFFIX(LIST) CAT(CHAIN_PREFIX_SUFFIX_1 LIST, _END)
#define CHAIN_PREFIX_SUFFIX_1(...) DEFER(SUFFIX)(DEFER(PREFIX)(__VA_ARGS__)) CHAIN_PREFIX_SUFFIX_2
#define CHAIN_PREFIX_SUFFIX_2(...) DEFER(SUFFIX)(DEFER(PREFIX)(__VA_ARGS__)) CHAIN_PREFIX_SUFFIX_1
#define CHAIN_PREFIX_SUFFIX_1_END
#define CHAIN_PREFIX_SUFFIX_2_END

// relies on definition of macro function OPERATOR(ELEM, ...)
#define CHAIN_OPERATOR(LIST) CAT(CHAIN_OPERATOR_1 LIST, _END)
#define CHAIN_OPERATOR_1(...) DEFER(OPERATOR)(__VA_ARGS__) CHAIN_OPERATOR_2
#define CHAIN_OPERATOR_2(...) DEFER(OPERATOR)(__VA_ARGS__) CHAIN_OPERATOR_1
#define CHAIN_OPERATOR_1_END
#define CHAIN_OPERATOR_2_END

#ifndef NDEBUG
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(...) assert(__VA_ARGS__)
#define UNREACHABLE(msg) assert(msg && false)

#define LOG_ERROR(fmt, ...)                                                                       \
    fprintf(stderr, "ERROR:%s:%d/[%s] " fmt "\n", __FILE__, __LINE__,                             \
            __func__ __VA_OPT__(, ) __VA_ARGS__)
#define LOG(fmt, ...)                                                                             \
    fprintf(stderr, "LOG:%s:%d/[%s] " fmt "\n", __FILE__, __LINE__,                               \
            __func__ __VA_OPT__(, ) __VA_ARGS__)

#else
#define ASSERT(...) NOP;
#define UNREACHABLE(msg) exit(EXIT_FAILURE);

#define LOG_ERROR(msg) NOP;
#define LOG(msg) NOP;
#endif

#endif
