# _POOL_TYPE enumeration

## Description

The **POOL_TYPE** enumeration type specifies the type of system memory to allocate.

## Syntax

```cpp
typedef enum _POOL_TYPE {
    NonPagedPool,
    NonPagedPoolExecute = NonPagedPool,
    PagedPool,
    NonPagedPoolMustSucceed = NonPagedPool + 2,
    DontUseThisType,
    NonPagedPoolCacheAligned = NonPagedPool + 4,
    PagedPoolCacheAligned,
    NonPagedPoolCacheAlignedMustS = NonPagedPool + 6,
    MaxPoolType,
    NonPagedPoolBase = 0,
    NonPagedPoolBaseMustSucceed = NonPagedPoolBase + 2,
    NonPagedPoolBaseCacheAligned = NonPagedPoolBase + 4,
    NonPagedPoolBaseCacheAlignedMustS = NonPagedPoolBase + 6,
    NonPagedPoolSession = 32,
    PagedPoolSession = NonPagedPoolSession + 1,
    NonPagedPoolMustSucceedSession = PagedPoolSession + 1,
    DontUseThisTypeSession = NonPagedPoolMustSucceedSession + 1,
    NonPagedPoolCacheAlignedSession = DontUseThisTypeSession + 1,
    PagedPoolCacheAlignedSession = NonPagedPoolCacheAlignedSession + 1,
    NonPagedPoolCacheAlignedMustSSession = PagedPoolCacheAlignedSession + 1,
    NonPagedPoolNx = 512,
    NonPagedPoolNxCacheAligned = NonPagedPoolNx + 4,
    NonPagedPoolSessionNx = NonPagedPoolNx + 32,

} POOL_TYPE;
```

## Constants

### `NonPagedPool`

*Nonpaged pool*, which is nonpageable system memory. Nonpaged pool can be accessed from any IRQL, but it is a scarce resource and drivers should allocate it only when necessary.

System memory allocated with the **NonPagedPool** pool type is executable. For more information, see the description of the **NonPagedPoolExecute** pool type.

Starting with Windows 8, drivers should allocate most or all of their nonpaged memory from the no-execute (NX) nonpaged pool instead of the executable nonpaged pool. For more information, see the description of the **NonPagedPoolNx** pool type.

### `NonPagedPoolExecute`

Starting with Windows 8, **NonPagedPoolExecute** is an alternate name for the **NonPagedPool** value. This value indicates that the allocated memory is to be nonpaged and executable—that is, instruction execution is enabled in this memory. To port a driver from an earlier version of Windows, you should typically replace all or most instances of the **NonPagedPool** name in the driver source code with **NonPagedPoolNx**. Avoid replacing instances of the **NonPagedPool** name with **NonPagedPoolExecute** except in cases in which executable memory is explicitly required. For more information, see [No-Execute (NX) Nonpaged Pool](https://learn.microsoft.com/windows-hardware/drivers/kernel/no-execute-nonpaged-pool).

### `PagedPool`

*Paged pool*, which is pageable system memory. Paged pool can only be allocated and accessed at IRQL < DISPATCH_LEVEL.

### `NonPagedPoolMustSucceed`

This value is for internal use only, and is allowed only during system startup. Drivers must not specify this value at times other than system startup, because a "must succeed" request crashes the system if the requested memory size is unavailable.

### `DontUseThisType`

Reserved for system use.

### `NonPagedPoolCacheAligned`

Nonpaged pool, aligned on processor cache boundaries. This value is for internal use only.

### `PagedPoolCacheAligned`

Paged pool, aligned on processor cache boundaries. This value is for internal use only.

### `NonPagedPoolCacheAlignedMustS`

This value is for internal use only, and is allowed only during system startup. It is the cache-aligned equivalent of **NonPagedPoolMustSucceed**.

### `MaxPoolType`

Reserved for system use.

### `NonPagedPoolBase`

Reserved for system use.

### `NonPagedPoolBaseMustSucceed`

Reserved for system use.

### `NonPagedPoolBaseCacheAligned`

Reserved for system use.

### `NonPagedPoolBaseCacheAlignedMustS`

Reserved for system use.

### `NonPagedPoolSession`

Deprecated. Do not use.

### `PagedPoolSession`

Deprecated. Do not use.

### `NonPagedPoolMustSucceedSession`

Deprecated. Do not use.

### `DontUseThisTypeSession`

Deprecated. Do not use.

### `NonPagedPoolCacheAlignedSession`

Deprecated. Do not use.

### `PagedPoolCacheAlignedSession`

Deprecated. Do not use.

### `NonPagedPoolCacheAlignedMustSSession`

Deprecated. Do not use.

### `NonPagedPoolNx`

*No-execute* (NX) nonpaged pool. This pool type is available starting with Windows 8. In contrast to the nonpaged pool designated by **NonPagedPool**, which allocates executable memory, the NX nonpaged pool allocates memory in which instruction execution is disabled. For more information, see [No-Execute (NX) Nonpaged Pool](https://learn.microsoft.com/windows-hardware/drivers/kernel/no-execute-nonpaged-pool).

Nonpaged pool can be accessed from any IRQL, but it is a scarce resource and drivers should allocate it only when necessary.

### `NonPagedPoolNxCacheAligned`

NX nonpaged pool, aligned on processor cache boundaries. This value is reserved for exclusive use by the operating system.

### `NonPagedPoolSessionNx`

Reserved for exclusive use by the operating system.

## See also

[ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExAllocatePoolWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtagpriority)

[ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex)

[ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist)

[ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist)

[LookasideListAllocateEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-allocate_function_ex)

[SeAssignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)

[SeAssignSecurityEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurityex)