# READ_PORT_USHORT function (miniport.h)

## Description

The **READ_PORT_USHORT** routine reads a USHORT value from the specified port address.

## Parameters

### `Port` [in]

Specifies the port address, which must be a mapped range in I/O space.

## Return value

**READ_PORT_USHORT** returns the USHORT value that is read from the specified port address.

## Remarks

Callers of **READ_PORT_USHORT** can be running at any IRQL, assuming the *Port* is resident, mapped device memory.