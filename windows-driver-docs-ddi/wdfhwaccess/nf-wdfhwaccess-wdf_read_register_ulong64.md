# WDF_READ_REGISTER_ULONG64 function

## Description

[Applies to UMDF only]

The **WDF_READ_REGISTER_ULONG64** function reads a ULONG64 value from the specified register address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register address, which must be a mapped range in memory space.

## Return value

**WDF_READ_REGISTER_ULONG64** returns the ULONG64 value that is read from the specified port address.