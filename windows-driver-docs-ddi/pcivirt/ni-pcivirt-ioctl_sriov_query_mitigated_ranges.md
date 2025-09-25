# IOCTL_SRIOV_QUERY_MITIGATED_RANGES IOCTL

## Major Code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

The request determines the specific ranges on which intercepts must be placed.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

### Input buffer

A pointer to a [SRIOV_MITIGATED_RANGES_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_ranges_input) structure that specifies the virtual function (VF) whose ranges are to be mitigated.

### Input buffer length

The size of the [SRIOV_MITIGATED_RANGES_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_ranges_input) structure.

### Output buffer

A pointer to a [SRIOV_MITIGATED_RANGES_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_ranges_output) structure that specifies the virtual function (VF) whose ranges were to mitigated.

### Output buffer length

The size of the [SRIOV_MITIGATED_RANGES_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_mitigated_ranges_output) structure.

### Input/output buffer

Not used with this operation; set this parameter to **NULL**.

### Input/output buffer length

Not used with this operation; set this parameter to zero.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_MITIGABLE_DEVICE_INTERFACE.

The virtualization stack uses an I/O MMU to differentiate traffic coming from the various interfaces that the device exposes, enforcing policy about which regions of memory a device can access and which interrupts it can generate.

The request is sent to the physical function (PF) by virtualization stack to get the specific ranges on which intercepts must be placed.