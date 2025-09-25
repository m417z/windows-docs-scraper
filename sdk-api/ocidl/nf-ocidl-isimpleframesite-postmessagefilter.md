# ISimpleFrameSite::PostMessageFilter

## Description

Sends the simple frame site a message that is received by a control's own window after the control has processed the message.

## Parameters

### `hWnd` [in]

A handle of the control window receiving the message.

### `msg` [in]

The message received by the simple frame site.

### `wp` [in]

The **WPARAM** of the message.

### `lp` [in]

The **LPARAM** of the message.

### `plResult` [out]

 A pointer to the variable that receives the result of the message processing.

### `dwCookie` [in]

The value that was returned by [ISimpleFrameSite::PreMessageFilter](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-isimpleframesite-premessagefilter) through its *pdwCookie* parameter.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The site processed the message. |
| **S_FALSE** | The site did not process the message. |
| **E_NOTIMPL** | The site does not filter any messages. |

## See also

[ISimpleFrameSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-isimpleframesite)