# IOCTL_UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED IOCTL

## Description

Notifies the client driver that an alternate mode is entered so that the driver can perform additional tasks.

## Parameters

### Major code

### Input buffer

A pointer to a [UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED_IN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_alternate_mode_entered_in_params) structure that contains information about the alternate mode.

### Input buffer length

The size of [UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED_IN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_alternate_mode_entered_in_params).

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

The UcmTcpciCx class extension sends this IOCTL request when an alternate mode is entered. The client driver can determine the alternate mode that was entered based on the values passed in *SVID* and *Mode* of the supplied structure.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)