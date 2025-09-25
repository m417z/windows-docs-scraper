# SHCreateItemFromRelativeName function

## Description

Creates and initializes a Shell item object from a relative parsing name.

## Parameters

### `psiParent` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the parent Shell item.

### `pszName` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode string that specifies a display name that is relative to the *psiParent*.

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to a bind context that controls the parsing operation. This parameter can be **NULL**.

### `riid` [in]

Type: **REFIID**

A reference to an interface ID.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in riid. This will usually be [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or
[IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.