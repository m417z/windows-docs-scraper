# WRITE_PORT_BUFFER_ULONG function (wdm.h)

## Description

The **WRITE_PORT_BUFFER_ULONG** routine writes a number of ULONG values from a buffer to the specified port address.

### Parameters

### `Port` [in]

Pointer to the port, which must be a mapped memory range in I/O space.

### `Buffer` [in]

Pointer to a buffer from which an array of ULONG values is to be written.

### `Count` [in]

Specifies the number of ULONG values to be written to the port.

## Return value

None

## Remarks

The size of the buffer must be large enough to contain at least the specified number of ULONG values.

Callers of **WRITE_PORT_BUFFER_ULONG** can be running at any IRQL, assuming the *Buffer* is resident and the *Port* is resident, mapped device memory.