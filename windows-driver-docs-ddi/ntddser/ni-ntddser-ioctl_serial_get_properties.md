# IOCTL_SERIAL_GET_PROPERTIES IOCTL

## Description

The **IOCTL_SERIAL_GET_PROPERTIES** request returns information about the capabilities of a serial controller. The capabilities information is returned in a [SERIAL_COMMPROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_commprop) structure.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** points to a client-allocated **SERIAL_COMMPROP** structure that the serial controller driver uses to output information about the capabilities of the serial controller.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** is set to the size, in bytes, of a **SERIAL_COMMPROP** structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a **SERIAL_COMMPROP** structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[SERIAL_COMMPROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_commprop)