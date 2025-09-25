# NDK_FN_CONNECT callback function

## Description

The *NdkConnect* (*NDK_FN_CONNECT*) function initiates an NDK connect request.

## Parameters

### `pNdkConnector` [in]

A pointer to an NDK connector object ([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)).

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)) to associate with the connection.

### `pSrcAddress`

A source address. For AF_INET or AF_INET6 *pSrcAddress* is the source IP address and the source ND port.

### `SrcAddressLength` [in]

The size, in bytes, of source address data at the *pSrcAddress* parameter.

### `pDestAddress` [in]

A destination address. For AF_INET or AF_INET6 *pDestAddress* is the destination IP address and the source ND port .

### `DestAddressLength` [in]

The size, in bytes, of destination address data at the *pDestAddress* parameter.

### `InboundReadLimit` [in]

The consumer-supplied maximum number of incoming in-progress read operations to allow on the QP. If the underlying provider has a lower **MaxInboundReadLimit** value in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, then the provider will cap the consumer-supplied value to the provider maximum. If the peer has a lower *OutboundReadLimit* value, then the provider will use that value as the effective *InboundReadLimit*. The consumer can retrieve the effective *InboundReadLimit* by calling the *NdkGetConnectionData* function ([NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)).

### `OutboundReadLimit` [in]

The consumer-supplied maximum number of outgoing in-progress read operations to allow on the QP. If the underlying provider has a lower **MaxOutboundReadLimit** value in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, then the provider will cap the consumer supplied value to the provider maximum. If the peer has a lower *InboundReadLimit*, then the provider will use that value as the effective *OutboundReadLimit*. The consumer can retrieve the effective *OutboundReadLimit* by calling the *NdkGetConnectionData* function ([NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)).

### `pPrivateData` [_In_reads_bytes_opt_(PrivateDataLength)]

A pointer to private data that is sent with the connect request.

### `PrivateDataLength` [in]

The length, in bytes, of the private data that is provided in the *pPrivateData* parameter.

### `RequestCompletion` [in]

A pointer to a request completion callback routine *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

### `pSrcAddress`

## Return value

The
*NdkConnect* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The connect request was completed successfully. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_NETWORK_UNREACHABLE** | The request failed because the remote network was not reachable. The connection attempt can be retried. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_HOST_UNREACHABLE** | The request failed because the remote host system was not reachable. The connection attempt can be retried. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_CONNECTION_REFUSED** | The request failed because the remote system refused the connection request. This can be due to lack of listener, backlog limits, or the peer actively rejecting the connection request. The connection attempt can be retried. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_IO_TIMEOUT** | The request failed because the connection request timed out. The connection attempt may be retried. Timeout values are selected by Network Direct providers to match their respective network characteristics. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_SHARING_VIOLATION** | The request failed because the specified local address is already in use. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_INVALID_ADDRESS** | The request failed because the specified local address is not a valid address for the adapter. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_TOO_MANY_ADDRESSES** | The request failed because the consumer specified a local port number of zero, and the Network Direct provider was unable to allocate a port from the ephemeral port space (ports 49152-65535).<br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_ADDRESS_ALREADY_EXISTS** | The request failed because a connection with the combination of local address, local port, remote address, and remote port already exists. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkConnect* initiates a connect request from a local address to a remote address.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_FN_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_disconnect)

[NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)