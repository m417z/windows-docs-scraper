# ITfThreadMgrEventSink::OnUninitDocumentMgr

## Description

Called when the last context is removed from the context stack

## Parameters

### `pdim` [in]

Pointer to the document manager object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop)

[ITfThreadMgrEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgreventsink)