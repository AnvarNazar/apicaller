//
// Created by anvar on 12/9/25.
//

#ifndef APITESTER_PROJECT_H
#define APITESTER_PROJECT_H

#include "types.h"

typedef struct {
    const Request *request;
    const Response *response;
    uint64_t requests_size;
} Project;


void project_init(Project *project);

void project_add_request(Project *project, const Request *request);

void project_add_response(Project *project, const Response *response);

void project_resolve_request(Project *project, uint64_t idx);

void project_destroy(Project *project);

#endif //APITESTER_PROJECT_H