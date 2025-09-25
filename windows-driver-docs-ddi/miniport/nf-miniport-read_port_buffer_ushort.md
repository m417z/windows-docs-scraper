# READ_PORT_BUFFER_USHORT function (miniport.h)

## Description

The **READ_PORT_BUFFER_USHORT** routine reads a number of USHORT values from the specified port address into a buffer.

## Parameters

### `Port` [in]

Specifies the port address, which must be a mapped memory range in I/O space.

### `Buffer` [out]

Pointer to a buffer into which an array of USHORT values is read.

### `Count` [in]

Specifies the number of USHORT values to be read into the buffer.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of USHORT values.

Callers of **READ_PORT_BUFFER_USHORT** can be running at any IRQL, assuming the *Buffer* is resident and the *Port* is resident, mapped device memory.