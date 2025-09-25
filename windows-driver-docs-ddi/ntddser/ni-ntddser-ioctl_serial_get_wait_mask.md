# IOCTL_SERIAL_GET_WAIT_MASK IOCTL

## Description

The **IOCTL_SERIAL_GET_WAIT_MASK** request returns the event wait mask that is currently set for the serial controller.

A client can wait for the wait events represented by flag bits **SERIAL_EV_RXCHAR** through **SERIAL_EV_EVENT2**. For more information about these event flags, see the Remarks section.

To set an event wait mask, a client can use an [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request. To wait for the occurrence of a wait event, a client uses an [IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask) request.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG buffer that the serial controller driver uses to output the wait mask. The wait mask is either zero or the bitwise-OR of one or more of the **SERIAL_EV_***XXX* event flags.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a ULONG. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## Remarks

 The **SERIAL_EV_***XXX* constants define the flag bits in the wait mask for a serial port.

```
#define SERIAL_EV_RXCHAR     0x0001
#define SERIAL_EV_RXFLAG     0x0002
#define SERIAL_EV_TXEMPTY    0x0004
#define SERIAL_EV_CTS        0x0008
#define SERIAL_EV_DSR        0x0010
#define SERIAL_EV_RLSD       0x0020
#define SERIAL_EV_BREAK      0x0040
#define SERIAL_EV_ERR        0x0080
#define SERIAL_EV_RING       0x0100
#define SERIAL_EV_PERR       0x0200
#define SERIAL_EV_RX80FULL   0x0400
#define SERIAL_EV_EVENT1     0x0800
#define SERIAL_EV_EVENT2     0x1000
```

The **SERIAL_EV_***XXX* constants define the types of events that can be specified in a wait mask. After a client (application or peripheral driver) opens a connection to a serial port, the client can specify a wait mask that indicates the types of events that the client needs to monitor. These events are changes in the hardware state of the serial port. When an event in the wait mask occurs, the client is notified.

The [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) and **IOCTL_SERIAL_GET_WAIT_MASK** control requests use event wait masks to specify a set of events on which a client can wait. A wait mask value is either zero or the bitwise-OR of one or more **SERIAL_EV_***XXX* constants. A wait mask value of zero indicates that the client is not waiting for any events.

The client sends an [IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask) control request to wait for an event in the currently set wait mask. The serial controller driver completes this request when an event in the wait mask occurs.

The following table shows which **SERIAL_EV_***XXX* flag bits are supported by SerCx2, SerCx, and Serial.sys. A **Yes** entry in the table indicates that the serial framework extension or driver supports the corresponding flag bit. A **No** entry indicates that the flag bit is not supported.

| Flag bit | SerCx2 | SerCx | Serial.sys |
| --- | --- | --- | --- |
| **SERIAL_EV_RXCHAR** | Yes | Yes | Yes |
| **SERIAL_EV_RXFLAG** | See note. | No | Yes |
| **SERIAL_EV_TXEMPTY** | Yes | Yes | Yes |
| **SERIAL_EV_CTS** | Yes | Yes | Yes |
| **SERIAL_EV_DSR** | Yes | Yes | Yes |
| **SERIAL_EV_RLSD** | See note. | Yes | Yes |
| **SERIAL_EV_BREAK** | Yes | Yes | Yes |
| **SERIAL_EV_ERR** | Yes | Yes | Yes |
| **SERIAL_EV_RING** | See note. | Yes | Yes |
| **SERIAL_EV_PERR** | See note. | No | No |
| **SERIAL_EV_RX80FULL** | See note. | No | Yes |
| **SERIAL_EV_EVENT1** | See note. | No | No |
| **SERIAL_EV_EVENT2** | See note. | No | No |

**Note** SerCx2 may or may not support the flag bit in the indicated table entry, depending on the serial controller driver and the capabilities of the serial controller hardware.

For more information about SerCx2, SerCx, and Serial.sys, see [Serial Controller Drivers Overview](https://learn.microsoft.com/previous-versions/jj241971(v=vs.85)).

## See also

[IOCTL_SERIAL_GET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_chars)

[IOCTL_SERIAL_SET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_chars)

[IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask)

[IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask)

[SERIAL_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_chars)

[SERIAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_status)