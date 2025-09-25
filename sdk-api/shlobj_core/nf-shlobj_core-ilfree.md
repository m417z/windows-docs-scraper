# ILFree function

## Description

Frees an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure allocated by the Shell.

## Parameters

### `pidl` [in]

Type: **PIDLIST_RELATIVE**

A pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure to be freed. This parameter can be **NULL**.

## Remarks

**ILFree** is often used with [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures allocated by one of the other IL functions, but it can be used to free any such structure returned by the Shell—for example, the **ITEMIDLIST** structure returned by [SHBrowseForFolder](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbrowseforfoldera) or used in a call to [SHGetFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderlocation).

**Note** When using Windows 2000 or later, use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) rather than **ILFree**. [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures are always allocated with the Component Object Model (COM) task allocator on those platforms.

## See also

[ILAppendID](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilappendid)

[ILClone](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilclone)

[ILCloneFirst](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilclonefirst)

[ILCombine](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilcombine)