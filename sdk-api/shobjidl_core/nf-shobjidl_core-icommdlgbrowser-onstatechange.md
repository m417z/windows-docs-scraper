# ICommDlgBrowser::OnStateChange

## Description

Called after a state, identified by the *uChange* parameter, has changed in the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface.

## Parameters

### `ppshv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the view's [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface.

### `uChange`

Type: **ULONG**

Change in the selection state. This parameter can be one of the following values.

#### CDBOSC_SETFOCUS

The focus has been set to the view.

#### CDBOSC_KILLFOCUS

The view has lost the focus.

#### CDBOSC_SELCHANGE

The selection has changed.

#### CDBOSC_RENAME

An item has been renamed.

#### CDBOSC_STATECHANGE

An item has been checked or unchecked.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used to let the common file dialog boxes track the state of the view and change its user interface as needed.

### Note to Calling Applications

When items in the view are selected, or when the view loses the focus, it needs to call this method to notify the common dialog that either the view state or selection state is changing.

## See also

[ICommDlgBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icommdlgbrowser)