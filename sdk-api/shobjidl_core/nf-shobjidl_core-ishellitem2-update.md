# IShellItem2::Update

## Description

Ensures that any cached information in this item is updated.

## Parameters

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including ERROR_FILE_NOT_FOUND if the item does not exist.