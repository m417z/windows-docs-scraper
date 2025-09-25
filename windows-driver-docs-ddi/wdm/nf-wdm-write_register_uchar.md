# WRITE_REGISTER_UCHAR function (wdm.h)

## Description

The **WRITE_REGISTER_UCHAR** routine dereferences the supplied pointer, inserts a memory barrier, and writes a UCHAR value to the specified address.

### Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a byte to be written to the register.

## Remarks

This routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to this routine will complete before any operation that appears after the call.

For more info about memory barriers, see [**KeMemoryBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kememorybarrier).

Callers of **WRITE_REGISTER_UCHAR** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.