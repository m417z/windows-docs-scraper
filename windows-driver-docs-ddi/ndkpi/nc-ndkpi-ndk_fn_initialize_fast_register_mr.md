# NDK_FN_INITIALIZE_FAST_REGISTER_MR callback function

## Description

The *NdkInitializeFastRegisterMr* (*NDK_FN_INITIALIZE_FAST_REGISTER_MR*) function initializes an NDK memory region (MR) for fast registration.

## Parameters

### `pNdkMr` [in]

A pointer to an NDK memory region (MR) object
([NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)).

### `AdapterPageCount` [in]

The maximum number of adapter pages to support in this MR such that fast-register work requests with equal or a lower number of adapter pages can be supported.

### `RemoteAccess` [in]

A BOOLEAN value that indicates if the MR must be initialized for remote access or not. An NDK consumer must set *RemoteAccess* to TRUE if the consumer will request remote access with the *NdkFastRegister* ([NDK_FN_FAST_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_fast_register)) function.

### `RequestCompletion` [in]

A pointer to a request completion callback routine *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

## Return value

The
*NdkInitializeFastRegisterMr* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Initialization was completed successfully. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_IMPLEMENTATION_LIMIT** | The request failed because the adapter does not support the requested *AdapterPageCount*. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkInitializeFastRegisterMr* initializes an MR for fast registration. The [NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr) object must be created with *FastRegister* parameter of the *NdkCreateMr* ([NDK_FN_CREATE_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mr)) function set to TRUE.

You can make multiple calls to *NdkInitializeFastRegisterMr*, either in parallel or one after another.

After *NdkInitializeFastRegisterMr* returns, a fast register work request can be posted to a queue pair (QP).

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_CREATE_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mr)

[NDK_FN_FAST_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_fast_register)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)