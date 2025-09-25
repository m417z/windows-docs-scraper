# NDK_FN_GET_SHARED_ENDPOINT_LOCAL_ADDRESS callback function

## Description

The *NdkGetSharedEndpointLocalAddress* (*NDK_FN_GET_SHARED_ENDPOINT_LOCAL_ADDRESS*) function returns the local address for an NDK shared endpoint.

## Parameters

### `pNdkSharedEndpoint` [in]

A pointer to an NDK shared endpoint object ([NDK_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint)).

### `pAddress`

A local address is returned in this buffer.

### `pAddressLength`

The size, in bytes, of the address buffer for input, and the size, in bytes, of the actual address written into the buffer for output.

## Return value

The
*NdkGetSharedEndpointLocalAddress* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A local address was written to the buffer in the *pAddress* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer size specified in the **pAddressLength* parameter input is too small. **pAddressLength* output value is updated with the required buffer size. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkGetSharedEndpointLocalAddress* returns the local address for a shared endpoint. *NdkGetSharedEndpointLocalAddress* retrieves port information for an AF_INET or AF_INET6 shared endpoint. That is, if the NDK consumer specifies zero as the ND port number in a shared endpoint creation request, the NDK provider picks a port. An NDK consumer can determine the port that the provider picked with *NdkGetSharedEndpointLocalAddress*.

## See also

[NDK_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint)