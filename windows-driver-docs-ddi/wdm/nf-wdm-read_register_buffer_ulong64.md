# READ_REGISTER_BUFFER_ULONG64 function (wdm.h)

## Description

The **READ_REGISTER_BUFFER_ULONG64** routine dereferences the supplied pointer, inserts a memory barrier, and reads a set of ULONG64 values from the specified register address into a buffer

### Parameters

### `Register` [in]

Pointer to the register address, which must be a mapped range in memory space.

### `Buffer` [out]

Pointer to a buffer that an array of ULONG64 values is read into.

### `Count` [in]

Specifies the number of ULONG64 values to be read into the buffer.

## Remarks

This routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to this routine will complete before any operation that appears after the call.

For more info about memory barriers, see [**KeMemoryBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kememorybarrier).

The size of the *Buffer* buffer must be large enough to contain at least the specified number of ULONG64 values.

Callers of the **READ_REGISTER_BUFFER_ULONG64** macro can be running at any IRQL, assuming that the *Buffer* buffer is resident and the *Register* register is resident, mapped device memory.