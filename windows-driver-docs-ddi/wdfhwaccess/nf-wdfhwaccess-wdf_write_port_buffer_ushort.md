# WDF_WRITE_PORT_BUFFER_USHORT function

## Description

[Applies to UMDF only]

The **WDF_WRITE_PORT_BUFFER_USHORT** function writes a number of USHORT values from a buffer to the specified port address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Port` [in]

A pointer to the port, which must be a mapped memory range in I/O space.

### `Buffer` [in]

A pointer to a buffer from which an array of USHORT values is to be written.

### `Count` [in]

Specifies the number of USHORT values to be written to the buffer.