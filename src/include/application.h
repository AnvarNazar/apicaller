//
// Created by anvar on 12/9/25.
//

#ifndef APITESTER_APPLICATION_H
#define APITESTER_APPLICATION_H

#include <gtk/gtk.h>

#include "project.h"

typedef struct {
    GtkApplication *gtk_app;
    GtkWindow *window;
    Project *projects;
    uint64_t projects_size;
    char *application_name;
} Application;

Application* application_init();

void application_add_project(Application *app, Project *project);

void application_run(Application *app, int argc, char **argv);

void application_delete(Application *app);

#endif //APITESTER_APPLICATION_H
