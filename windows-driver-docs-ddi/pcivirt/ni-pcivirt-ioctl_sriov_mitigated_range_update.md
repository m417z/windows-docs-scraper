# IOCTL_SRIOV_MITIGATED_RANGE_UPDATE IOCTL

## Major Code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

The **IOCTL_SRIOV_MITIGATED_RANGE_UPDATE** request indicates that the virtualization stack wants to update to the mitigation ranges.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

### Input buffer

A pointer to a [SRIOV_MITIGATED_RANGE_UPDATE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_range_update_input) structure.

### Input buffer length

Size of the [SRIOV_MITIGATED_RANGE_UPDATE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_range_update_input) structure.

### Output buffer

A buffer that contains an [SRIOV_MITIGATED_RANGE_UPDATE_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_range_update_output)-type value filled by the physical function (PF) driver when it completes the request.

### Output buffer length

A pointer to a variable to contain the number of bytes written to the output buffer when the request is completed.

### Input/output buffer

Not used with this operation; set this value to **NULL**.

### Input/output buffer length

Not used with this operation; set this value to zero.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes MITIGABLE_DEVICE_INTERFACE.

The stack uses an I/O MMU to differentiate traffic coming from the various interfaces that the device exposes, enforcing policy about which regions of memory a device can access and which interrupts it can generate. When that range of memory is updated, the stack sends this request.

The physical function (PF driver) keeps the **IOCTL_SRIOV_MITIGATED_RANGE_UPDATE** request in its queue until the request is either cancelled by the virtualization stack or the PF driver
wants to send a request to the virtual function (VF) driver to update to the mitigation ranges for a particular VF. When the VF completes the request, the PF completes the **IOCTL_SRIOV_MITIGATED_RANGE_UPDATE** request. Upon completion, the virtualization stack reinitializes the mitigation maps by sending [IOCTL_SRIOV_QUERY_MITIGATED_RANGE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_range_count) and [IOCTL_SRIOV_QUERY_MITIGATED_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_ranges) requests. The stack may additionally call any user mode device simulation for additional ranges to mitigate. The **IOCTL_SRIOV_MITIGATED_RANGE_UPDATE** request is sent for each active virtual function.