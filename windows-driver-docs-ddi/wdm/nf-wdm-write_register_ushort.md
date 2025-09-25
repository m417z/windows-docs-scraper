# WRITE_REGISTER_USHORT function (wdm.h)

## Description

The **WRITE_REGISTER_USHORT** routine dereferences the supplied pointer, inserts a memory barrier, and writes a USHORT value to the specified address.

### Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a USHORT value to be written to the register.

## Remarks

This routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to this routine will complete before any operation that appears after the call.

For more info about memory barriers, see [**KeMemoryBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kememorybarrier).

Callers of **WRITE_REGISTER_USHORT** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.