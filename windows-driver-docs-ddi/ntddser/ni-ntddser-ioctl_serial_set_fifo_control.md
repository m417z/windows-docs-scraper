# IOCTL_SERIAL_SET_FIFO_CONTROL IOCTL

## Description

The **IOCTL_SERIAL_SET_FIFO_CONTROL** request sets the FIFO control register (FCR). Serial does not verify the specified FIFO control information.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG that is used to input FIFO control information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** is set to the size, in bytes, of a ULONG.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).