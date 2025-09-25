# READ_PORT_BUFFER_ULONG function (miniport.h)

## Description

The **READ_PORT_BUFFER_ULONG** routine reads a number of ULONG values from the specified port address into a buffer.

## Parameters

### `Port` [in]

Specifies the port address, which must be a mapped memory range in I/O space.

### `Buffer` [out]

Pointer to a buffer into which an array of ULONG values is read.

### `Count` [in]

Specifies the number of ULONG values to be read into the buffer.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of ULONG values.

Callers of **READ_PORT_BUFFER_ULONG** can be running at any IRQL, assuming the *Buffer* is resident and the *Port* is resident, mapped device memory.