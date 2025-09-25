## Description

A file system calls **CcUpdateExternalCacheInfoEx** to ask the cache manager (*Cc*) to update dirty page statistics in the specified external cache information structure.

## Parameters

### `ExternalCacheContext`

[in] Pointer to the context that identifies the external cache structure to be updated. This context was returned by [**CcRegisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccregisterexternalcacheex).

### `DirtyPagesInfo`

[in] Pointer to a [**CC_DIRTY_PAGES_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-cc_dirty_pages_info) structure that contains updated information about dirty page statistics. *Cc* ignores the dirty page thresholds part of this structure.

## Return value

**CcUpdateExternalCacheInfoEx** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate error code such as the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_INVALID_PARAMETER | The version in **DirtyPagesInfo** is invalid. |

## Remarks

*Cc* needs these updated values so it can accurately set the dirty page threshold and target.

## See also

[**CcRegisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccregisterexternalcacheex)

[**CC_DIRTY_PAGES_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-cc_dirty_pages_info)