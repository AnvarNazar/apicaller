//
// Created by anvar on 12/9/25.
//

#ifndef APICALLER_APPLICATION_H
#define APICALLER_APPLICATION_H

#include <gtk/gtk.h>

#include "project.h"

typedef struct {
    GtkApplication *gtk_app;
    GActionMap *action_map;
    Project *projects;
    uint64_t projects_size;
    char *application_name;

    GtkWindow *window;
    GMenu *menu;
    GtkWidget *menu_bar;
    GtkWidget *main_box;

    GtkWidget *vbox;

    uint32_t width;
    uint32_t height;
} Application;

Application* application_init();

void application_add_project(Application *app, Project *project);

void application_run(Application *app, int argc, char **argv);

void application_delete(Application *app);

static void create_menu(Application *app);

#endif //APICALLER_APPLICATION_H
