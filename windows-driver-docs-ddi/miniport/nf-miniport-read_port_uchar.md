# READ_PORT_UCHAR function (miniport.h)

## Description

The **READ_PORT_UCHAR** routine reads a byte from the specified port address.

## Parameters

### `Port` [in]

Specifies the port address, which must be a mapped memory range in I/O space.

## Return value

**READ_PORT_UCHAR** returns the byte that is read from the specified port address.

## Remarks

Callers of **READ_PORT_UCHAR** can be running at any IRQL, assuming the *Port* is resident, mapped device memory.