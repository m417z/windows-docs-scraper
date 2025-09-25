# NDK_FN_CREATE_COMPLETION callback function

## Description

The *NdkCreateCompletion* (*NDK_FN_CREATE_COMPLETION*) function completes the creation of an NDK object.

## Parameters

### `Context` [in, optional]

The context value passed to the NDK provider when a consumer calls an object creation function. The creation function provides the context with the asynchronous create completion request *NdkCreateCompletion* (*NDK_FN_CREATE_COMPLETION*) function pointer.

### `Status` [in]

The asynchronous completion status for the create request. See the object creation functions (for example, [NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)) for completion status codes that can be returned for each type of object.

### `pNdkObject` [in]

A pointer to an NDK object header ([NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)).

## Remarks

**Note** This function is implemented by the NDK consumer and passed to the NDK provider.

NDK objects are created with asynchronous functions. These asynchronous object creation functions take an *NDK_FN_CREATE_COMPLETION* function pointer as an input parameter.

An NDK provider can return STATUS_PENDING from an asynchronous object creation function. In this case, the NDK provider must call the create completion function to indicate that the object creation is complete.

Any status other status code indicates inline completion. In this case, the provider must not call the create request completion function. If the create request function returns an NT_STATUS status code other than STATUS_PENDING, the created object must be returned in an output parameter with the create request function.

For create requests that return STATUS_PENDING and later complete with STATUS_SUCCESS asynchronously, the created object must be returned by the create completion function with the *pNdkObject* parameter and the provider must not access the object output parameter of the create request function.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_CREATE_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_connector)

[NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)

[NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)

[NDK_FN_CREATE_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mr)

[NDK_FN_CREATE_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mw)

[NDK_FN_CREATE_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_pd)

[NDK_FN_CREATE_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp)

[NDK_FN_CREATE_QP_WITH_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp_with_srq)

[NDK_FN_CREATE_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_shared_endpoint)

[NDK_FN_CREATE_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_srq)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)