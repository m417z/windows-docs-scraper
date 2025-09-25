# READ_PORT_ULONG function (wdm.h)

## Description

The **READ_PORT_ULONG** routine reads a ULONG value from the specified port address.

### Parameters

### `Port` [in]

Specifies the port address, which must be a mapped range in I/O space.

## Return value

**READ_PORT_ULONG** returns the ULONG value that is read from the specified port address.

## Remarks

Callers of **READ_PORT_ULONG** can be running at any IRQL, assuming the *Port* is resident, mapped device memory.