# WRITE_PORT_ULONG function (wdm.h)

## Description

The **WRITE_PORT_ULONG** routine writes a ULONG value to the specified port address.

### Parameters

### `Port` [in]

Pointer to the port, which must be a mapped memory range in I/O space.

### `Value` [in]

Specifies a ULONG value to be written to the port.

## Return value

None

## Remarks

Callers of **WRITE_PORT_ULONG** can be running at any IRQL, assuming the *Port* is resident, mapped device memory.