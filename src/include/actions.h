//
// Created by anvar on 20/9/25.
//

#ifndef APICALLER_ACTIONS_H
#define APICALLER_ACTIONS_H

#include <gtk/gtk.h>


void projects_new_request(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void projects_open_project(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void projects_save_project(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void projects_save_as_project(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void projects_close(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void window_fullscreen(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void window_settings(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void window_environment(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void plugins_plugins(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void plugins_install(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void help_help(GSimpleAction *action, GVariant *parameter, gpointer userdata);

void help_about(GSimpleAction *action, GVariant *parameter, gpointer userdata);

#endif //APICALLER_ACTIONS_H
