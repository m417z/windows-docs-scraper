# WDF_WRITE_REGISTER_BUFFER_USHORT function

## Description

[Applies to UMDF only]

The **WDF_WRITE_REGISTER_BUFFER_USHORT** routine writes a number of USHORT values from a buffer to the specified register.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Buffer` [in]

A pointer to a buffer into which an array of USHORT values is to be written.

### `Count` [in]

Specifies the number of USHORT values to write to the register.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of bytes.