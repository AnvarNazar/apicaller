//
// Created by anvar on 15/9/25.
//
#include "include/application.h"

static void activate(GtkApplication *gtk_app, gpointer userdata) {
    Application *app = userdata;
    app->window = (GtkWindow *) gtk_application_window_new(app->gtk_app);
    gtk_window_set_title(app->window, app->application_name);
    gtk_window_set_default_size(app->window, 800, 600);

    gtk_window_present(GTK_WINDOW(app->window));
}

Application* application_init() {
    Application *app = (Application *) malloc(sizeof(Application));
    app->application_name = "API Caller";
    app->gtk_app = gtk_application_new("com.anvarnazar.test", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app->gtk_app, "activate", G_CALLBACK(activate), app);

    app->projects = NULL;
    app->projects_size = 0;
    return app;
}

void application_add_project(Application *app, Project *project) {
    // TODO: implement
}

void application_run(Application *app, int argc, char **argv) {
    g_application_run(G_APPLICATION(app->gtk_app), argc, argv);
}

void application_delete(Application *app) {
    for (int i = 0; i < app->projects_size; i++) {
        project_destroy(app->projects + (i * app->projects_size));
    }
    g_object_unref(app->gtk_app);
    free(app);
}
