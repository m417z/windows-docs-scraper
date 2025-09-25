# NDK_FN_CLOSE_COMPLETION callback function

## Description

 The *NdkCloseCompletion* (*NDK_FN_CLOSE_COMPLETION*) function is an asynchronous completion function for closing NDK objects.

## Parameters

### `Context` [in, optional]

A context value for each close request that is passed to the provider with the asynchronous close request function (*NDK_FN_CLOSE_COMPLETION*) pointer.

## Remarks

**Note** This function is implemented by the NDK consumer and passed to the NDK provider.

The NDK programming interface includes an *NdkCloseObject* ([NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)) function for NDK objects. For more information about NDK objects, see [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) and [NDK_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ne-ndkpi-_ndk_object_type).

 NDK close requests can return either STATUS_SUCCESS or STATUS_PENDING. That is, a close request can never fail, but can be completed asynchronously at a later time. The provider must call the *NdkCloseCompletion* function if *NdkCloseObject* returns STATUS_PENDING. The provider must not call the *NdkCloseCompletion* function if the *NdkCloseCompletion* function returns any status other than STATUS_PENDING.

A close request will remain pending while there is another pending request or an in-progress notification callback on the object being closed.

The provider will call the *NdkCloseCompletion* function after all pending requests have been completed for the object (that is, the provider called the associated completion function for a request and the completion function returned control back to the provider) and all in-progress notification callbacks have returned control back to the provider.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)

[NDK_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ne-ndkpi-_ndk_object_type)