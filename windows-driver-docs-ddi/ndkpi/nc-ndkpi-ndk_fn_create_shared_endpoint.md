# NDK_FN_CREATE_SHARED_ENDPOINT callback function

## Description

The *NdkCreateSharedEndpoint* (*NDK_FN_CREATE_SHARED_ENDPOINT*) function creates an NDK shared endpoint.

## Parameters

### `pNdkAdapter` [in]

A pointer to an NDK adapter object ([NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)).

### `pAddress`

A local address to use for initiating outgoing connections. For AF_INET or AF_INET6 *pAddress* contains the local IP address and local ND port.

### `AddressLength` [in]

The size, in bytes, of local address data at the *pAddress* parameter.

### `CreateCompletion` [in]

A pointer to an *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that completes the creation of an NDK object.

### `RequestContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCreateCompletion* function that is specified in the *CreateCompletion* parameter.

### `ppNdkSharedEndpoint`

A pointer to a created shared endpoint object ([NDK_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint)) is returned in this location if the request succeeds without returning STATUS_PENDING. If the request returns STATUS_PENDING then this parameter is ignored and the created object is returned with the callback that is specified in the *CreateCompletion* parameter.

## Return value

The
*NdkCreateSharedEndpoint* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The shared endpoint object was created successfully and returned with the **ppNdkSharedEndpoint* parameter. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The provider will call the function specified in the *CreateCompletion* parameter ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) to complete the pending operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_SHARING_VIOLATION** | The request failed because the specified local address is already in use.<br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_TOO_MANY_ADDRESSES** | The request failed because the consumer specified a local port number of zero, and the Network Direct provider was unable to allocate a port from the ephemeral port space (ports 49152-65535.) |
| **STATUS_INVALID_ADDRESS** | The request failed because the specified local address is not a valid address for the adapter. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkCreateSharedEndpoint* function creates an NDK shared endpoint to use as the local address for multiple outgoing connections that are destined to different remote addresses. This is analogous to having multiple incoming connections to the same local address that are represented by a listener object.

 If the function returns STATUS_SUCCESS, the created object is returned in the *ppNdkSharedEndpoint* parameter. If *NdkCreateSharedEndpoint* returns STATUS_PENDING, the created object is returned by the *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that is specified in the *CreateCompletion* parameter.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint)