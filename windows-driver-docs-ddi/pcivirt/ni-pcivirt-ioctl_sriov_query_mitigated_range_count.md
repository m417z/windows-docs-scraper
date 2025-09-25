# IOCTL_SRIOV_QUERY_MITIGATED_RANGE_COUNT IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

 The request determines the ranges of memory-mapped I/O space that must mitigated.

## Parameters

### Major code

### Input buffer

A pointer to a [SRIOV_MITIGATED_RANGE_COUNT_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_range_count_input) structure. Set the **VfIndex** member to 0.

### Input buffer length

The size of the [SRIOV_MITIGATED_RANGE_COUNT_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_range_count_input) structure.

### Output buffer

A pointer to a [SRIOV_MITIGATED_RANGE_COUNT_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_range_count_output) structure that is filled by the physical function (PF) driver with ranges of memory-mapped I/O space.

### Output buffer length

The size of the [SRIOV_MITIGATED_RANGE_COUNT_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_range_count_output) structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_MITIGABLE_DEVICE_INTERFACE.

The virtualization stack uses an I/O MMU to differentiate traffic coming from the various interfaces that the device exposes, enforcing policy about which regions of memory a device can access and which interrupts it can generate.

The request is sent to the physical function (PF) driver by the virtualization stack to find out the ranges of memory-mapped I/O space
in which the stack must place
intercepts on those pages and send the requests to read and write values
within those pages to the PF driver.