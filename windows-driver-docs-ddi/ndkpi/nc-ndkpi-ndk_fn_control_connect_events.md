# NDK_FN_CONTROL_CONNECT_EVENTS callback function

## Description

The *NdkControlConnectEvents* (*NDK_FN_CONTROL_CONNECT_EVENTS*) function pauses and restarts NDK connect event callback functions.

## Parameters

### `pNdkListener` [in]

A pointer to an NDK listener object ([NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)).

### `Pause` [in]

A BOOLEAN value that specifies if a connection is paused or restarted. If *Pause* is TRUE the connection is paused. If *Pause* is FALSE the connection is restarted.

## Remarks

This function is closely related to the *NdkConnectEventCallback* ([NDK_FN_CONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_event_callback)) function. The *NDK_FN_CONNECT_EVENT_CALLBACK* function is called by an NDK provider to notify a consumer about an incoming connection request.
To pause the reception of connect event callbacks, an NDK consumer can pass TRUE in the *Pause* parameter. When a connection is paused, the incoming connection requests must be treated as if there is no NDK listener ([NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)) on the targeted address.

To restart the reception of connect event callbacks, the consumer passes FALSE in the *Pause* parameter.

## See also

[NDK_FN_CONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_event_callback)

[NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)