# WDF_WRITE_REGISTER_USHORT function

## Description

[Applies to UMDF only]

The **WDF_WRITE_REGISTER_USHORT** routine writes a USHORT value to the specified address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register address, which must be a mapped range in memory space.

### `Value` [in]

Specifies a USHORT value to write to the register.