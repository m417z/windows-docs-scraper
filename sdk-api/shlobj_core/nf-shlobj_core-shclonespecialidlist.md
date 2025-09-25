# SHCloneSpecialIDList function

## Description

[**SHCloneSpecialIDList** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [SHGetSpecialFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderlocation).]

Retrieves a pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that specifies a special folder.

## Parameters

### `hwnd`

Type: **HWND**

Reserved.

### `csidl` [in]

Type: **int**

A [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value that identifies the folder of interest.

### `fCreate` [in]

Type: **BOOL**

A value of type **BOOL** that indicates if the folder should be created if it does not already exist. If *fCreate* is **TRUE**, the folder is created. If it is **FALSE**, the folder is not created.

## Return value

Type: **PIDLIST_ABSOLUTE**

Returns a pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure of a special folder specified by *csidl*. The function creates the folder if *fCreate* is **TRUE**.

## Remarks

When finished, you should free the pointer to the cloned folder with [ILFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilfree).