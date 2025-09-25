## Description

The **ExAllocateCacheAwareRundownProtection** routine allocates a cache-friendly rundown protection structure for multi-processor scenarios. Rundown protection is a synchronization mechanism that allows for the safe cleanup of resources that might be accessed by multiple threads.

## Parameters

### `PoolType` [in]

The type of pool memory to allocate. For a description of the available pool memory types, see [**POOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type).

### `PoolTag` [in]

A ULONG that specifies the pool tag for the memory allocation. The pool tag is a 32-bit value that is used to track memory usage.

## Return value

Returns a pointer to an opaque **EX_RUNDOWN_REF_CACHE_AWARE** structure or NULL if allocation fails.

## Remarks

A driver can call **ExAllocateCacheAwareRundownProtection** as an alternative to calling [**ExSizeOfRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsizeofrundownprotectioncacheaware) followed by [**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware).

For more info, see [Cache-aware run-down protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection#cache-aware-run-down-protection).

## See also

[**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware)

[**ExAcquireRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheawareex)

[**ExFreeCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreecacheawarerundownprotection)

[**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware)

[**ExReInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheawareex)

[**ExRundownCompletedCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exrundowncompletedcacheaware)

[**ExSizeOfRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsizeofrundownprotectioncacheaware)

[**ExWaitForRundownProtectionReleaseCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionreleasecacheaware)