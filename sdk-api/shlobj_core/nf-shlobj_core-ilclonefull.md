# ILCloneFull function

## Description

Clones a full, or absolute, [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_ABSOLUTE**

A pointer to the full, or absolute, [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure to be cloned.

## Return value

Type: **PIDLIST_ABSOLUTE**

A pointer to a copy of the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure pointed to by *pidl*.

## Remarks

When you are finished with the cloned [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure, release it with [ILFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilfree) to avoid memory leaks.