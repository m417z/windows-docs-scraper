# ITfThreadMgr::GetFocus

## Description

Returns the document manager that has the input focus.

## Parameters

### `ppdimFocus` [out]

Pointer to a [ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr) interface that receives the document manager with the current input focus. Receives **NULL** if no document manager has the focus.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | No document manager has focus. *ppdimFocus* be set to **NULL**. |
| **E_INVALIDARG** | *ppdimFocus* is invalid. |

## See also

[ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)

[ITfThreadMgr::AssociateFocus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-associatefocus)

[ITfThreadMgr::SetFocus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-setfocus)