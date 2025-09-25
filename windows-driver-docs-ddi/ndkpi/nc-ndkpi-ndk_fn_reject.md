# NDK_FN_REJECT callback function

## Description

The *NdkReject* (*NDK_FN_REJECT*) function rejects an incoming NDK connection request.

## Parameters

### `pNdkConnector` [in]

A pointer to an NDK connector object
([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)).

### `PrivateDataLength` [in]

The length, in bytes, of the private data that is provided in the *pPrivateData* parameter.

### `pPrivateData`

A pointer to private data that is sent back with the reject request.

## Return value

The
*NdkReject* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The reject request was successful. |
| **STATUS_CONNECTION_ABORTED** | The connecting peer abandoned the connection establishment. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkReject* rejects an incoming connection request over a listener. A connection request can also be rejected for a connection request where the *NdkConnect* ([NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect)) function has been completed and the consumer rejects the connection. For example, the consumer rejects the connection because of the values in the *pInboundReadLimit*, *pOutboundReadLimit*, or *pPrivateData* parameters available with the *NdkGetConnectionData* ([NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)) function.

## See also

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept)

[NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect)

[NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)