# ITfProperty::Clear

## Description

Empties the property value over the specified range.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the range that the property is cleared for. If this parameter is **NULL**, all values for this property over the entire edit context are cleared.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pRange* is invalid. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read/write lock. |
| **TF_E_READONLY** | The edit context is read-only. |
| **TF_E_NOTOWNEDRANGE** | The TSF manager does not own the range. |

## Remarks

It is not necessary to call this method when a context is about to be destroyed. The TSF manager will clear all properties when the context is removed from the context stack.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)