# _VPCI_INVALIDATE_BLOCK_OUTPUT structure

## Description

The **VPCI_INVALIDATE_BLOCK_OUTPUT** structure is used in an [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) IOCTL request.

The driver for a PCI Express (PCIe) virtual function (VF) issues the **IOCTL_VPCI_INVALIDATE_BLOCK** IOCTL request in order be notified of changes to data in one or more VF configuration blocks. When the IOCTL request is completed, the **VPCI_INVALIDATE_BLOCK_OUTPUT** structure specifies which VF configuration blocks have been changed.

**Note** The [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) IOCTL request is issued by the driver of a PCIe VF on a device that supports the single root I/O virtualization (SR-IOV) interface.

## Members

### `BlockMask`

A **UINT64** value that specifies a bitmask for the first 64 VF configuration blocks. Each bit in the bitmask corresponds to a VF configuration block. If a bit is set to one, the data associated with the corresponding VF configuration block has changed.

## Remarks

A VF configuration block is used for backchannel communication between the drivers of the PCIe PF and a VF on a device that supports the SR-IOV interface. Data from a VF configuration block can be exchanged between the following drivers:

* The VF driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
* The PF driver, which runs in the management operating system.

  This operating system runs within the Hyper-V parent partition.

**Note** The usage of the VF configuration block and the format of its configuration data are defined by the independent hardware vendor (IHV) of the device. The configuration data is used only by the drivers of the PF and VF.

However, we recommend that IHVs reserve the first 64 VF configuration blocks for data that may change occasionally.

## See also

[IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block)