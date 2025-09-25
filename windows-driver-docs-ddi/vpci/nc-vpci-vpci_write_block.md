## Description

The *WriteVfConfigBlock* routine writes a block of configuration data for a PCI Express virtual function (VF). This routine is called by the driver of a PCIe VF on a device that supports the single root I/O virtualization (SR-IOV) interface.

## Parameters

### `Context`

[in] A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [**VPCI\_INTERFACE\_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-vpci_interface_standard) structure for the interface.

### `BlockId`

[in] The identifier of the VF configuration block to be written. This identifier is proprietary to the independent hardware vendor (IHV) and is used only by the drivers for the PCIe physical function (PF) and VF on the device.

### `Buffer`

[in] A pointer to a caller-allocated buffer that contains the configuration data to be written. For more information, see Remarks.

### `Length`

[in] The number of bytes to be written to the VF configuration block.

> [!NOTE]
> The value of this parameter must not exceed **VPCI\_MAX\_READ\_WRITE\_BLOCK\_SIZE**.

## Return value

The *ReadVfConfigBlock* routine returns **STATUS\_SUCCESS** if the operation succeeds. Otherwise, the routine returns an appropriate NTSTATUS value.

## Remarks

When the *WriteVfConfigBlock* routine is called, the driver of the PF is notified to update a specified VF configuration block with the specified data.

A VF configuration block is used for backchannel communication between the drivers of the PCIe PF and a VF on a device that supports the SR-IOV interface. The IHV can define one or more VF configuration blocks for the device. Each VF configuration block has an IHV-defined format, length, and block ID.

VF configuration data can be exchanged between the following drivers in a protected manner:

- The VF driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
- The PF driver, which runs in the management operating system. This operating system runs within the Hyper-V parent partition.

Data from each VF configuration block is used only by the drivers of the PF and VF.

> [!NOTE]
> The [**IOCTL\_VPCI\_WRITE\_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block) IOCTL offers an asynchronous alternative to the *WriteVfConfigBlock* routine.

## See also

[**IOCTL\_VPCI\_WRITE\_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block)

[**VPCI\_INTERFACE\_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-vpci_interface_standard)