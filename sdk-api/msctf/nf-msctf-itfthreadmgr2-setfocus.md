# ITfThreadMgr2::SetFocus

## Description

Sets the input focus to the specified document manager.

## Parameters

### `pdimFocus` [in]

Pointer to a [ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr) interface that receives the input focus. This parameter cannot be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pdimFocus* is invalid. |

## Remarks

The application must call this method when the document window receives the input focus. If the application associates a window with a document manager using [ITfThreadMgr::AssociateFocus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-associatefocus), the TSF manager calls this method for the application.

## See also

[ITfThreadMgr2](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr2)