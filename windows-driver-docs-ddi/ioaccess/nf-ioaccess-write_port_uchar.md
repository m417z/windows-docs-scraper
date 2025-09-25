# WRITE_PORT_UCHAR function (ioaccess.h)

## Description

The **WRITE_PORT_UCHAR** routine writes a byte to the specified port address.

## Parameters

### `Port` [in]

Pointer to the port, which must be a mapped memory range in I/O space.

### `Value` [in]

Specifies a byte to be written to the port.

## Remarks

Callers of **WRITE_PORT_UCHAR** can be running at any IRQL, assuming the *Port* is resident, mapped device memory.