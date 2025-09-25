# IShellBrowser::SetStatusTextSB

## Description

Sets and displays status text about the in-place object in the container's frame-window status bar.

## Parameters

### `pszStatusText`

Type: **LPCWSTR**

A pointer to a null-terminated character string that contains the message to display.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is also possible to send messages directly to the status window by using the [IShellBrowser::SendControlMsg](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-sendcontrolmsg) method.

### Notes to Calling Applications

Use this method to set the contents of the status bar.

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)