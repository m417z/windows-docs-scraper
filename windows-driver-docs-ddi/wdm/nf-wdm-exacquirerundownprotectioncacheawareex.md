## Description

The **ExAcquireRundownProtectionCacheAwareEx** routine tries to acquire cache-aware run-down protection on a shared object so the caller can safely access the object.

## Parameters

### `RunRefCacheAware` [in, out]

Pointer to the opaque **EX_RUNDOWN_REF_CACHE_AWARE** structure returned by a previous call to [**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection) or [**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware).

### `Count` [in]

The amount by which to increment to the run-down instance count of the object. The count is incremented only if the routine returns **TRUE**. For more information, see Remarks.

## Return value

**ExAcquireRundownProtectionCacheAwareEx** returns **TRUE** if the routine successfully acquires run-down protection for the caller. Otherwise, it returns **FALSE**. A return value of **FALSE** indicates that the run down of the object has started and that the object must be treated as invalid.

## Remarks

The *RunRefCacheAware* parameter points to an **EX_RUNDOWN_REF_CACHE_AWARE** structure that tracks the run-down status of the associated object. This status information includes a count of instances of cache-aware run-down protection that are currently in effect on the object. The **ExAcquireRundownProtectionCacheAwareEx** and [**ExReleaseRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheawareex) routines increment and decrement this count by arbitrary amounts. Two related routines, [**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware) and [**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware), increment and decrement this count by one.

As long as the run-down block itself is nonpaged, this function can be called at DISPATCH_LEVEL.

For more information, see [Cache-aware run-down protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection#cache-aware-run-down-protection).

## See also

[**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware)

[**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection)

[**ExFreeCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreecacheawarerundownprotection)

[**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware)

[**ExReInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheawareex)

[**ExRundownCompletedCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exrundowncompletedcacheaware)

[**ExSizeOfRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsizeofrundownprotectioncacheaware)

[**ExWaitForRundownProtectionReleaseCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionreleasecacheaware)