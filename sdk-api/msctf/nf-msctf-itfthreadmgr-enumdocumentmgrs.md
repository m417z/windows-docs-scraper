# ITfThreadMgr::EnumDocumentMgrs

## Description

Returns an enumerator for all the document managers within the calling thread.

## Parameters

### `ppEnum` [out]

Pointer to a [IEnumTfDocumentMgrs](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfdocumentmgrs) interface that receives the enumerator.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The caller must release the enumerator when it is no longer required.

## See also

[IEnumTfDocumentMgrs](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfdocumentmgrs)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)