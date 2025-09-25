# WDF_WRITE_REGISTER_UCHAR function

## Description

[Applies to UMDF only]

The **WDF_WRITE_REGISTER_UCHAR** routine writes a byte to the specified address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a byte to write to the register.