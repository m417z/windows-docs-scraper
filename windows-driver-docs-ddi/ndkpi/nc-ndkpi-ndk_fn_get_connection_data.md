# NDK_FN_GET_CONNECTION_DATA callback function

## Description

The *NdkGetConnectionData* (*NDK_FN_GET_CONNECTION_DATA*) function gets read limit values and the private data sent by the peer.

## Parameters

### `pNdkConnector` [in]

A pointer to an NDK connector object ([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)).

### `pInboundReadLimit` [out, optional]

The maximum number of incoming in-progress read operations to allow on the QP is returned in this location.

### `pOutboundReadLimit` [out, optional]

The maximum number of outgoing in-progress read operations to allow on the QP is returned in this location.

### `pPrivateData`

A pointer to private data that is returned.

### `pPrivateDataLength`

The length, in bytes, of the private data that is provided in the *pPrivateData* parameter.

**Note** The output value does not indicate the actual length of private data stored in the buffer. NDK consumers must negotiate the format and length of the actual private data. For more information about private data, see the Remarks section.

## Return value

The *NdkGetConnectionData* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_BUFFER_TOO_SMALL** | The value in the **pPrivateDataLength* parameter specified a buffer size that was too small to hold the connection private data. **pPrivateDataLength* is updated with the required size. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkGetConnectionData* function gets the private data sent by the peer with connect, accept, or reject requests and the effective inbound and outbound read limit values. These values are derived from the local and remote peers' requested values and the provider's maximum limits.

To access the private data and the effective inbound read limit (IRD) and outbound read limit (ORD) values from the active side, an NDK consumer can call *NdkGetConnectionData* for a connector object that was passed to the [NDK_FN_CONNECT_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_event_callback) function.

To access the private data and effective IRD and ORD values from the passive side, the consumer can call *NdkGetConnectionData* for a connector object for which [NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect) or [NDK_FN_CONNECT_WITH_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_with_shared_endpoint) completed successfully An NDK consumer will not call this function after it calls the [NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept) function on the passive side or the [NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect) function on the active side.

If the *pPrivateData* parameter is NULL and **pPrivateDataLength* is zero, an NDK provider must return STATUS_SUCCESS and store the required private data buffer size (*RDS*) in **pPrivateDataLength*.

**Note** The *required private data buffer size* (*RDS*) does not indicate that the peer has sent that much private data. The NDK consumer must, on both ends, have a common scheme to allow the receiving end to determine if there is any private data or not in the private data buffer. The *RDS* might be different for each connection.

If *pPrivateData* is NULL and **pPrivateDataLength* is greater than zero, this is an invalid request. A consumer must never do this.

If *pPrivateData* is not NULL, the provider must copy the private data to the buffer at *pPrivateData* up to the smaller of **pPrivateDataLength* or *RDS* in bytes.

If **pPrivateDataLength* is greater than or equal to *RDS*, the provider must return STATUS_SUCCESS. Otherwise, the provider must return STATUS_BUFFER_TOO_SMALL. In both cases, the provider must store the *RDS* in **pPrivateDataLength* before returning.

## See also

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)