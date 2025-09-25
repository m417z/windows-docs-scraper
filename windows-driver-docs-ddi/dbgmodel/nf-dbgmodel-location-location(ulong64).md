# Location(ULONG64) function (dbgmodel.h)

## Description

Constructs a location from an offset into the virtual address space of the target.

## Parameters

### `virtualAddress`

The virtual address.

## Remarks

Defines the location for an object. This particular variant of Location is the C-COM access struct.
Note that a location only has meaning in conjunction with a host context. It is a location within
a context. When performing an operation on the location (reading bytes, writing bytes, etc...), a valid host context must be supplied.

### Returns

This function is a constructor and does not return value.

## See also

[dbgmodel.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/)