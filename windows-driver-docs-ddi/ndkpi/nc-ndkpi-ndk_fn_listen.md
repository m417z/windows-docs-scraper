# NDK_FN_LISTEN callback function

## Description

The *NdkListen* (*NDK_FN_LISTEN*) function puts an NDK listener object into listening mode.

## Parameters

### `pNdkListener` [in]

A pointer to an NDK listener object ([NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)).

### `pAddress`

A local address to listen on. For AF_INET or AF_INET6 *pAddress* contains the local IP address and local ND port.

### `AddressLength` [in]

The size, in bytes, of local address data at the *pAddress* parameter.

### `RequestCompletion` [in]

A pointer to a request completion callback routine *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

## Return value

The
*NdkListen* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The listen request succeeded. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_SHARING_VIOLATION** | The request failed because the specified local address is already in use.<br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_INVALID_ADDRESS** | The request failed because the specified local address is not a valid address for the adapter. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_TOO_MANY_ADDRESSES** | The request failed because the consumer specified a local port number of zero, and the Network Direct provider was unable to allocate a port from the ephemeral port space (ports 49152-65535.) |
| **Other status codes** | An error occurred. |

## Remarks

*NdkListen* puts a listener object into listening mode on the specified local address.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)

[NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)