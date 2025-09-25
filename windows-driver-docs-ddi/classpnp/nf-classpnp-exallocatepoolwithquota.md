# ExAllocatePoolWithQuota macro

## Description

The **ExAllocatePoolWithQuota** routine is **obsolete**, and is exported only for existing driver binaries. Use [**ExAllocatePoolWithQuotaTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag) instead.

**ExAllocatePoolWithQuota** allocates pool memory, charging quota against the current process.

## Parameters

### `a`

Specifies the type of pool memory to allocate. For a description of the available pool memory types, see [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type).

You can modify *a* (*PoolType*) by using a bitwise OR with the POOL_COLD_ALLOCATION flag as a hint to the kernel to allocate the memory from pages that are likely to be paged out quickly. To reduce the amount of resident pool memory as much as possible, you should not reference these allocations frequently. The POOL_COLD_ALLOCATION flag is only advisory and is available for Windows XP and later versions of the Windows operating system.

### `b`

Specifies the number of bytes to allocate.

## Syntax

```cpp
PVOID ExAllocatePoolWithQuota(
  _In_ POOL_TYPE a,
  _In_ SIZE_T b
);
```

## Remarks

This routine is called by highest-level drivers that allocate memory to satisfy a request in the context of the process that originally made the I/O request. Lower-level drivers call [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) instead.

If *b* (*NumberOfBytes*) is PAGE_SIZE or greater, a page-aligned buffer is allocated. Quota is *not* charged to the process for allocations of PAGE_SIZE or greater.

Memory allocations of less than PAGE_SIZE are allocated within a page and do not cross page boundaries. Memory allocations of PAGE_SIZE or less are not necessarily page-aligned but are aligned to 8-byte boundaries in 32-bit systems and to 16-byte boundaries in 64-bit systems.

> [!NOTE]
> Do not set *NumberOfBytes* = 0. Avoid zero-length allocations because they waste pool header space and, in many cases, indicate a potential validation issue in the calling code. For this reason, [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) flags such allocations as possible errors.

The system automatically sets certain standard event objects when the amount of pool (paged or nonpaged) is high or low. Drivers can wait for these events to tune their pool usage. For more information, see [Standard Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/standard-event-objects).

> [!NOTE]
> Memory that **ExAllocatePoolWithQuota** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

Callers of **ExAllocatePoolWithQuota** must be executing at IRQL <= DISPATCH_LEVEL. A caller executing at DISPATCH_LEVEL must specify a **NonPaged***Xxx* value for *PoolType*. A caller executing at IRQL <= APC_LEVEL can specify any POOL_TYPE value, but the IRQL and environment must also be considered for determining the pool type.

## See also

[**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[**ExAllocatePoolWithQuotaTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag)

[**ExFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepool)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)