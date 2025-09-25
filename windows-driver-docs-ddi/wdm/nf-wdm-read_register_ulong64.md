# READ_REGISTER_ULONG64 function (wdm.h)

## Description

The **READ_REGISTER_ULONG64** routine dereferences the supplied pointer, inserts a memory barrier, and reads a ULONG64 value from the specified register address.

### Parameters

### `Register` [in]

Pointer to the register address, which must be a mapped range in memory space.

## Return value

**READ_REGISTER_ULONG64** returns the ULONG64 value that is read from the specified register address.

## Remarks

This routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to this routine will complete before any operation that appears after the call.

For more info about memory barriers, see [**KeMemoryBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kememorybarrier).

Callers of the **READ_REGISTER_ULONG64** macro can be running at any IRQL, assuming the *Register* address is resident, mapped device memory.