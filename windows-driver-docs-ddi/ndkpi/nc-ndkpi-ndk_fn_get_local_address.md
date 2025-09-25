# NDK_FN_GET_LOCAL_ADDRESS callback function

## Description

The *NdkGetLocalAddress* (*NDK_FN_GET_LOCAL_ADDRESS*) function returns the local address for an NDK connection.

## Parameters

### `pNdkConnector` [in]

A pointer to an NDK connector object ([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)).

### `pAddress`

A local address for a listener is returned in this buffer.

### `pAddressLength`

The size, in bytes, of the address buffer for input, and the size, in bytes, of the address written into the buffer for output.

## Return value

The
*NdkGetLocalAddress* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The local address was written to the buffer in the *pAddress* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer size specified in the **pAddressLength* parameter input is too small. **pAddressLength* output value is updated with the required buffer size. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkGetLocalAddress* returns the local address for a connection.

## See also

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)