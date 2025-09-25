# IOCTL_SERIAL_GET_MODEMSTATUS IOCTL

## Description

The **IOCTL_SERIAL_GET_MODEMSTATUS** request updates the modem status, and returns the value of the modem status register before the update.

For more information, see the definitions of the modem status register bits (SERIAL_MSR_DCTS through SERIAL_MSR_DCD) in the Serial.h header file in the [Serial driver sample](https://go.microsoft.com/fwlink/p/?LinkId=617962) on GitHub.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG buffer that the serial controller driver uses to output the value of the modem status register.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a ULONG. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_SET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_modem_control)