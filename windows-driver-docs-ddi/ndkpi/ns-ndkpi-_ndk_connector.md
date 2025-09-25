# _NDK_CONNECTOR structure

## Description

The **NDK_CONNECTOR** structure specifies the attributes of an NDK connector object.

## Members

### `Header`

The [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) structure for the **NDK_CONNECTOR** structure. Set the **ObjectType** member of the structure that **Header** specifies to **NdkObjectTypeConnector**.

### `Dispatch`

A pointer to an [NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch) structure that defines dispatch functions for the NDK connector object.

## Remarks

An NDK provider must set the **Dispatch** member pointer to its [NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch) table before returning the created connector object. The provider must not use the **Dispatch** member after setting it because the NDK consumer can set the **Dispatch** member to some other value.

## See also

[NDKPI Listeners, Connectors, and Endpoints](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-listeners--connectors--and-endpoints)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_FN_CREATE_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_connector)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)