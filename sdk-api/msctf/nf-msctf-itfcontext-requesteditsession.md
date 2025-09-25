# ITfContext::RequestEditSession

## Description

Obtains access to the document text and properties.

## Parameters

### `tid` [in]

Contains a [TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid) value that identifies the client to establish the edit session with.

### `pes` [in]

Pointer to an [ITfEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfeditsession) interface called to perform the edit session.

### `dwFlags` [in]

Contains one or more of the following values.

| Value | Meaning |
| --- | --- |
| **TF_ES_ASYNCDONTCARE** | The edit session can occur synchronously or asynchronously, at the discretion of the TSF manager. The manager will attempt to schedule a synchronous edit session for improved performance. This value cannot be combined with the TF_ES_ASYNC or TF_ES_SYNC values. |
| **TF_ES_SYNC** | The edit session must be synchronous or the request will fail (with TF_E_SYNCHRONOUS). This flag should only be used in documented situations (such as keystroke handling) where it can be expected to succeed. Otherwise the call will likely fail. This value cannot be combined with the TF_ES_ASYNCDONTCARE or TF_ES_ASYNC values. |
| **TF_ES_READ** | Requests read-only access to the context. |
| **TF_ES_READWRITE** | Requests read/write access to the context. |
| **TF_ES_ASYNC** | The edit session must be asynchronous or the request fails. This value cannot be combined with the TF_ES_ASYNCDONTCARE or TF_ES_SYNC values. |

### `phrSession` [out]

Address of an **HRESULT** value that receives the result of the edit session request. The value received depends upon the type of edit session requested.

* If an asynchronous edit session is requested and can be established, receives TF_S_ASYNC.
* If a synchronous edit session is requested and cannot be established, receives TF_E_SYNCHRONOUS.
* If the TF_ES_READWRITE flag is specified and the document is read-only, receives TS_E_READONLY.
* If a synchronous edit session is established, receives the return value of the [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. *phrSession* contains more result data for the method. |
| **TF_E_LOCKED** | The caller is within the context of another text service which already holds a lock. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

Pending asynchronous edit sessions are processed in the order received. Synchronous edit sessions are processed before any pending asynchronous edit sessions.

A text service can request an edit session within the context of an existing edit session, provided a write access session is not requested within a read-only session. Calls to this method within the context of an edit session established by another text service will fail with TF_E_LOCKED.

A synchronous read/write request will fail if made when processing one of the following notifications.

* [ITfTextEditSink::OnEndEdit](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftexteditsink-onendedit)
* [ITfTextLayoutSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextlayoutsink-onlayoutchange)
* [ITfStatusSink::OnStatusChange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfstatussink-onstatuschange)

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfEditSession interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfeditsession), [ITfStatusSink::OnStatusChange](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfstatussink-onstatuschange), [ITfTextEditSink::OnEndEdit](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itftexteditsink-onendedit), [ITfTextLayoutSink::OnLayoutChange](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itftextlayoutsink-onlayoutchange)