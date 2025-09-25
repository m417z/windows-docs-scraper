# IOCTL_SERIAL_CONFIG_SIZE IOCTL

## Description

The **IOCTL_SERIAL_CONFIG_SIZE** request returns information about configuration size.

Serial.sys always returns a configuration size of zero.

This request is obsolete and should not be used by new drivers for Microsoft Windows 2000 and later.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG buffer that Serial.sys uses to output configuration size information.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** is set to the size in bytes of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size in bytes of a ULONG.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).