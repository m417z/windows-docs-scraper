# PifMgr_CloseProperties function

## Description

[**PifMgr_CloseProperties** is available for use in the

operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Closes application properties that were opened with [PifMgr_OpenProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_openproperties).

## Parameters

### `hProps` [in]

Type: **HANDLE**

A handle to the application's properties. This parameter should be set to the value that is returned by [PifMgr_OpenProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_openproperties).

### `flOpt` [in]

Type: **UINT**

A flag that specifies how the function operates.

#### CLOSEPROPS_DISCARD

Abandon cached data.

#### CLOSEPROPS_NONE

No options specified.

## Return value

Type: **int**

Returns **NULL** if successful. If unsuccessful, the functions returns the handle to the application properties that was passed as *hProps*.

## See also

[PifMgr_GetProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_getproperties)

[PifMgr_SetProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_setproperties)