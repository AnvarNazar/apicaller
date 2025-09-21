//
// Created by anvar on 15/9/25.
//
#include "include/application.h"
#include "include/actions.h"

void activate(GtkApplication *gtk_app, gpointer userdata) {
    Application *app = userdata;
    app->window = (GtkWindow *) gtk_application_window_new(app->gtk_app);
    gtk_window_set_default_size(app->window, app->width, app->height);
    gtk_window_set_title(app->window, app->application_name);

    setup_actions(app);
    create_menu(app);
    app->menu_bar = gtk_popover_menu_bar_new_from_model(G_MENU_MODEL(app->menu));

    app->main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_append(GTK_BOX(app->main_box), app->menu_bar);

    gtk_window_set_child(GTK_WINDOW(app->window), app->main_box);
    gtk_window_present(GTK_WINDOW(app->window));
}

void setup_actions(Application *app) {
    GSimpleAction *projects_new_request_action = g_simple_action_new("new_request", NULL);
    GSimpleAction *projects_open_project_action = g_simple_action_new("open_project", NULL);
    GSimpleAction *projects_save_project_action = g_simple_action_new("save_project", NULL);
    GSimpleAction *projects_save_as_project_action = g_simple_action_new("save_as_project", NULL);
    GSimpleAction *projects_close_action = g_simple_action_new("close", NULL);
    GSimpleAction *window_fullscreen_action = g_simple_action_new("fullscreen", NULL);
    GSimpleAction *window_settings_action = g_simple_action_new("settings", NULL);
    GSimpleAction *window_environment_action = g_simple_action_new("environments", NULL);
    GSimpleAction *plugins_plugins_action = g_simple_action_new("plugins", NULL);
    GSimpleAction *plugins_install_action = g_simple_action_new("plugins.install", NULL);
    GSimpleAction *help_help_action = g_simple_action_new("help", NULL);
    GSimpleAction *help_about_action = g_simple_action_new("help.about", NULL);

    g_signal_connect(projects_new_request_action, "activate", G_CALLBACK(projects_new_request), NULL);
    g_signal_connect(projects_open_project_action, "activate", G_CALLBACK(projects_open_project), NULL);
    g_signal_connect(projects_save_project_action, "activate", G_CALLBACK(projects_save_project), NULL);
    g_signal_connect(projects_save_as_project_action, "activate", G_CALLBACK(projects_save_as_project), NULL);
    g_signal_connect(projects_close_action, "activate", G_CALLBACK(projects_close), NULL);
    g_signal_connect(window_fullscreen_action, "activate", G_CALLBACK(window_fullscreen), NULL);
    g_signal_connect(window_settings_action, "activate", G_CALLBACK(window_settings), NULL);
    g_signal_connect(window_environment_action, "activate", G_CALLBACK(window_environment), NULL);
    g_signal_connect(plugins_plugins_action, "activate", G_CALLBACK(plugins_plugins), NULL);
    g_signal_connect(plugins_install_action, "activate", G_CALLBACK(plugins_install), NULL);
    g_signal_connect(help_help_action, "activate", G_CALLBACK(help_help), NULL);
    g_signal_connect(help_about_action, "activate", G_CALLBACK(help_about), NULL);

    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(projects_new_request_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(projects_open_project_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(projects_save_project_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(projects_save_as_project_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(projects_close_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(window_fullscreen_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(window_settings_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(window_environment_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(plugins_plugins_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(plugins_install_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(help_help_action));
    g_action_map_add_action(G_ACTION_MAP(app->gtk_app), G_ACTION(help_about_action));
}

void create_menu(Application *app) {
    app->menu = g_menu_new();

    GMenu *projects_menu = g_menu_new();
    g_menu_append(projects_menu, "New Request", "app.new_request");
    g_menu_append(projects_menu, "Open Project", "app.open_project");
    g_menu_append(projects_menu, "Save Project", "app.save_project");
    g_menu_append(projects_menu, "Save As Project", "app.save_as_project");
    g_menu_append(projects_menu, "Close", "app.close");
    g_menu_append_submenu(app->menu, "Projects", G_MENU_MODEL(projects_menu));

    GMenu *windows_menu = g_menu_new();
    g_menu_append(windows_menu, "Fullscreen", "app.fullscreen");
    g_menu_append(windows_menu, "Settings", "app.settings");
    g_menu_append(windows_menu, "Environments", "app.environments");
    g_menu_append_submenu(app->menu,  "Windows", G_MENU_MODEL(windows_menu));

    GMenu *plugins_menu = g_menu_new();
    g_menu_append(plugins_menu, "Plugins", "app.plugins");
    g_menu_append(plugins_menu, "Install", "app.plugins.install");
    g_menu_append_submenu(app->menu, "Plugins", G_MENU_MODEL(plugins_menu));

    GMenu *help_menu = g_menu_new();
    g_menu_append(help_menu, "Help", "app.help");
    g_menu_append(help_menu, "About", "app.help.about");
    g_menu_append_submenu(app->menu, "Help", G_MENU_MODEL(help_menu));
}

Application *application_init() {
    Application *app = (Application *) malloc(sizeof(Application));
    app->application_name = "API Caller";
    app->gtk_app = gtk_application_new("com.anvarnazar.test", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app->gtk_app, "activate", G_CALLBACK(activate), app);

    app->projects = NULL;
    app->projects_size = 0;

    app->width = 800;
    app->height = 600;
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
    g_object_unref(app->menu);
    g_object_unref(app->gtk_app);
    free(app);
}
