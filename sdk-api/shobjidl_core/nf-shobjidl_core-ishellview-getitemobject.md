# IShellView::GetItemObject

## Description

Gets an interface that refers to data presented in the view.

## Parameters

### `uItem`

Type: **UINT**

The constants that refer to an aspect of the view. This parameter can be any one of the [_SVGIO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svgio) constants.

### `riid`

Type: **REFIID**

The identifier of the COM interface being requested.

### `ppv`

Type: **LPVOID***

The address that receives the interface pointer. If an error occurs, the pointer returned must be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Used by the common dialog boxes to retrieve the selected items from the view.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)