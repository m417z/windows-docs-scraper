# ITfDocumentMgr::EnumContexts

## Description

Obtains a context enumerator.

## Parameters

### `ppEnum` [out]

Address of an [IEnumTfContexts](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfcontexts) pointer that receives the enumerator.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation error occurred. |
| **E_FAIL** | The enumerator cannot be initialized. |

## See also

[IEnumTfContexts](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfcontexts)

[ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr)