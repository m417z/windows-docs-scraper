# WRITE_REGISTER_BUFFER_USHORT function (miniport.h)

## Description

The **WRITE_REGISTER_BUFFER_USHORT** routine writes a number of USHORT values from a buffer to the specified register.

## Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Buffer` [in]

Pointer to a buffer from which an array of USHORT values is to be written.

### `Count` [in]

Specifies the number of USHORT values to be written to the register.

## Remarks

The size of the buffer must be large enough to contain at least the specified number of USHORT values.

Callers of **WRITE_REGISTER_BUFFER_USHORT** can be running at any IRQL, assuming the *Buffer* is resident and the *Register* is resident, mapped device memory.