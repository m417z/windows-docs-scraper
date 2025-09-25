## Description

The **CcRegisterExternalCacheEx** routine registers an external cache with the cache manager.

## Parameters

### `FileObject`

[in] Pointer to a file object. **FileObject** is used to identify the volume associated with the external cache being registered.

### `Callback`

[in] A caller-implemented [**PEXTERNAL_CACHE_CALLBACK_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pexternal_cache_callback_ex) callback routine that the cache manager will call on every lazy write scan.

### `ExternalCacheContext`

[out] Pointer to the context that identifies the external cache instance.

## Return value

**CcRegisterExternalCacheEx** returns STATUS_SUCCESS if the external cache is successfully registered. Otherwise, it returns an appropriate error code, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_SUPPORTED | The cache manager's per-volume lazywriter isn't enabled. In this case, the caller is expected to fall back on traditional cache management. |

## Remarks

**CcRegisterExternalCacheEx** is the entry point for file systems (clients) to request registration of an external cache with the cache manager. The cache manager allocates an internal structure to represent this instance and add the callback routine provided by the caller. Cache manager will call the callback on every lazy write scan.

## See also

[**CcUpdateExternalCacheInfoEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccupdateexternalcacheinfoex)

[**CcUnregisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunregisterexternalcacheex)