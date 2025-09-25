# IOCTL_HID_SEND_IDLE_NOTIFICATION_REQUEST IOCTL

## Description

The **IOCTL_HID_SEND_IDLE_NOTIFICATION_REQUEST**
control code is the IOCTL of the idle notification request IRP that HIDClass sends to HID mini drivers, such as HIDUSB, to inform the bus driver that the device is now idle.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

### Input buffer length

 The size of a status code.

### Output buffer

 None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The bus or port driver sets Irp->IoStatus.Status to STATUS_SUCCESS or the appropriate error status.