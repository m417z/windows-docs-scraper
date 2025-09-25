# IBrowserService2::_SendChildren

## Description

Deprecated. Allows the derived class to send a message through the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function directly instead of relying on the base class.

## Parameters

### `hwndBar` [in]

Type: **HWND**

A handle to the browser window whose window procedure receives the message.

### `fBroadcast` [in]

Type: **BOOL**

The **BOOL** that indicates whether to allow the derived class to broadcast the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function. **TRUE** to allow broadcasting; **FALSE** otherwise.

### `uMsg` [in]

Type: **UINT**

The message to be sent.

### `wParam` [in, out]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in, out]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.