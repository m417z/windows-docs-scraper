# IShellBrowser::SendControlMsg

## Description

Sends control messages to either the toolbar or the status bar in a Windows Explorer window.

## Parameters

### `id`

Type: **UINT**

An identifier for either a toolbar (**FCW_TOOLBAR**) or for a status bar window (**FCW_STATUS**).

### `uMsg`

Type: **UINT**

The message to be sent to the control.

### `wParam`

Type: **WPARAM**

The value depends on the message specified in the *uMsg* parameter.

### `lParam`

Type: **LPARAM**

The value depends on the message specified in the *uMsg* parameter.

### `pret`

Type: **LRESULT***

The address of the return value of the
[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or a COM-defined error value otherwise.

## Remarks

Refer to the [Common Controls](https://learn.microsoft.com/windows/desktop/Controls/common-controls-intro) documentation for more information on the messages that can be sent to the toolbar or status bar control.

### Notes to Calling Applications

Use of this call requires diligent attention, because leaving either the status bar or toolbar in an inappropriate state will affect the performance of Windows Explorer.

### Notes to Implementers

If your Windows Explorer does not have these controls, you can return **E_NOTIMPL**.

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)