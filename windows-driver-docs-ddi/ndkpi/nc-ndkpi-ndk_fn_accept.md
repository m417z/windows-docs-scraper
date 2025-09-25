# NDK_FN_ACCEPT callback function

## Description

The *NdkAccept* (*NDK_FN_ACCEPT*) function accepts an incoming connection request over a listener object.

## Parameters

### `pNdkConnector` [in]

A pointer to an NDK connector object ([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)).

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)) to associate with the connection.

### `InboundReadLimit` [in]

The consumer-supplied maximum number of incoming in-progress read operations to allow on the QP. If the underlying provider has a lower **MaxInboundReadLimit** value in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, then the provider will cap the consumer-supplied value to the provider maximum. If the peer has a lower *OutboundReadLimit* value, then the provider will use that value as the effective *InboundReadLimit*. The consumer can retrieve the effective *InboundReadLimit* by calling the *NdkGetConnectionData* function ([NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)).

### `OutboundReadLimit` [in]

The consumer-supplied maximum number of outgoing in-progress read operations to allow on the QP. If the underlying provider has a lower **MaxOutboundReadLimit** value in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, then the provider will cap the consumer supplied value to the provider maximum. If the peer has a lower *InboundReadLimit*, then the provider will use that value as the effective *OutboundReadLimit*. The consumer can retrieve the effective *OutboundReadLimit* by calling the *NdkGetConnectionData* function ([NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)).

### `pPrivateData` [_In_reads_bytes_opt_(PrivateDataLength)]

A pointer to private data that is sent back with the accept request.

### `PrivateDataLength` [in]

The length, in bytes, of the private data that is provided in the *pPrivateData* parameter.

### `DisconnectEvent` [in, optional]

An entry point for an optional disconnect notification callback function *NdkDisconnectEventCallback* ([NDK_FN_DISCONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_disconnect_event_callback)). The provider calls this callback function when the peer disconnects.

### `DisconnectEventContext` [in, optional]

A context value to pass to the *DisconnectEventContext* parameter of the callback function that is specified in the *DisconnectEvent* parameter.

### `RequestCompletion` [in]

A pointer to a request completion callback routine *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

## Return value

The
*NDK_FN_ACCEPT* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_CONNECTION_ABORTED** | The connecting peer abandoned the pending connection establishment. |
| **STATUS_IO_TIMEOUT** | The peer did not call the CompleteConnect ([NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect)) function to complete the pending connection request. |
| **Other status codes** | An error occurred. |

## Remarks

The NDK consumer calls *NdkAccept* to accept an incoming connection request over a listener object.

The *NdkCreateListener* ([NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)) function creates an NDK listener object and provides an *NdkConnectEventCallback* function ([NDK_FN_CONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_event_callback)).

The *NdkConnectEventCallback* function is used by the NDK provider to notify the consumer about each incoming connection request.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect)

[NDK_FN_CONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_event_callback)

[NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)

[NDK_FN_DISCONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_disconnect_event_callback)

[NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)

[NDK_FN_REJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_reject)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)