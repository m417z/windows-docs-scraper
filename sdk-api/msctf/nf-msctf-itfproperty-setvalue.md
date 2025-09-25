# ITfProperty::SetValue

## Description

Sets the value of the property for a range.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the range that the property value is set for. This parameter cannot be **NULL**. This method will fail if *pRange* is empty.

### `pvarValue` [in]

Pointer to a **VARIANT** structure that contains the new property value. Only values of type VT_I4, VT_UNKNOWN, VT_BSTR and VT_EMPTY are supported.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read/write lock. |
| **TF_E_READONLY** | The edit context is read-only. |
| **TF_E_NOTOWNEDRANGE** | The TSF manager does not own the range. |

## Remarks

Property values set with this method will be discarded when the text that the property value covers is modified. To gain custom control over a value response to text edits, use [ITfProperty::SetValueStore](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfproperty-setvaluestore).

Values set with this method are serialized, except for values of type VT_UNKNOWN, which are not serialized. If a property value of type VT_UNKNOWN must be serialized, use **ITfProperty::SetValueStore** instead.

Overlapping property values of the same type are unsupported.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty)

[ITfProperty::SetValueStore](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfproperty-setvaluestore)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)