#include <stdio.h>
#include "./include/types.h"
#include "./include/application.h"

int main(int argc, char* argv[]) {
    Application *app = application_init();
    application_run(app, argc, argv);
    application_delete(app);
    return 0;
}