# WRITE_REGISTER_BUFFER_UCHAR function (miniport.h)

## Description

The **WRITE_REGISTER_BUFFER_UCHAR** routine writes a number of bytes from a buffer to the specified register.

## Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Buffer` [in]

Pointer to a buffer from which an array of UCHAR values is to be written.

### `Count` [in]

Specifies the number of bytes to be written to the register.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of bytes.

Callers of **WRITE_REGISTER_BUFFER_UCHAR** can be running at any IRQL, assuming the *Buffer* is resident and the *Register* is resident, mapped device memory.