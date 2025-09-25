# ITfThreadMgrEventSink::OnSetFocus

## Description

Called when a document view receives or loses the focus

## Parameters

### `pdimFocus` [in]

Pointer to the document manager receiving the input focus. If no document is receiving the focus, this will be **NULL**.

### `pdimPrevFocus` [in]

Pointer to the document manager that previously had the input focus. If no document had the focus, this will be **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITfThreadMgr::SetFocus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-setfocus)

[ITfThreadMgrEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgreventsink)