# SHBindToFolderIDListParentEx function

## Description

Extends the [SHBindToFolderIDListParent](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbindtofolderidlistparent) function by allowing the caller to specify a bind context.

## Parameters

### `psfRoot` [in, optional]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to a Shell folder object. If *psfRoot* is **NULL**, indicates that the IDList passed is relative to the desktop.

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A PIDL to bind to, relative to *psfRoot*. If *psfRoot* is **NULL**, this is an absolute IDList relative to the desktop folder.

### `ppbc` [in, optional]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object to be used during this operation. If this parameter is not used, set it to **NULL**, which is equivalent to calling the [SHBindToFolderIDListParent](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbindtofolderidlistparent) function. Because support for *pbc* is optional for folder object implementations, some folders may not support the use of bind contexts.

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

## See also

[SHBindToFolderIDListParent](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbindtofolderidlistparent)