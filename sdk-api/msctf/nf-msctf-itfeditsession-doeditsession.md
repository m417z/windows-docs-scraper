# ITfEditSession::DoEditSession

## Description

Called to enable a text service to read and/or modify the contents of a context.

## Parameters

### `ec` [in]

Contains a [TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie) value that uniquely identifies the edit session. This cookie is used to access the context with methods such as [ITfRange::GetText](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-gettext).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfContext::RequestEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-requesteditsession)

[ITfEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfeditsession)

[ITfRange::GetText](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-gettext)

[TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie)