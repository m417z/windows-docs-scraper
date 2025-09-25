# ITfThreadMgrEventSink::OnPopContext

## Description

Called when a context is removed from the context stack

## Parameters

### `pic` [in]

Pointer to the context removed from the stack.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop)

[ITfThreadMgrEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgreventsink)