# WDF_READ_REGISTER_USHORT function

## Description

[Applies to UMDF only]

The **WDF_READ_REGISTER_USHORT** function reads a USHORT value from the specified register address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register address, which must be a mapped range in memory space.

## Return value

**WDF_READ_REGISTER_USHORT** returns the USHORT value that is read from the specified port address.