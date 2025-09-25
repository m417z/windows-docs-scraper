# NdisMInvalidateConfigBlock function

## Description

A miniport driver calls the **NdisMInvalidateConfigBlock** function to notify NDIS that the data for one or more Virtual Function (VF) configuration blocks has been changed.

**Note** **NdisMInvalidateConfigBlock** must only be called by the miniport driver for the network adapter's PCIe Physical Function (PF).

## Parameters

### `NdisMiniportHandle` [in]

The network adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `VFId` [in]

The identifier of the VF for which the device location is returned.

### `BlockMask` [in]

A ULONGLONG value that specifies a bitmask for the first 64 VF configuration blocks. Each bit in the bitmask corresponds to a VF configuration block. If the bit is set to one, the data associated with the corresponding VF configuration block has changed.

## Remarks

A VF configuration block is used for backchannel communication between the PF and VF miniport drivers. The IHV can define one or more VF configuration blocks for the device. Each VF configuration block has an IHV-defined format, length, and block ID.

**Note** Data from each VF configuration block is used only by the PF and VF miniport drivers.

VF configuration data is exchanged between the following drivers:

* The VF driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
* The PF driver, which runs in the management operating system.

  This operating system runs within the Hyper-V parent partition.

In order to handle notifications of invalid VF configuration data, NDIS and the miniport drivers perform the following steps:

1. In the guest operating system, NDIS issues an I/O control request of [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request. When this IOCTL is completed, NDIS is notified that VF configuration data has changed.
2. In the management operating system, the following steps occur:
   1. The PF miniport driver calls the **NdisMInvalidateConfigBlock** function to notify NDIS that VF configuration data has changed and is no longer valid.
   2. NDIS signals the virtualization stack, which runs in the management operating system, about the change to VF configuration block data. The virtualization stack caches the *BlockMask* parameter data.

      **Note** Each time that the PF miniport driver calls **NdisMInvalidateConfigBlock**, the virtualization stack ORs the *BlockMask* parameter data with the current value in its cache.
   3. The virtualization stack notifies the virtual PCI (VPCI) driver, which runs in the guest operating system, about the invalidation of VF configuration data. The virtualization stack sends the cached *BlockMask* parameter data to the VPCI driver.
3. In the guest operating system, the following steps occur:
   1. The VPCI driver saves the cached *BlockMask* parameter data in the **BlockMask** member of the [VPCI_INVALIDATE_BLOCK_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_invalidate_block_output) structure that is associated with the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request.
   2. The VPCI driver successfully completes the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request. When this happens, NDIS issues an OID method request of [OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-invalidate-config-block) to the VF miniport driver. An [NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_vf_invalidate_config_block_info) request is passed along in the OID request. This structure contains the cached *BlockMask* parameter data.

      NDIS also issues another [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request to handle successive notifications of changes to VF configuration data.
   3. When the VF driver handles the [OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-invalidate-config-block) request, it reads data from the specified VF configuration blocks.

For more information about backchannel communication within the single root I/O virtualization (SR-IOV) interface, see [SR-IOV PF/VF Backchannel Communication](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-pf-vf-backchannel-communication).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

## See also

[IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block)

[NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_vf_invalidate_config_block_info)

[OID_SRIOV_READ_VF_CONFIG_SPACE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-read-vf-config-space)

[VPCI_INVALIDATE_BLOCK_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_invalidate_block_output)