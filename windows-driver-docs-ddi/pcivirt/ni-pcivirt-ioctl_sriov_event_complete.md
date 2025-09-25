# IOCTL_SRIOV_EVENT_COMPLETE IOCTL

## Major Code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

The request indicates that the virtualization stack or the SR-IOV device received one of the events listed in [SRIOV_PF_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ne-pcivirt-_sriov_pf_event).

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

### Input buffer

A pointer to an [SRIOV_PNP_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_pnp_event_complete) structure that contains the NTSTATUS code with which [IOCTL_SRIOV_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_notification) request must be completed.

### Input buffer length

The size of the [SRIOV_PNP_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_pnp_event_complete) structure.

### Output buffer

None.

### Output buffer length

Zero.

### Input/output buffer

None.

### Input/output buffer length

Zero.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE.

The virtualization stack sends the **IOCTL_SRIOV_EVENT_COMPLETE** request when the physical function (PF) driver completes the previously sent [IOCTL_SRIOV_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_notification) request. The **IOCTL_SRIOV_EVENT_COMPLETE** request can be completed synchronously. The stack provides the NTSTATUS code to set for the [SRIOV_PNP_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_pnp_event_complete) is the input buffer.