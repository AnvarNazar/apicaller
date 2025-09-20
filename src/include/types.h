//
// Created by anvar on 12/9/25.
//

#ifndef APITESTER_TYPES_H
#define APITESTER_TYPES_H
#include <stdint.h>

typedef enum {
    GET,
    POST,
    PUT,
    PATCH,
    OPTIONS,
    DELETE,
    HEAD,
    CONNECT,
    TRACE,
} Method;

typedef struct {
    Method method;
    const char *url;
    const char **headers;
    const char *body;
    void *response;
} Request;

typedef struct {
    void *request;
    const char **headers;
    const char *body;
    uint32_t status;
} Response;

#endif //APITESTER_TYPES_H
