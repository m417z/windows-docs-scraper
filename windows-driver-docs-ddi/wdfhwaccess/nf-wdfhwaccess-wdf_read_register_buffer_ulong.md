# WDF_READ_REGISTER_BUFFER_ULONG function

## Description

[Applies to UMDF only]

The **WDF_READ_REGISTER_BUFFER_ULONG** function reads a number of ULONG values from the specified register address into a buffer.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Buffer` [out]

A pointer to a buffer into which an array of ULONG values is read.

### `Count` [in]

Specifies the number of ULONG values to be read into the buffer.