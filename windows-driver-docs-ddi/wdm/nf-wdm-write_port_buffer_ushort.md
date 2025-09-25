# WRITE_PORT_BUFFER_USHORT function (wdm.h)

## Description

The **WRITE_PORT_BUFFER_USHORT** routine writes a number of USHORT values from a buffer to the specified port address.

### Parameters

### `Port` [in]

Pointer to the port, which must be a mapped memory range in I/O space.

### `Buffer` [in]

Pointer to a buffer from which an array of USHORT values is to be written.

### `Count` [in]

Specifies the number of USHORT values to be written to the port.

## Return value

None

## Remarks

The size of the buffer must be large enough to contain at least the specified number of USHORT values.

Callers of **WRITE_PORT_BUFFER_USHORT** can be running at any IRQL, assuming the *Buffer* is resident and the *Port* is resident, mapped device memory.