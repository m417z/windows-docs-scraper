# IOCTL_SRIOV_INVALIDATE_BLOCK IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

The **IOCTL_SRIOV_INVALIDATE_BLOCK** request indicates that the virtualization stack wants to reset the contents of the specified configuration block.

## Parameters

### Major code

### Input buffer

A pointer to a [SRIOV_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_invalidate_block) structure that contains the configuration block to invalidate.

### Input buffer length

The size of the [SRIOV_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_invalidate_block) structure.

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE.

The request is sent to the physical function (PF) driver by VSP.
The PF driver completes the request when the driver wants to indicate to the virtual function (VF) driver that
one or more of the configuration blocks need to be read again.