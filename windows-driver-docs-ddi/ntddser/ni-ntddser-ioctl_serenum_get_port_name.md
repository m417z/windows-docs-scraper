# IOCTL_SERENUM_GET_PORT_NAME IOCTL

## Description

The IOCTL_SERENUM_GET_PORT_NAME request returns the value of the **PortName** (or **Identifier**) entry value for the RS-232 port -- see [Registry Settings for a Plug and Play Serial Device](https://learn.microsoft.com/previous-versions/ff546972(v=vs.85)).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated buffer that Serenum uses to output the port name. The port name is a null-terminated Unicode string.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size in bytes of a client-allocated output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size in bytes of the null-terminated Unicode string that is returned in the client's output buffer.

The **Status** member is set to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The output buffer is too small to hold the port name string.

**STATUS_SUCCESS**

The request completed successfully.

**STATUS_UNSUCCESSFUL**

An error occurred when opening the registry key for the device or reading the **PortName** (or **Identifier)** entry value.