## Description

The **ExAllocatePool2** routine allocates pool memory of the specified type and returns a pointer to the allocated block.

## Parameters

### `Flags`

A ULONG64-typed value specifying the type of pool memory along with required and optional attributes. Multiple flag values can be combined using bit-wise OR. See [**POOL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/pool_flags) for possible values.

### `NumberOfBytes`

Specifies a non-zero number of bytes to allocate.

### `Tag`

The pool tag to use for the allocated memory. Specify the pool tag as a non-zero character literal of one to four characters delimited by single quotation marks (for example, `Tag1`). The string is usually specified in reverse order (for example, `1gaT`). Each ASCII character in the tag must be a value in the range 0x20 (space) to 0x7E (tilde). Each allocation code path should use a unique pool tag to help debuggers and verifiers identify the code path.

## Return value

**ExAllocatePool2** returns a pointer to the allocated memory.

The following conditions cause the function to return NULL by default. If **POOL_FLAG_RAISE_ON_FAILURE** is specified, the function raises an exception.

- Insufficient memory
- **Tag** is set to 0 or invalid POOL_FLAGS are specified

## Remarks

If you are building a driver that targets versions of Windows prior to Windows 10, version 2004, use [**ExAllocatePoolZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolzero), [**ExAllocatePoolUninitialized**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepooluninitialized), [**ExAllocatePoolQuotaZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolquotazero), or [**ExAllocatePoolQuotaUninitialized**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolquotauninitialized).

This routine has the following differences from the earlier allocation routines (**ExAllocatePoolWithTag**, **ExAllocatePoolWithQuotaTag**, **ExAllocatePoolWithTagPriority**):

1. Memory is zero initialized unless **POOL_FLAG_UNINITIALIZED** is specified.

1. Return behavior in the event of unsuccessful allocation. **ExAllocatePoolWithQuotaTag** raises an exception by default.

1. Tags with a value of 0 are invalid.

When replacing [**ExAllocatePoolWithQuotaTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag) with **ExAllocatePool2**, you must specify the **POOL_FLAG_USE_QUOTA** flag. For more info about pool flags, see [POOL_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/kernel/pool_flags).

If **NumberOfBytes** is `PAGE_SIZE` or greater, a page-aligned buffer is allocated. Memory allocations of `PAGE_SIZE` or less are allocated within a page and do not cross page boundaries. Memory allocations of less than `PAGE_SIZE` are not necessarily page-aligned but are aligned to 8-byte boundaries in 32-bit systems and to 16-byte boundaries in 64-bit systems.

Drivers may only use up to the **NumberOfBytes** they have explicitly allocated. Accessing memory outside of this range may corrupt the pool and cause the system to crash.

The system associates the pool tag with the allocated memory. Programming tools, such as WinDbg, can display the pool tag associated with each allocated buffer. Gflags, a tool included in Debugging Tools for Windows, turns on a system feature that requests allocation from special pool for a particular pool tag. Poolmon, which is included in the WDK, tracks memory by pool tag.

The value of Tag is stored, and sometimes displayed, in reverse (little-endian) order. For example, if a caller passes `Fred` as a Tag, it appears as `derF` in a pool dump and in pool usage tracking in the debugger, and as `0x64657246` in the registry and in tool displays.

The allocated buffer can be freed with either **ExFreePool** or **ExFreePoolWithTag**.

Callers of **ExAllocatePool2** must be running at IRQL <= DISPATCH_LEVEL. A caller executing at DISPATCH_LEVEL must specify **POOL_FLAG_NON_PAGED** or **POOL_FLAG_NON_PAGED_EXECUTABLE** for **Flags**. A caller executing at IRQL <= APC_LEVEL can specify **POOL_FLAG_PAGED**, but if the memory will be accessed from code running at DISPATCH_LEVEL, you must still allocate non-paged memory.

In a non-uniform memory access (NUMA) multiprocessor architecture, **ExAllocatePool2** attempts to allocate memory that is local to the processor that is calling **ExAllocatePool2**. If no local memory is available, **ExAllocatePool2** allocates the closest available memory.

Memory that **ExAllocatePool2** allocates is zero initialized. Kernel-mode drivers should not opt-out of zeroing for allocations that will be copied to an untrusted location (user-mode, over the network, etc.) to avoid disclosing sensitive information.

## See also

[ExAllocatePool3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool3)