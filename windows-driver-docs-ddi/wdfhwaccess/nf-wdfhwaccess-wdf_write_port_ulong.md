# WDF_WRITE_PORT_ULONG function

## Description

[Applies to UMDF only]

The **WDF_WRITE_PORT_ULONG** function writes a ULONG value to the specified port address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Port` [in]

A pointer to the port, which must be a mapped memory range in I/O space.

### `Value` [in]

Specifies a ULONG value to be written to the port.