# IOCTL_SERIAL_GET_COMMSTATUS IOCTL

## Description

The **IOCTL_SERIAL_GET_COMMSTATUS** request returns information about the communication status of a serial device. For more information about the status information that is retrieved by this request, see [SERIAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_status).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated **SERIAL_STATUS** structure that the serial controller driver uses to output communication status information.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size in bytes of a **SERIAL_STATUS** structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size in bytes of a **SERIAL_STATUS** structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[SERIAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_status)