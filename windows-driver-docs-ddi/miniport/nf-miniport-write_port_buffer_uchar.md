# WRITE_PORT_BUFFER_UCHAR function (miniport.h)

## Description

The **WRITE_PORT_BUFFER_UCHAR** routine writes a number of bytes from a buffer to the specified port.

## Parameters

### `Port` [in]

Pointer to the port, which must be a mapped memory range in I/O space.

### `Buffer` [in]

Pointer to a buffer from which an array of UCHAR values is to be written.

### `Count` [in]

Specifies the number of bytes to be written to the port.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of bytes.

Callers of **WRITE_PORT_BUFFER_UCHAR** can be running at any IRQL, assuming the *Buffer* is resident and the *Port* is resident, mapped device memory.