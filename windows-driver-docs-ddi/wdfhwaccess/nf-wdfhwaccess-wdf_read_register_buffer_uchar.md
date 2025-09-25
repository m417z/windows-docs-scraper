# WDF_READ_REGISTER_BUFFER_UCHAR function

## Description

[Applies to UMDF only]

The **WDF_READ_REGISTER_BUFFER_UCHAR** function reads a number of bytes from the specified register address into a buffer.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Buffer` [out]

A pointer to a buffer into which an array of UCHAR values is read.

### `Count` [in]

Specifies the number of bytes to be read into the buffer.