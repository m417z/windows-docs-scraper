# ILCloneFirst function

## Description

Clones the first [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure in an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that you want to clone.

## Return value

Type: **PITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that contains the first [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure from the **ITEMIDLIST** structure specified by *pidl*. Returns **NULL** on failure.

## See also

[ILClone](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilclone)