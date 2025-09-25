# _NDIS_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS structure

## Description

The **NDIS_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS** structure specifies the parameters for a write operation on the configuration block of a network adapter's PCI Express (PCIe) Virtual Function (VF). These parameters are used for the backchannel communication between the VF and the PCIe Physical Function (PF) miniport drivers.

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS_REVISION_1.

### `VFId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the unique identifier of the VF on the network adapter.

**Note** The VF with the specified NDIS_SRIOV_FUNCTION_ID value must have resources that were previously allocated through an object identifier (OID) method request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

### `BlockId`

A ULONG value that specifies the identifier of the VF configuration block to be written to. This identifier is proprietary to the independent hardware vendor (IHV) and is used only by the miniport drivers for the PF and VF on the network adapter.

For more information, see the Remarks section.

### `Length`

A ULONG value that specifies the length, in units of bytes, of the write operation.

### `BufferOffset`

A ULONG value that specifies the offset, in units of bytes, from the beginning of this structure to a buffer that contains the data to be written to the specified VF configuration block.

## Remarks

 The **NDIS_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS** structure is used in an OID set request of [OID_SRIOV_WRITE_VF_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-write-vf-config-block).

A VF configuration block is used for backchannel communication between the drivers of the PCIe PF and a VF on a device that supports the SR-IOV interface. Data from a VF configuration block can be exchanged between the following drivers:

* The VF miniport driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
* The PF miniport driver, which runs in the management operating system.

  This operating system runs within the Hyper-V parent partition.

**Note** The usage of the VF configuration block and the format of its configuration data are defined by the independent hardware vendor (IHV) of the device. The configuration data is used only by the PF and VF miniport drivers.

For more information about backchannel communication within the single root I/O virtualization (SR-IOV) interface, see [SR-IOV PF/VF Backchannel Communication](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-pf-vf-backchannel-communication).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SRIOV_WRITE_VF_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-write-vf-config-block)