# IOCTL_SERIAL_LSRMST_INSERT IOCTL

## Description

The **IOCTL_SERIAL_LSRMST_INSERT** request enables or disables the insertion of information about line status and modem status in the receive data stream. If LSRMST insertion is enabled, the driver inserts event information for the supported event types. The event information includes an *event header* followed by event-specific data.

The event header contains a client-specified escape character and a SERIAL_LSRMST_*XXX* constant that indicates the event type. The driver supports the following event types:

SERIAL_LSRMST_LSR_DATA

A change occurred in the line status. The serial controller driver inserts an event header followed by the event-specific data, which is the value of the line status register followed by the character present in the receive hardware when the line-status change was processed.

SERIAL_LSRMST_LSR_NODATA

A line status change occurred, but no data was available in the receive buffer. The serial controller driver inserts an event header followed by the event-specific data, which is the value of the line status register when the line status change was processed.

SERIAL_LSRMST_MST

A change occurred in the modem status. The serial controller driver inserts an event header followed by the event-specific data, which is the value of the modem status register when the modem-status change was processed.

SERIAL_LSRMST_ESCAPE

Indicates that the next character in the receive data stream, which was received from the device, is identical to the client-specified escape character. The serial controller driver inserts an event header. There is no event-specific data.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated UCHAR input value to use as the escape character. If the escape character is nonzero, insertion is enabled, and the serial driver uses the specified escape character. Otherwise, insertion is disabled.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a UCHAR.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a UCHAR. Otherwise, **Information** is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that the specified escape character is the same as the XON (transmit on) or the XOFF (transmit off) character, or that error replacement is enabled with handshake flow control.