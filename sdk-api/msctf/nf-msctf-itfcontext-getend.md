# ITfContext::GetEnd

## Description

Obtains a range of text positioned at the end of the document.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit session. This is the value passed to [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `ppEnd` [out]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface pointer that receives an empty range positioned at the end of the document.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_NOLOCK** | The cookie in *ec* is invalid. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_NOTIMPL** | The context owner does not implement this method. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange)