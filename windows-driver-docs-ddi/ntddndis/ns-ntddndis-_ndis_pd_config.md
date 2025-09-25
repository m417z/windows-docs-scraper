# _NDIS_PD_CONFIG structure

## Description

This structure holds configuration data for the PD provider.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_CONFIG** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_CONFIG_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_CONFIG_REVISION_1**

### `Flags`

This member is reserved and must be set to 0.

### `Enabled`

A **BOOLEAN** value that is set to **TRUE** if the PDPI provider's PacketDirect capability is enabled. Otherwise, this member is **FALSE**.

### `CapabilitiesOffset`

If the **CapabilitiesSize** member is greater than zero, this is a **ULONG**-aligned pointer to an [NDIS_PD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pd_capabilities) structure.

### `CapabilitiesSize`

If this member is greater than zero, it contains the size of the [NDIS_PD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pd_capabilities) structure that the **CapabilitiesOffset** member points to.

## Remarks

This structure must be aligned on an 8-byte boundary.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)