# WDF_READ_PORT_USHORT function

## Description

[Applies to UMDF only]

The **WDF_READ_PORT_USHORT** function reads a USHORT value from the specified port address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Port` [in]

Specifies the port address, which must be a mapped memory range in I/O space.

## Return value

**WDF_READ_PORT_USHORT** returns the USHORT value that is read from the specified port address.