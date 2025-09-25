# WDF_READ_PORT_BUFFER_USHORT function

## Description

[Applies to UMDF only]

The **WDF_READ_PORT_BUFFER_USHORT** function reads a number of USHORT values from the specified port address into a buffer.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Port` [in]

Specifies the port address, which must be a mapped memory range in I/O space.

### `Buffer` [out]

A pointer to a buffer into which an array of USHORT values is read.

### `Count` [in]

Specifies the number of USHORT values to be read into the buffer.