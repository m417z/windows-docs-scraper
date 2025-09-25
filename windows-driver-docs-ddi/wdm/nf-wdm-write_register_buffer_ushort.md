# WRITE_REGISTER_BUFFER_USHORT function (wdm.h)

## Description

The **WRITE_REGISTER_BUFFER_USHORT** routine dereferences the supplied pointer, inserts a memory barrier, and writes a set of USHORT values from a buffer to the specified address.

### Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Buffer` [in]

Pointer to a buffer from which an array of USHORT values is to be written.

### `Count` [in]

Specifies the number of USHORT values to be written to the register.

## Remarks

This routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to this routine will complete before any operation that appears after the call.

For more info about memory barriers, see [**KeMemoryBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kememorybarrier).

The size of the buffer must be large enough to contain at least the specified number of USHORT values.

Callers of **WRITE_REGISTER_BUFFER_USHORT** can be running at any IRQL, assuming the *Buffer* is resident and the *Register* is resident, mapped device memory.