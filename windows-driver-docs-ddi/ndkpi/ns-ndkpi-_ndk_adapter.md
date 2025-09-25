# _NDK_ADAPTER structure

## Description

The **NDK_ADAPTER** structure specifies the attributes of an NDK adapter object.

## Members

### `Header`

The [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) structure for the **NDK_ADAPTER** structure. Set the **ObjectType** member of the structure that **Header** specifies to **NdkObjectTypeAdapter**.

### `Dispatch`

A pointer to an [NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch) structure that defines dispatch functions for the NDK adapter object.

## Remarks

The **NDK_ADAPTER** structure defines an adapter object. The [OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler) function opens an NDK adapter instance on an NDK-capable NDIS miniport adapter.

An NDK provider must set the **Dispatch** member to point to its [NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch) table before returning the created adapter object. Also, the NDK provider must not use the **Dispatch** member after setting it because the NDK consumer can change the **Dispatch** member to some other value.

## See also

[CLOSE_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-close_ndk_adapter_handler)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)

[OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler)