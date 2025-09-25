# _NDK_LISTENER structure

## Description

The **NDK_LISTENER** structure specifies the attributes of an NDK listener object.

## Members

### `Header`

The [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) structure for the **NDK_LISTENER** structure. Set the **ObjectType** member of the structure that **Header** specifies to **NdkObjectTypeListener**.

### `Dispatch`

A pointer to an [NDK_LISTENER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener_dispatch) structure that defines dispatch functions for the NDK listener object.

## Remarks

An NDK provider must set the **Dispatch** member to point to its [NDK_LISTENER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener_dispatch) table before returning the created listener object. Also, the NDK provider must not use the **Dispatch** member after setting it because the NDK consumer can change the **Dispatch** member to some other value.

## See also

[NDKPI Listeners, Connectors, and Endpoints](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-listeners--connectors--and-endpoints)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)

[NDK_LISTENER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener_dispatch)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)