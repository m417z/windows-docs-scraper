# IOCTL_SERIAL_IMMEDIATE_CHAR IOCTL

## Description

The **IOCTL_SERIAL_IMMEDIATE_CHAR** request causes a specified character to be transmitted as soon as possible. The immediate character request completes immediately after any other write that might be in progress. Only one immediate character request can be pending at a time.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to the UCHAR value to transmit immediately.

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

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that a previous immediate character request is pending.