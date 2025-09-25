# READ_PORT_BUFFER_UCHAR function (wdm.h)

## Description

The **READ_PORT_BUFFER_UCHAR** routine reads a number of bytes from the specified port address into a buffer.

### Parameters

### `Port` [in]

Specifies the port address, which must be a mapped memory range in I/O space.

### `Buffer` [out]

Pointer to a buffer into which an array of UCHAR values is read.

### `Count` [in]

Specifies the number of bytes to be read into the buffer.

## Return value

None

## Remarks

The size of the buffer must be large enough to contain at least the specified number of bytes.

Callers of **READ_PORT_BUFFER_UCHAR** can be running at any IRQL, assuming the *Buffer* is resident and the *Port* is resident, mapped device memory.