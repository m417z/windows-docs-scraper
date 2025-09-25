# IShellView::SelectItem

## Description

Changes the selection state of one or more items within the Shell view window.

## Parameters

### `pidlItem`

Type: **PCUITEMID_CHILD**

The address of the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

### `uFlags`

Type: **UINT**

One of the [_SVSIF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svsif) constants that specify the type of selection to apply.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

### Notes to Implementers

This method is used to implement the Target command from the **File** menu of the Shell shortcut property sheet.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)