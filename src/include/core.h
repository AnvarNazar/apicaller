//
// Created by anvar on 12/9/25.
//

#ifndef APITESTER_CORE_H
#define APITESTER_CORE_H

#include "types.h"

void request_init(Request *request);
void request_destroy(Request *request);

void response_init(Response *response);
void response_destroy(Response *response);

#endif //APITESTER_CORE_H