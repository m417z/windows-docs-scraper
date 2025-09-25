# WRITE_PORT_USHORT function (miniport.h)

## Description

The **WRITE_PORT_USHORT** routine writes a USHORT value to the specified port address.

## Parameters

### `Port` [in]

Pointer to the port, which must be a mapped memory range in I/O space.

### `Value` [in]

Specifies a USHORT value to be written to the port.

## Remarks

Callers of **WRITE_PORT_USHORT** can be running at any IRQL, assuming the *Port* is resident, mapped device memory.