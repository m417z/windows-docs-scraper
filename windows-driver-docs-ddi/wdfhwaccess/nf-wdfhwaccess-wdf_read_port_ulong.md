# WDF_READ_PORT_ULONG function

## Description

[Applies to UMDF only]

The **WDF_READ_PORT_ULONG** function reads a ULONG value from the specified port address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Port` [in]

Specifies the port address, which must be a mapped memory range in I/O space.

## Return value

**WDF_READ_PORT_ULONG** returns the ULONG value that is read from the specified port address.