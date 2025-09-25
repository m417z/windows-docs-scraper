## Description

> [!CAUTION]
> Microsoft is aware of an issue with ExAllocatePoolQuotaZero that can lead to an allocation not getting zeroed on Windows 10, version 1909.This issue has been fixed in a security refresh of the WDK for Windows 10, version 2004 and the Enterprise WDK (EWDK) for Windows 10, version 2004 on December 16th, 2020. For information on downloading the latest WDK, see [Download the Windows Driver Kit (WDK)](https://learn.microsoft.com/windows-hardware/drivers/download-the-wdk).

This routine is a wrapper for and a recommended replacement option for [ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag).

ExAllocatePoolQuotaZero allocates pool memory of the specified type and returns a pointer to the allocated block. It is identical to [ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag) except it zero initializes the allocated memory. If this is not desired, use [ExAllocatePoolQuotaUninitialized](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolquotauninitialized) instead.

## Parameters

### `PoolType`

The type of pool memory to allocate. For a description of the available pool memory types, see [**POOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type).

Similarly, you can modify the *PoolType* value by bitwise-ORing this value with the POOL_COLD_ALLOCATION flag (also defined in `wdm.h`) as a hint to the kernel to allocate the memory from pages that are likely to be paged out quickly. To reduce the amount of resident pool memory as much as possible, you should not reference these allocations frequently. The POOL_COLD_ALLOCATION flag is only advisory.

### `NumberOfBytes`

The number of bytes to allocate.

### `Tag`

The pool tag to use for the allocated memory. Specify the pool tag as a non-zero character literal of one to four characters delimited by single quotation marks (for example, `Tag1`). The string is usually specified in reverse order (for example, `1gaT`). Each ASCII character in the tag must be a value in the range 0x20 (space) to 0x7E (tilde). Each allocation code path should use a unique pool tag to help debuggers and verifiers identify the code path.

## Return value

ExAllocatePoolQuotaZero returns a pointer to the allocated pool.

If the request cannot be satisfied, ExAllocatePoolQuotaZero raises an exception unless POOL_QUOTA_FAIL_INSTEAD_OF_RAISE is specified. Using POOL_QUOTA_FAIL_INSTEAD_OF_RAISE is preferred for performance reasons.

## Remarks

To run on versions of Windows prior to Windows 10 version 2004, the driver must define POOL_ZERO_DOWN_LEVEL_SUPPORT and call [ExInitializeDriverRuntime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializedriverruntime) before calling this function.

This routine is called by highest-level drivers that allocate memory to satisfy a request in the context of the process that originally made the I/O request. Lower-level drivers call [ExAllocatePoolZero](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolzero) instead.

See the Remarks section of [ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag) for additional guidance.

## See also

[ExAllocatePoolQuotaUninitialized](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolquotauninitialized)