# WDF_WRITE_REGISTER_ULONG64 function

## Description

[Applies to UMDF only]

The **WDF_WRITE_REGISTER_ULONG64** function writes a ULONG64 value to the specified address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a ULONG64 value to write to the register.