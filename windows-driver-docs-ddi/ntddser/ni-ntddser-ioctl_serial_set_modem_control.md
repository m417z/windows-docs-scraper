# IOCTL_SERIAL_SET_MODEM_CONTROL IOCTL

## Description

The **IOCTL_SERIAL_SET_MODEM_CONTROL** request sets the modem control register (MCR) in the UART. No parameter checking is done on the client-supplied register settings.

To obtain the value of the MCR, a client can use an [IOCTL_SERIAL_GET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_modem_control) request.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG that is used to input modem control information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a ULONG.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## Remarks

The implementation of this I/O control request (IOCTL) is hardware-specific because no standard layout is defined for the modem control register (MCR) across 16550-compatible UART devices. The drivers for peripheral devices that connect to serial ports should avoid using this IOCTL, which might work with some UARTs but not with others. This IOCTL is primarily used to configure the UART into loopback mode for testing, but only if the UART has an MCR that supports loopback mode.

For an example layout of an MCR, see the definition of the MCR bits (SERIAL_MCR_DTR through SERIAL_MCR_LOOP) in the Serial.h header file in the [Serial driver sample](https://go.microsoft.com/fwlink/p/?LinkId=617962) on GitHub.

## See also

[IOCTL_SERIAL_GET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_modem_control)