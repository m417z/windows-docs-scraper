# ITfProperty::SetValueStore

## Description

Sets the value of the property for a range of text using a property store object.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the range that the property value is set for. This parameter cannot be **NULL**. This method fails if *pRange* is empty.

### `pPropStore` [in]

Pointer to an [ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore) interface that obtains the property data.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_FAIL** | An unspecified error occurred. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read/write lock. |

## Remarks

Property values set with [ITfProperty::SetValue](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfproperty-setvalue) will be discarded when the text that the property value covers is modified. To gain control over what happens to a property value when the text is modified, use **ITfProperty::SetValueStore** .

Values set with **ITfProperty::SetValue** will be serialized, except for values of type VT_UNKNOWN, which are not serialized. If a property value of type VT_UNKNOWN must be serialized, use **ITfProperty::SetValueStore** instead.

Overlapping property values of the same type are unsupported.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty)

[ITfProperty::SetValue](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfproperty-setvalue)

[ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)