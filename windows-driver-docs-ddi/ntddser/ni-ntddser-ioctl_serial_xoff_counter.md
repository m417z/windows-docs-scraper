# IOCTL_SERIAL_XOFF_COUNTER IOCTL

## Description

The **IOCTL_SERIAL_XOFF_COUNTER** request sets an *XOFF counter*. An XOFF counter request supports clients that use software to emulate hardware handshake flow control.

An XOFF counter request is synchronized with write requests. The driver sends a specified XOFF character, and completes the request after one of the following events occurs:

* A write request is received.
* A timer expires (a time-out value is specified by the XOFF counter request).
* The serial controller driver receives a number of characters that is greater than or equal to a count specified by the XOFF counter request.

For more information about the operation of an XOFF counter, see the description of the **SERIAL_XOFF_COUNTER** structure in the Ntddser.h header file in the Microsoft Windows Driver Kit (WDK).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** points to a client-allocated **SERIAL_XOFF_COUNTER** structure that is used to input XOFF counter information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** is set to the size, in bytes, of a **SERIAL_XOFF_COUNTER** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2) or to one of the following request-specific values:

**STATUS_INVALID_PARAMETER**

The count value specified for the XOFF counter request is less than zero.

**STATUS_SERIAL_COUNTER_TIMEOUT**

The request timed out.

**STATUS_SERIAL_MORE_WRITES**

A write request was received.

## See also

[IOCTL_SERIAL_SET_XOFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_xoff)

[IOCTL_SERIAL_SET_XON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_xon)