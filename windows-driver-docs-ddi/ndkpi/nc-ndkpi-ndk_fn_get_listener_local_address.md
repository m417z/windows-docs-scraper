# NDK_FN_GET_LISTENER_LOCAL_ADDRESS callback function

## Description

The *NdkGetListenerLocalAddress* (*NDK_FN_GET_LISTENER_LOCAL_ADDRESS*) function returns the local address for an NDK listener.

## Parameters

### `pNdkListener` [in]

A pointer to an NDK listener object ([NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)).

### `pAddress`

A local address for a listener is returned in this buffer.

### `pAddressLength`

The size, in bytes, of the address buffer for input, and the size, in bytes, of the actual address written into the buffer for output.

## Return value

The
*NdkGetListenerLocalAddress* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A local address was written to the buffer in the *pAddress* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer size specified in the **pAddressLength* parameter input is too small. **pAddressLength* output value is updated with the required buffer size. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkGetListenerLocalAddress* returns the local address for a listener. The local address is useful for retrieving port information for an AF_INET or AF_INET6 listener. For example, if the NDK consumer specifies zero as the ND port number in a listen request and the NDK provider specifies a port, the NDK consumer can use *NdkGetListenerLocalAddress* to determine which port the provider specified.

## See also

[NDK_FN_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_listen)

[NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)