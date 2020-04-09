#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <inttypes.h>
#include <glib.h>
#include <gdbus.h>

#include "call_fun_ipc.h"
#include "fun_map.h"
#include "config.h"

static void main_exit(void)
{
    printf("server %s\n", __func__);
    call_fun_ipc_server_deinit();
}

void signal_crash_handler(int sig)
{
    call_fun_ipc_server_deinit();
    exit(-1);
}

void signal_exit_handler(int sig)
{
    call_fun_ipc_server_deinit();
    exit(0);
}



int main(int argc , char ** argv)
{
    GMainLoop *main_loop;
    atexit(main_exit);
    signal(SIGTERM, signal_exit_handler);
    signal(SIGINT, signal_exit_handler);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGBUS, signal_crash_handler);
    signal(SIGSEGV, signal_crash_handler);
    signal(SIGFPE, signal_crash_handler);
    signal(SIGABRT, signal_crash_handler);

    call_fun_ipc_server_init(map, sizeof(map) / sizeof(struct FunMap), DBUS_NAME, DBUS_IF, DBUS_PATH, 0);

    main_loop = g_main_loop_new(NULL, FALSE);
    printf("call_fun_ipc_demo_server init\n");

    g_main_loop_run(main_loop);
    if (main_loop)
        g_main_loop_unref(main_loop);

    return 0;
}