# IOCTL_SERIAL_GET_DTRRTS IOCTL

## Description

The **IOCTL_SERIAL_GET_DTRRTS** request returns information about the *data terminal ready* (DTR) control signal and the *request to send* (RTS) control signal.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG buffer that Serial.sys uses to output information about the DTR and RTS. The ULONG buffer is set to zero or to the bitwise-OR of one or more of the following flag bits:

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size in bytes of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size in bytes of a ULONG. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## -SERIAL_DTR_STATE

Indicates that DTR is set.

## -SERIAL_RTS_STATE

Indicates that RTS is set.

## See also

[IOCTL_SERIAL_SET_DTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_dtr)

[IOCTL_SERIAL_SET_RTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_rts)