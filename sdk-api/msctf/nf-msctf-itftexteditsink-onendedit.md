# ITfTextEditSink::OnEndEdit

## Description

Receives a notification upon completion of an ITfEditSession::DoEditSession method that has read/write access to the context.

## Parameters

### `pic` [in]

Pointer to the [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface for the edited context.

### `ecReadOnly` [in]

Specifies a [TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie) value for read-only access to the context.

### `pEditRecord` [in]

Pointer to the [ITfEditRecord](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfeditrecord) interface used to access the modifications to the context.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An edit session with read/write access is requested with a call to the [ITfContext::RequestEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-requesteditsession) method using the TF_ES_READWRITE flag, which establishes an **ITfEditSession::DoEditSession** method to perform the session. When such a **ITfEditSession::DoEditSession** method completes, TSF calls this method.

A text service can use the *ecReadOnly* parameter only to view the context. If changes are required, the text service must use an asynchronous call to the **ITfContext::RequestEditSession** method. However, a text service should modify only text that it previously entered as part of a composition. Otherwise, two or more text services could repeatedly modify the same text. A text service can use the [ITfContext::InWriteSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-inwritesession) method to determine if it performed the completed edit session.

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfContext::InWriteSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-inwritesession)

[ITfContext::RequestEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-requesteditsession)

[ITfEditRecord](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfeditrecord)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfTextEditSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itftexteditsink)

[TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie)