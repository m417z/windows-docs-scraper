# _NDIS_SRIOV_PF_LUID_INFO structure

## Description

The **NDIS_SRIOV_PF_LUID_INFO** structure specifies the locally unique identifier (LUID) associated with the network adapter's PCI Express (PCIe) Physical Function (PF).

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_PF_LUID_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_PF_LUID_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_PF_LUID_INFO_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_PF_LUID_INFO_REVISION_1.

### `Luid`

An [LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) value that is associated with the PF network adapter. For more information, see the Remarks section.

## Remarks

NDIS generates an LUID for the PF before NDIS calls the [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)
function of the miniport driver for the PF. This LUID is valid until NDIS calls the PF miniport driver's [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

**Note** The value of the **Luid** member is different from the **NetLuid** member of the [NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure. This structure is passed to the miniport driver through the *MiniportInitParameters* of [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

An overlying driver queries this LUID through OID query requests of [OID_SRIOV_PF_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-pf-luid).

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SRIOV_PF_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-pf-luid)