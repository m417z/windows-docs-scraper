## Description

> [!CAUTION]
> Microsoft is aware of an issue with ExAllocatePoolZero that can lead to an allocation not getting zeroed on Windows 10, version 1909. This issue has been fixed in a security refresh of the WDK for Windows 10, version 2004 and the Enterprise WDK (EWDK) for Windows 10, version 2004 on December 16th, 2020. For information on downloading the latest WDK, see [Download the Windows Driver Kit (WDK)](https://learn.microsoft.com/windows-hardware/drivers/download-the-wdk).

This routine is a wrapper for and a recommended replacement option for [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

ExAllocatePoolZero allocates pool memory of the specified type and returns a pointer to the allocated block. It is identical to [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) except it zero initializes the allocated memory.

## Parameters

### `PoolType`

The type of pool memory to allocate. For a description of the available pool memory types, see [**POOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type).

You can modify the enumeration value by performing a bitwise-OR with the POOL_RAISE_IF_ALLOCATION_FAILURE flag defined in `wdm.h`. This flag causes an exception to be raised if the request cannot be satisfied. Use of this flag is not recommended because it is costly.

Similarly, you can modify the *PoolType* value by bitwise-ORing this value with the POOL_COLD_ALLOCATION flag (also defined in `wdm.h`) as a hint to the kernel to allocate the memory from pages that are likely to be paged out quickly. To reduce the amount of resident pool memory as much as possible, you should not reference these allocations frequently. The POOL_COLD_ALLOCATION flag is only advisory.

### `NumberOfBytes`

The number of bytes to allocate.

### `Tag`

The pool tag to use for the allocated memory. Specify the pool tag as a non-zero character literal of one to four characters delimited by single quotation marks (for example, `Tag1`). The string is usually specified in reverse order (for example, `1gaT`). Each ASCII character in the tag must be a value in the range 0x20 (space) to 0x7E (tilde). Each allocation code path should use a unique pool tag to help debuggers and verifiers identify the code path.

## Return value

ExAllocatePoolZero returns **NULL** if there is insufficient memory in the free pool to satisfy the request. Otherwise, the routine returns a pointer to the allocated memory.

## Remarks

This routine is used for the general pool allocation of memory.

To run on versions of Windows prior to Windows 10 version 2004, the driver must define POOL_ZERO_DOWN_LEVEL_SUPPORT and call [ExInitializeDriverRuntime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializedriverruntime) before calling this function.

The only difference between this function and [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) is that memory is zero initialized. If this is not desired, use [ExAllocatePoolUninitialized](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepooluninitialized) instead, which is a wrapper for ExAllocatePoolWithTag.

A driver should only access memory within the byte range that it allocates. Accessing memory outside this range may corrupt the pool and cause the system to crash.

See the Remarks section of [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) for additional guidance.

## See also

[ExAllocatePoolUninitialized](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepooluninitialized)