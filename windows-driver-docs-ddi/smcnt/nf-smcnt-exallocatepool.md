# ExAllocatePool macro (smcnt.h)

## Description

The **ExAllocatePool** routine is **obsolete**, and is exported only for existing binaries. Use **[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)** instead.

**ExAllocatePool** allocates pool memory of the specified type and returns a pointer to the allocated block.

## Parameters

### `a`

Type of pool memory to allocate. For a description of the available pool memory types, see **[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)**.

You can modify *a* by using a bitwise OR with the POOL_COLD_ALLOCATION flag as a hint to the kernel to allocate the memory from pages that are likely to be paged out quickly. To reduce the amount of resident pool memory as much as possible, you should not reference these allocations frequently. The POOL_COLD_ALLOCATION flag is only advisory and is available for Windows XP and later versions of the Windows operating system.

### `b`

Specifies the number of bytes to allocate.

## Syntax

```cpp
#define ExAllocatePool(a,b) ExAllocatePoolWithTag(a,b, SMARTCARD_POOL_TAG)
```

## Remarks

This routine is used for the general pool allocation of memory.

If *b* is PAGE_SIZE or greater, a page-aligned buffer is allocated. Memory allocations of PAGE_SIZE or less do not cross page boundaries. Memory allocations of less than PAGE_SIZE are not necessarily page-aligned but are aligned to 8-byte boundaries in 32-bit systems and to 16-byte boundaries in 64-bit systems.

A successful allocation requesting *b* < PAGE_SIZE of nonpaged pool gives the caller exactly the number of requested bytes of memory. If an allocation request for *b* > PAGE_SIZE succeeds and *b* is not an exact multiple of PAGE_SIZE, the last page in the allocation contains bytes that are not part of the caller's allocation. If possible, the pool allocator uses these bytes. To avoid corrupting data that belongs to other kernel-mode components, drivers must access only storage addresses that they have explicitly allocated.

If **ExAllocatePool** returns **NULL**, the caller should return the NTSTATUS value STATUS_INSUFFICIENT_RESOURCES or should delay processing to another point in time.

Callers of **ExAllocatePool** must be executing at IRQL <= DISPATCH_LEVEL. A caller executing at DISPATCH_LEVEL must specify a **NonPaged***Xxx* value for *a*. A caller executing at IRQL <= APC_LEVEL can specify any POOL_TYPE value, but the IRQL and environment must also be considered for determining the page type.

> [!NOTE]
> Do not set `b = 0`. Avoid zero-length allocations because they waste pool header space and, in many cases, indicate a potential validation issue in the calling code. For this reason, [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) flags such allocations as possible errors.

The system automatically sets certain standard event objects when the amount of pool (paged or nonpaged) is high or low. Drivers can wait for these events to tune their pool usage. For more information, see [Standard Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/standard-event-objects).

> [!NOTE]
> Memory that **ExAllocatePool** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

## See also

- [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)
- [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepool)
- [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)