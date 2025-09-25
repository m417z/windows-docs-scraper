# _NDK_SHARED_ENDPOINT structure

## Description

The **NDK_SHARED_ENDPOINT** structure specifies the attributes of an NDK shared endpoint object.

## Members

### `Header`

The [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) structure for the **NDK_SHARED_ENDPOINT** structure. Set the **ObjectType** member of the structure that **Header** specifies to **NdkObjectTypeSharedEndpoint**.

### `Dispatch`

A pointer to an [NDK_SHARED_ENDPOINT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint_dispatch) structure that defines dispatch functions for the NDK shared endpoint object.

## Remarks

NDK provider must set the **Dispatch** member to its own [NDK_SHARED_ENDPOINT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint_dispatch) table before returning a newly created Shared Endpoint object and must NOT use the **Dispatch** member any more (because the NDK consumer is free to set the **Dispatch** member to some other value).

## See also

[NDKPI Listeners, Connectors, and Endpoints](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-listeners--connectors--and-endpoints)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_FN_CREATE_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_shared_endpoint)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)

[NDK_SHARED_ENDPOINT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint_dispatch)