# SHBindToObject function

## Description

Retrieves and binds to a specified object by using the Shell namespace [IShellFolder::BindToObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-bindtoobject) method.

## Parameters

### `psf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder). This parameter can be **NULL**. If *psf* is **NULL**, this indicates
parameter *pidl* is relative to the desktop. In this case, *pidl* must specify an absolute [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist).

### `pidl`

Type: **PCUIDLIST_RELATIVE**

A pointer to a constant [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) to bind to that is relative to *psf*. If *psf* is **NULL**, this is an absolute **ITEMIDLIST** relative to the desktop folder.

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object to be used during this operation. If this parameter is not used, set it to **NULL**. Because support for *pbc* is optional for folder object implementations, some folders may not support the use of bind contexts.

### `riid`

Type: **REFIID**

Identifier of the interface to return.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer as specified in *riid* to the bound object. If an error occurs, contains a **NULL** pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** This is a helper function that gets the desktop object by calling [SHGetDesktopFolder](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetdesktopfolder).

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder::BindToObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-bindtoobject)