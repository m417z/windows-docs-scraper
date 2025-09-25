# IOCTL_HPMI_BATTERY_UTILIZATION_HINT IOCTL

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

Set command sent to HPMI to provide battery utilization hints.

**Important** Preliminary Information

## Parameters

### Major code

### Input buffer

The AssociatedIrp.SystemBuffer member of the I/O request packet (IRP) points to an initiator-allocated buffer that is used both as the input buffer and the output buffer for the request. On input, this buffer contains a [HPMI_BATTERY_UTILIZATION_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_battery_utilization_hint) structure in which the version is set to a valid value.

### Input buffer length

The Parameters.DeviceIoControl.InputBufferLength member of the IRP's current I/O stack location (IO_STACK_LOCATION) is set to the size in bytes of the buffer that is pointed to by the AssociatedIrp.SystemBuffer member. This size must be greater than or equal to sizeof [HPMI_BATTERY_UTILIZATION_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_battery_utilization_hint) structure or the request will fail with an error status of STATUS_INVALID_PARAMETER.

### Output buffer

TBD

### Output buffer length

TBD

### Input/output buffer

TBD

### Input/output buffer length

TBD

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code, for example STATUS_INVALID_PARAMETER.

## Remarks

 This IOCTL may be issued multiple times if HPMI requests HPMI_REQUEST_SERVICE_BATTERY_UTILIZATION_HINTS service.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[HPMI_HINT_BOOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ne-hpmi-_hpmi_hint_bool)

[IOCTL_HPMI_BATTERY_UTILIZATION_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ni-hpmi-ioctl_hpmi_battery_utilization_hint)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)

[hpmi.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/)