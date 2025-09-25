# SHBindToFolderIDListParent function

## Description

Given a Shell namespace item specified in the form of a folder, and an item identifier list relative to that folder, this function binds to the parent of the namespace item and optionally returns a pointer to the final component of the item identifier list.

## Parameters

### `psfRoot` [in, optional]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to a Shell folder object. If *psfRoot* is **NULL**, indicates that the IDList passed is relative to the desktop.

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A PIDL to bind to, relative to *psfRoot*. If *psfRoot* is **NULL**, this is an absolute IDList relative to the desktop folder.

### `riid` [in]

Type: **REFIID**

Reference to the desired interface ID. This is typically IID_IShellFolder or IID_IShellFolder2, but can be anything supported by the target folder.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) or [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2), but can be anything supported by the target folder.

### `ppidlLast` [out, optional]

Type: **PCUITEMID_CHILD***

A pointer to the last ID of the *pidl* parameter, and is a child ID relative to the parent folder returned in *ppv*. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** Calling the **SHBindToFolderIDListParent** function is equivalent to calling the [SHBindToFolderIDListParentEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbindtofolderidlistparentex) function with **NULL** as the bind context.

## See also

[SHBindToFolderIDListParentEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbindtofolderidlistparentex)