# WDF_WRITE_REGISTER_ULONG function

## Description

[Applies to UMDF only]

The **WDF_WRITE_REGISTER_ULONG** routine writes a ULONG value to the specified address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a ULONG value to write to the register.