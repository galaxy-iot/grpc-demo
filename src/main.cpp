#include <iostream>
#include <protobuf/grpc_server.grpc.pb.h>
#include <protobuf/grpc_server.pb.h>
#include "server/server.h"

#include "iothub.h"
#include "iothub_device_client_ll.h"
#include "iothub_client_options.h"
#include "iothub_message.h"
#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/crt_abstractions.h"
#include "azure_c_shared_utility/shared_util_options.h"
#include "iothubtransportmqtt.h"

int main() {
    IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol;
    IOTHUB_MESSAGE_HANDLE message_handle;
    size_t messages_sent = 0;
    const char* telemetry_msg = "test_message";
    printf("%s\n",telemetry_msg);
    protocol = MQTT_Protocol;

    (void)IoTHub_Init();
    IOTHUB_DEVICE_CLIENT_LL_HANDLE device_ll_handle;

    (void)printf("Creating IoTHub Device handle\r\n");
    // Create the iothub handle here
    device_ll_handle = IoTHubDeviceClient_LL_CreateFromConnectionString("", protocol);
    if (device_ll_handle == NULL)
    {
        (void)printf("Failure creating IotHub device. Hint: Check your connection string.\r\n");
    }

    CustomServer *s = new CustomServer(9999);

    s->start();

    // wait for signals
    while (true) {

    };

    
}