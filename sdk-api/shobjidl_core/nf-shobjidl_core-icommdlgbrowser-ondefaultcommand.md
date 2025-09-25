# ICommDlgBrowser::OnDefaultCommand

## Description

Called when a user double-clicks in the view or presses the ENTER key.

## Parameters

### `ppshv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the view's [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The browser should return S_OK if it has processed the action or S_FALSE to let the view perform the default action.

### Note to Calling Applications

This method allows the default command to be handled by the common dialog box instead of the view.

## See also

[ICommDlgBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icommdlgbrowser)