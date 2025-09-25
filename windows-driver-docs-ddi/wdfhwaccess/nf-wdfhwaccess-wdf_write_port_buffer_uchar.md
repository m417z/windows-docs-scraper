# WDF_WRITE_PORT_BUFFER_UCHAR function

## Description

[Applies to UMDF only]

The **WDF_WRITE_PORT_BUFFER_UCHAR** function writes a number of bytes from a buffer to the specified port.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Port` [in]

A pointer to the port, which must be a mapped memory range in I/O space.

### `Buffer` [in]

A pointer to a buffer from which an array of UCHAR values is to be written.

### `Count` [in]

Specifies the number of bytes to be written to the buffer.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of bytes.