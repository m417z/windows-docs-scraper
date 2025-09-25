## Description

This routine initializes a cache-aware rundown protection object.

## Parameters

### `RunRefCacheAware` [out]

Pointer to a caller-supplied buffer where the routine returns an opaque **EX_RUNDOWN_REF_CACHE_AWARE** structure. See Remarks for more information.

### `RunRefSize` [in]

Specifies the size, in bytes, of the rundown protection object.

## Remarks

Rundown protection is a synchronization mechanism used by the Windows kernel to safely clean up resources that might be accessed by multiple threads.

This function is optimized for scenarios where the access patterns to a protected resource are cache-aware, meaning that the same thread is likely to access the resource repeatedly, and different threads are likely to access different parts of the resource. By using this function rather than ExInitializeRundownProtection, a driver can reduce the likelihood of cache contention, where multiple threads compete for the same cache lines, leading to performance degradation.

This function is typically used during the initialization phase of a driver, when it is setting up the resources that it needs to operate. The driver calls this function for each resource that needs to be protected by cache-aware rundown protection.

The **EX_RUNDOWN_REF_CACHE_AWARE** structure is an opaque structure that is used to manage the rundown protection. The caller should first call [**ExSizeOfRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsizeofrundownprotectioncacheaware) to determine the appropriate size for the rundown protection object. This size should then be used to allocate a buffer for the **RunRefCacheAware** parameter and also passed as the **RunRefSize** parameter.

## See also

[**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware)

[**ExAcquireRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheawareex)

[**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection)

[**ExFreeCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreecacheawarerundownprotection)

[**ExReInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheawareex)

[**ExRundownCompletedCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exrundowncompletedcacheaware)

[**ExSizeOfRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsizeofrundownprotectioncacheaware)

[**ExWaitForRundownProtectionReleaseCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionreleasecacheaware)

[Cache-aware run-down protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection#cache-aware-run-down-protection)