## Description

The **ExSizeOfRundownProtectionCacheAware** routine returns recommended size for a cache-friendly rundown structure.

## Return value

Returns a **SIZE_T** value.

## Remarks

After calling this routine, call [**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware) to initialize a cache-aware rundown protection object.

## See also

[Cache-aware run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection#cache-aware-run-down-protection)

[**ExAcquireRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheaware)

[**ExAcquireRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectioncacheawareex)

[**ExAllocateCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatecacheawarerundownprotection)

[**ExFreeCacheAwareRundownProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreecacheawarerundownprotection)

[**ExInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotectioncacheaware)

[**ExReInitializeRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheaware)

[**ExReleaseRundownProtectionCacheAwareEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectioncacheawareex)

[**ExRundownCompletedCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exrundowncompletedcacheaware)

[**ExWaitForRundownProtectionReleaseCacheAware**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionreleasecacheaware)