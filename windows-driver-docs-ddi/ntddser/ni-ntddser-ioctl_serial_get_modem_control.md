# IOCTL_SERIAL_GET_MODEM_CONTROL IOCTL

## Description

The **IOCTL_SERIAL_GET_MODEM_CONTROL** request returns the value of the modem control register in the serial controller.

To set the modem control register, a client can use an [IOCTL_SERIAL_SET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_modem_control) request.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG buffer that the serial controller driver uses to output the value of the modem control register.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a ULONG. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## Remarks

The **IOCTL_SERIAL_GET_MODEM_CONTROL** and **IOCTL_SERIAL_SET_MODEM_CONTROL** requests are used primarily for hardware testing. No standard register layout is defined for the modem control operations. Peripheral drivers that use these IOCTLs risk making themselves dependent on the hardware features of a particular serial controller.

For an example layout of a modem control register, see the definition of the MCR bits (SERIAL_MCR_DTR through SERIAL_MCR_LOOP) in the Serial.h header file in the [Serial driver sample](https://go.microsoft.com/fwlink/p/?LinkId=617962) on GitHub.

## See also

[IOCTL_SERIAL_SET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_modem_control)