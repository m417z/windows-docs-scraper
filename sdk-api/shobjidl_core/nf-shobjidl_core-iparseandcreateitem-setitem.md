# IParseAndCreateItem::SetItem

## Description

Sets a Shell item that [SHCreateItemFromParsingName](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromparsingname) created from a parsing name.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IParseAndCreateItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iparseandcreateitem)