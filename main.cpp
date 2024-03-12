#include <czmq.h>
#include <cjson/cJSON.h>

int main(int argc, char **argv)
{
    zsock_t *responder = zsock_new(ZMQ_REP);
    int r = zsock_bind(responder, "tcp://*:5555");
    if (r != 5555)
    {
        printf("Failed to bind to port\n");
    }

    while (true)
    {
        printf("Waiting for messages...\n");

        char *msg = zstr_recv(responder);

        printf("Recieved message %s\n", msg);

        printf("Replying with Hello\n");

        zstr_send(responder, "Hello");

        free(msg);
    }

    zsock_destroy(&responder);
}