# ITfThreadMgr2::CreateDocumentMgr

## Description

Creates a document manager object.

## Parameters

### `ppdim` [out]

Pointer to an [ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr) interface that receives the document manager object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppdim* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

The caller must release the document manager when it is no longer required.

## See also

[ITfThreadMgr2](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr2)