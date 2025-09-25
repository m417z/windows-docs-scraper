# ITfDocumentMgr::GetBase

## Description

Obtains the context at the base of the context stack.

## Parameters

### `ppic` [out]

Address of an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) pointer that receives the context.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppic* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation error occurred. |

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr)

[ITfDocumentMgr::GetTop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-gettop)

[ITfDocumentMgr::Push](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-push)