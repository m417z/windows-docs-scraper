# IOCTL_SERIAL_SET_QUEUE_SIZE IOCTL

## Description

The **IOCTL_SERIAL_SET_QUEUE_SIZE** request sets the size of the internal receive buffer. If the requested size is greater than the current receive buffer size, a new receive buffer is created. Otherwise, the receive buffer is not changed.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated [SERIAL_QUEUE_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_queue_size) structure that is used to input a receive buffer size.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a **SERIAL_QUEUE_SIZE** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[SERIAL_QUEUE_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_queue_size)