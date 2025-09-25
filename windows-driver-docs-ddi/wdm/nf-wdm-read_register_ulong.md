# READ_REGISTER_ULONG function (wdm.h)

## Description

The **READ_REGISTER_ULONG** routine dereferences the supplied pointer, inserts a memory barrier, and reads a ULONG value from the specified register address.

### Parameters

### `Register` [in]

Pointer to the register address, which must be a mapped range in memory space.

## Return value

**READ_REGISTER_ULONG** returns the ULONG value read from the specified register address.

## Remarks

This routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to this routine will complete before any operation that appears after the call.

For more info about memory barriers, see [**KeMemoryBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kememorybarrier).

Callers of **READ_REGISTER_ULONG** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.