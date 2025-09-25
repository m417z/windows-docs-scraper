# _NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES structure

## Description

The **NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES** structure specifies the NDK-capabilities of a miniport adapter. This structure is used in the **NDKAttributes** member of the [NDIS_MINIPORT_ADAPTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_attributes) union.

## Members

### `Header`

A [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this **NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES** structure.

Set the members of the **NDIS_OBJECT_HEADER** structure as follows:

* Set the **Type** member to **NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_NDK_ATTRIBUTES**.
* Set the **Revision** member to **NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES_REVISION_1**.
* Set the **Size** member to **NDIS_SIZEOF_MINIPORT_ADAPTER_NDK_ATTRIBUTES_REVISION_1**.

### `Enabled`

If the miniport adapter's NDK functionality is enabled, this member is **TRUE**. Otherwise, it is **FALSE**.

### `NdkCapabilities`

A pointer to an [NDIS_NDK_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_capabilities) structure that specifies the capabilities of an NDK adapter.

## Remarks

An NDK-capable adapter must indicate its NDK capabilities in its [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function, even if its NDK functionality is currently disabled.

To report its NDK capabilities, the miniport adapter stores an **NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES** structure in the **NDKAttributes** member of the [NDIS_MINIPORT_ADAPTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_attributes) union and passes the **NDIS_MINIPORT_ADAPTER_ATTRIBUTES** union to the [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function. For more information, see [Initializing an NDK Miniport Adapter](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-an-ndk-miniport-adapter).

## See also

[Initializing an NDK Miniport Adapter](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-an-ndk-miniport-adapter)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_ADAPTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_attributes)

[NDIS_NDK_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_capabilities)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)