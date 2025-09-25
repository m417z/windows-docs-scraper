# _NDIS_SRIOV_CAPABILITIES structure

## Description

The **NDIS_SRIOV_CAPABILITIES** structure specifies the single root I/O virtualization (SR-IOV) capabilities of the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_CAPABILITIES** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_CAPABILITIES** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_CAPABILITIES _REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_CAPABILITIES _REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS

### `SriovCapabilities`

A ULONG value that contains a bitwise OR of the following flags:

#### NDIS_SRIOV_CAPS_SRIOV_SUPPORTED

Specifies that the network adapter supports SR-IOV functionality.

**Note** This flag must only be set by the miniport driver for the PCI Express (PCIe) Physical Function (PF) of the network adapter. This driver runs in the management operating system. This operating system runs in the Hyper-V parent partition.

#### NDIS_SRIOV_CAPS_PF_MINIPORT

Specifies that this is a PF miniport driver.

#### NDIS_SRIOV_CAPS_VF_MINIPORT

Specifies that this is a PCIe Virtual Function (VF) miniport driver.

## Remarks

 The miniport driver uses the **NDIS_SRIOV_CAPABILITIES** structure to report its SR-IOV capabilities in the following ways:

* The miniport driver calls the [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function from its [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function and sets the *MiniportAttributes* parameter to a pointer to an [NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes) structure. The driver advertises SR-IOV support by formatting the
  **HardwareSriovCapabilities** and **CurrentSriovCapabilities** members as **NDIS_SRIOV_CAPABILITIES** structures.
* When the driver successfully handles an OID query request of [OID_SRIOV_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-hardware-capabilities) or [OID_SRIOV_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-current-capabilities), it returns an **NDIS_SRIOV_CAPABILITIES** structure.

NDIS passes the network adapter's SR-IOV capabilities to overlying drivers that bind to the network adapter in the following way:

* When NDIS calls an overlying filter driver's [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function, NDIS passes the network adapter's SR-IOV capabilities through the *AttachParameters* parameter. This parameter contains a pointer to an [NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure. The **SriovCapabilities** member of this structure contains a pointer to an **NDIS_SRIOV_CAPABILITIES** structure.
* When NDIS calls an overlying protocol driver's [ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)
  function, NDIS passes the network adapter's SR-IOV capabilities through the *BindParameters* parameter. This parameter contains a pointer to an [NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure. The **SriovCapabilities** member of this structure contains a pointer to an **NDIS_SRIOV_CAPABILITIES** structure.

For more information on how to report the SR-IOV capabilities of a network adapter, see [Determining SR-IOV Capabilities](https://learn.microsoft.com/windows-hardware/drivers/network/determining-sr-iov-capabilities).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[OID_SRIOV_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-current-capabilities)

[OID_SRIOV_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-hardware-capabilities)