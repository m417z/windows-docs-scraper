# ISimpleFrameSite::PreMessageFilter

## Description

Provides a site with the opportunity to process a message that is received by a control's own window before the control itself does any processing.

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

### `pdwCookie` [out]

A pointer to the variable that will be passed to [ISimpleFrameSite::PostMessageFilter](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-isimpleframesite-postmessagefilter) if it is called later. This parameter should only contain allocated data if this method returns S_OK so it will also receive a call to **PostMessageFilter** which can free the allocation. The caller is not in any way responsible for anything returned in this parameter.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The simple frame site will not use the message in this filter so more processing can take place. |
| **S_FALSE** | The site has processed the message and no further processing should occur. |
| **E_NOTIMPL** | The site does not do any message filtering, indicating that PostMessageFilter need not be called later. |
| **E_POINTER** | The address in *plResult* or *pdwCookie* is not valid. |

## Remarks

Successful return values indicate whether the site wishes to allow further processing. S_OK indicates further processing, whereas S_FALSE means do not process further. S_OK also indicates that the control must later call [PostMessageFilter](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-isimpleframesite-postmessagefilter).

## See also

[ISimpleFrameSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-isimpleframesite)