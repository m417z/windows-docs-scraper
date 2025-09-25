# _VPCI_READ_BLOCK_INPUT structure

## Description

The **VPCI_READ_BLOCK_INPUT** structure is used in an [IOCTL_VPCI_READ_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_read_block) IOCTL request to read data from a specified configuration block of data for a PCI Express (PCIe) virtual function (VF).

This IOCTL request is issued by the driver of a PCIe VF on a device that supports the single root I/O virtualization (SR-IOV) interface.

## Members

### `BlockId`

A **ULONG** value that specifies the VF configuration block to be read. This value is defined by the driver for the PCIe physical function (PF) of the device.

### `BytesRequested`

The size, in bytes, of the buffer that receives the block.

## Remarks

A VF configuration block is used for backchannel communication between the drivers of the PCIe PF and a VF on a device that supports the SR-IOV interface. Data from a VF configuration block can be exchanged between the following drivers:

* The VF driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
* The PF driver, which runs in the management operating system.

  This operating system runs within the Hyper-V parent partition.

**Note** The usage of the VF configuration block and the format of its configuration data are defined by the independent hardware vendor (IHV) of the device. The configuration data is used only by the drivers of the PF and VF.

## See also

[IOCTL_VPCI_READ_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_read_block)