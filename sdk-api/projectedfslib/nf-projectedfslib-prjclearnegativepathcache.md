# PrjClearNegativePathCache function

## Description

Purges the virtualization instance's negative path cache, if it is active.

## Parameters

### `namespaceVirtualizationContext` [in]

Opaque handle for the virtualization instance.

### `totalEntryNumber` [out, optional]

Optional pointer to a variable that receives the number of paths that were in the cache before it was purged.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the negative path cache is active, then if the provider indicates that a file path does not exist by returning HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) from its [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback, ProjFS will fail subsequent opens of that path without calling the [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback again. This helps improve performance of virtualization instances that host workloads that frequently probe for the presence of a file by trying to open it.

To resume receiving the [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback for paths the provider has indicated do not exist, the provider must call this routine.