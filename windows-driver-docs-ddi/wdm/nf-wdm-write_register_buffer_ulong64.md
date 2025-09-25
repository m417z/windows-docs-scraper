# WRITE_REGISTER_BUFFER_ULONG64 function (wdm.h)

## Description

The **WRITE_REGISTER_BUFFER_ULONG64** routine dereferences the supplied pointer, inserts a memory barrier, and writes a set of ULONG64 values from a buffer to the specified address.

### Parameters

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Buffer` [in]

A pointer to a buffer into which an array of ULONG64 values is to be written.

### `Count` [in]

Specifies the number of ULONG64 values to write to the register.

## Remarks

This routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to this routine will complete before any operation that appears after the call.

For more info about memory barriers, see [**KeMemoryBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kememorybarrier).

The size of the buffer must be large enough to contain at least the specified number of bytes.

For more information, see [Reading and Writing to Device Registers in UMDF 1.x Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/reading-and-writing-to-device-registers-in-umdf-1-x-drivers).