## Description

The *NdkCompleteConnectEx* (*NDK_FN_COMPLETE_CONNECT_EX*) function completes an asynchronous connection request.

## Parameters

### `pNdkConnector` [in]

A pointer to an NDK connector object ([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)).

### `DisconnectEvent` [in, optional]

An entry point for an optional disconnect notification callback function NdkDisconnectEventCallbackEx function [NDK_FN_DISCONNECT_EVENT_CALLBACK_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_disconnect_event_callback_ex). The provider calls this callback function when the peer disconnects.

### `DisconnectEventContext` [in, optional]

A context value to pass back to the *NdkDisconnectEventCallback* function that is specified in the *DisconnectEvent* parameter.

### `RequestCompletion` [in]

A pointer to a request completion callback *NdkRequestCompletion* function ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value that the provider passes back to the *NdkRequestCompletion* function. This value is specified in the *RequestCompletion* parameter.

## Return value

The *NDK_FN_COMPLETE_CONNECT* function returns one of the following NTSTATUS codes.

|Return code|Description|
|--- |--- |
|**STATUS_SUCCESS**|The request was completed successfully.|
|**STATUS_PENDING**|The request is pending. The provider will call the _NdkRequestCompletion_ function that is specified in the _RequestCompletion_ parameter to complete the request asynchronously.|
|**STATUS_CONNECTION_INVALID**|The request failed because the queue pair is not connecting. **Important**: The request can fail inline as well as asynchronously with this status code.|
|**STATUS_CONNECTION_ABORTED**|The accepting peer abandoned the pending connection establishment.|
|**STATUS_IO_TIMEOUT**|The request failed because the connection establishment timed out. This is not an indication of a catastrophic or permanent failure, but it ends connection establishment for this connector. **Important**: The request can fail inline as well as asynchronously with this status code.|
|**Other status codes**|An error occurred.|

## Remarks

The *NdkCompleteConnectEx* function completes a connection request that was initiated by a previous call to the *NdkConnect* ([NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect)) function. The NDK consumer calls *NdkCompleteConnectEx* after the peer accepts the connection request.

## See also

[NDK_FN_ACCEPT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept_ex)

[NDK_FN_DISCONNECT_EVENT_CALLBACK_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_disconnect_event_callback_ex)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)