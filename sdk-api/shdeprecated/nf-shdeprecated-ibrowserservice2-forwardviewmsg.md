# IBrowserService2::ForwardViewMsg

## Description

Deprecated. Calls the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function with a message received by the view, using the **_hwndView** member of the [BASEBROWSERDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-basebrowserdatalh) structure as the **SendMessage** *hWnd* parameter.

## Parameters

### `uMsg` [in]

Type: **UINT**

The message to be sent.

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LRESULT**

The return value specifies the result of the message processing; it depends on the message sent.