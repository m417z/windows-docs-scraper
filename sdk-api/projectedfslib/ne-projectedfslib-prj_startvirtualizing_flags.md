# PRJ_STARTVIRTUALIZING_FLAGS enumeration

## Description

Flags to provide when starting a virtualization instance.

## Constants

### `PRJ_FLAG_NONE:0x00000000`

No flags.

### `PRJ_FLAG_USE_NEGATIVE_PATH_CACHE:0x00000001`

Specifies that ProjFS should maintain a "negative path cache" for the virtualization instance. If the negative path cache is active, then if the provider indicates that a file path does not exist by returning HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) from its [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback, ProjFS will fail subsequent opens of that path without calling the [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback again.

To resume receiving the [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) for paths the provider has indicated do not exist, the provider must call [PrjClearNegativePathCache](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjclearnegativepathcache).