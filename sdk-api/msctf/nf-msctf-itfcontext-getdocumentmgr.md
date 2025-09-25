# ITfContext::GetDocumentMgr

## Description

Obtains the document manager that contains the context.

## Parameters

### `ppDm` [out]

Pointer to an [ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr) interface pointer that receives the document manager.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The context is not contained in any document manager. *ppDm* is set to **NULL**. |
| **E_INVALIDARG** | *ppDm* is invalid. |

## Remarks

If the context is not contained within a document manager, this method returns S_FALSE and *ppDm* is set to **NULL**. This occurs when the context is removed from the context stack through a call to [ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop).

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfDocumentMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdocumentmgr), [ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfdocumentmgr-pop)