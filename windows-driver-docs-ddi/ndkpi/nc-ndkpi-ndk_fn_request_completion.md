# NDK_FN_REQUEST_COMPLETION callback function

## Description

The *NdkRequestCompletion* (*NDK_FN_REQUEST_COMPLETION*) function completes a pending NDK request.

## Parameters

### `Context` [in, optional]

The context value passed to the NDK provider when a consumer calls an asynchronous request function. The asynchronous request function provides the context with the with the *NdkRequestCompletion* (*NDK_FN_REQUEST_COMPLETION*) function pointer.

### `Status` [in]

The asynchronous completion status for the request. See the asynchronous request functions (for example, [NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept)) for completion status codes that can be returned for each type of request.

## Remarks

Many NDK requests can be completed asynchronously. Asynchronous request functions require the consumer to pass an *NDK_FN_REQUEST_COMPLETION* function pointer as an input. If an asynchronous request function returns STATUS_PENDING, the provider must call the *NdkRequestCompletion* (*NDK_FN_REQUEST_COMPLETION*) function to indicate completion of the request. If an asynchronous request functions returns anything other than STATUS_PENDING, the request was handled immediately and the provider must not call *NdkRequestCompletion*.

## See also

[NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept)