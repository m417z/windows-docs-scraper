# READ_REGISTER_BUFFER_ULONG function (miniport.h)

## Description

The **READ_REGISTER_BUFFER_ULONG** routine reads a number of ULONG values from the specified register address into a buffer.

## Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Buffer` [out]

Pointer to a buffer into which an array of ULONG values is read.

### `Count` [in]

Specifies the number of ULONG values to be read into the buffer.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of ULONG values.

Callers of **READ_REGISTER_BUFFER_ULONG** can be running at any IRQL, assuming the *Buffer* is resident and the *Register* is resident, mapped device memory.