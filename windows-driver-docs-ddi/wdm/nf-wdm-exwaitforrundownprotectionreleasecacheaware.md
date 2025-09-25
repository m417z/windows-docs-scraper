## Description

The **ExWaitForRundownProtectionReleaseCacheAware** routine waits until all drivers that have already been granted cache-aware run-down protection complete their accesses of the shared object.

## Parameters

### `RunRef` [in, out]

A pointer to a **EX_RUNDOWN_REF_CACHE_AWARE** structure that was initialized by a previous call to [**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection) or [**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware). The cache-aware run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

## Remarks

This routine is called by the driver that owns an object that resides in shared memory and that is accessed by other drivers. Before deleting this object, the owning driver must call this routine to wait for any outstanding accesses of the object to complete. After **ExWaitForRundownProtectionReleaseCacheAware** returns, the owning driver can safely delete the object.

After **ExWaitForRundownProtectionReleaseCacheAware** is called, the [**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware) routine grants no further requests for cache-aware run-down protection from drivers that are trying to access the shared object.

The routine waits to return until all drivers that were previously granted cache-aware run-down protection finish accessing the object. As each driver finishes, it calls the [**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware) routine to release the previously acquired cache-aware run-down protection. When all outstanding accesses are completed, **ExWaitForRundownProtectionReleaseCacheAware** returns and the object can be safely deleted.

If **ExWaitForRundownProtectionReleaseCacheAware** is called when all drivers that were previously granted run-down protection have already finished accessing the shared object, the routine changes the object status to *run down*, and returns immediately, without waiting.

If **ExWaitForRundownProtectionReleaseCacheAware** is called to run down a shared object, but the *RunRef* parameter indicates that this object is already run down, the call has no effect but is not treated as an error.

For more information, see [Cache-aware run-down protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection#cache-aware-run-down-protection).

## See also

[**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware)

[**ExAcquireRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheawareex)

[**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection)

[**ExFreeCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreecacheawarerundownprotection)

[**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware)

[**ExReInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheawareex)

[**ExRundownCompletedCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exrundowncompletedcacheaware)

[**ExSizeOfRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsizeofrundownprotectioncacheaware)