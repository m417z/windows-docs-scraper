# WDF_WRITE_REGISTER_BUFFER_ULONG function

## Description

[Applies to UMDF only]

The **WDF_WRITE_REGISTER_BUFFER_ULONG** function writes a number of ULONG values from a buffer to the specified register.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Buffer` [in]

A pointer to a buffer from which an array of ULONG values is to be written.

### `Count` [in]

Specifies the number of ULONG values to write to the register.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of bytes.