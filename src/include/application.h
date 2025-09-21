//
// Created by anvar on 12/9/25.
//

#ifndef APICALLER_APPLICATION_H
#define APICALLER_APPLICATION_H

#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>

#include "project.h"

typedef struct {
    GtkApplication *gtk_app;
    GActionMap *action_map;
    Project *projects;
    uint64_t projects_size;
    char *application_name;

    // UI
    uint32_t width;
    uint32_t height;
    GtkWindow *window;
    GMenu *menu;
    GtkWidget *menu_bar;
    GtkWidget *main_box;
    GtkWidget *content_box;
    GtkWidget *project_view;
    GtkWidget *request_hpane;

    GtkWidget *request_frame;
    GtkWidget *request_frame_box;
    GtkWidget *url_text_box;
    GtkWidget *method_dropdown;

    GtkWidget *response_frame;
    GtkSourceBuffer *response_buffer;
    GtkSourceView *response_text_box;

} Application;

Application* application_init();

void application_add_project(Application *app, Project *project);

void application_run(Application *app, int argc, char **argv);

void application_delete(Application *app);

void create_menu(Application *app);

void setup_actions(Application *app);

void setup_ui(Application *app);

void setup_project_view(Application *app);

void setup_request_view(Application *app);

#endif //APICALLER_APPLICATION_H
