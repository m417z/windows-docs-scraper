## Description

The **ExRundownCompletedCacheAware** routine updates the run-down status of a shared object to indicate that the run down of the object has completed.

## Parameters

### `RunRefCacheAware` [in, out]

Pointer to the rundown protection object that the function will operate on. This is a pointer to an opaque **EX_RUNDOWN_REF_CACHE_AWARE** structure returned by a previous call to [**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection) or [**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware).

## Remarks

This routine is called by the driver that owns an object that resides in shared memory and that is accessed by other drivers. The **ExRundownCompletedCacheAware** call must be preceded by a call to the [**ExWaitForRundownProtectionReleaseCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionreleasecacheaware) routine that runs down the object.

After an **ExRundownCompletedCacheAware** call, additional calls to [**ExWaitForRundownProtectionReleaseCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionreleasecacheaware) to run down the associated object return immediately without waiting. However, calls to [**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware) to acquire run-down protection on the associated object fail (return **FALSE**).

After an **ExRundownCompletedCacheAware** call, the driver can call the [**ExReInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotectioncacheaware) routine to associate the **EX_RUNDOWN_REF_CACHE_AWARE** structure with a new object and to initialize run-down protection on this object. After the **ExReInitializeRundownProtection** call, drivers can call [**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware) to acquire run-down protection on the new object.

On entry, the status information in the **EX_RUNDOWN_REF_CACHE_AWARE** structure must indicate that the object that was associated with this structure was run down.

## See also

[Cache-aware run-down protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection#cache-aware-run-down-protection)

[**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware)

[**ExAcquireRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheawareex)

[**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection)

[**ExFreeCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreecacheawarerundownprotection)

[**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware)

[**ExReInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheawareex)

[**ExSizeOfRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsizeofrundownprotectioncacheaware)

[**ExWaitForRundownProtectionReleaseCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionreleasecacheaware)