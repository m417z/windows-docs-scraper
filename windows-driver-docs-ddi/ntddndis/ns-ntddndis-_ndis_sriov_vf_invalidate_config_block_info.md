# _NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO structure

## Description

The **NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO** structure specifies one or more Virtual Function (VF) configuration blocks whose data has been changed (*invalidated*) by the driver for the PCI Express (PCIe) Physical Function (PF) on the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO** structure, the miniport driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SIZEOF_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_VF_CONFIG_STATE_REVISION_1.

### `BlockMask`

A ULONG64 value that specifies a bitmask for the first 64 VF configuration blocks. Each bit in the bitmask corresponds to a VF configuration block. If the bit is set to one, the data associated with the corresponding VF configuration block has changed.

## Remarks

The **NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO** structure is used in OID set requests of [OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-invalidate-config-block).

A VF configuration block is used for backchannel communication between the drivers of the PCIe PF and a VF on a device that supports the SR-IOV interface. Data from a VF configuration block can be exchanged between the following drivers:

* The VF miniport driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
* The PF miniport driver, which runs in the management operating system.

  This operating system runs within the Hyper-V parent partition.

**Note** The usage of the VF configuration block and the format of its configuration data are defined by the independent hardware vendor (IHV) of the device. The configuration data is used only by the PF and VF miniport drivers.

However, we recommend that IHVs reserve the first 64 VF configuration blocks for data that may change occasionally.

For more information about backchannel communication within the single root I/O virtualization (SR-IOV) interface, see [SR-IOV PF/VF Backchannel Communication](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-pf-vf-backchannel-communication).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-invalidate-config-block)