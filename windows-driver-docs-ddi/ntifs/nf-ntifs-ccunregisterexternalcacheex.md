## Description

**CcUnregisterExternalCacheEx** routine unregisters an external cache with the cache manager.

## Parameters

### `ExternalCacheContext`

[in] Pointer to the context that identifies the external cache to be unregistered. This context was returned by [**CcRegisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccregisterexternalcacheex).

## Remarks

After a client (file system) unregisters an external cache, it will no longer receive any callbacks from the cache manager during lazy write scans.

## See also

[**CcRegisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccregisterexternalcacheex)