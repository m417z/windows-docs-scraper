# ITfReadOnlyProperty::GetValue

## Description

Obtains the value of the property for a range of text.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that specifies the range to obtain the property for.

### `pvarValue` [out]

Pointer to a **VARIANT** value that receives the property value. The data type and contents of this value is defined by the property owner and must be recognized by the caller in order to use this value. The caller must release this data, when it is no longer required, by passing this value to the **VariantClear** API.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The range is not covered by the property or the range contains more than one property value. *pvarValue* receives a VT_EMPTY value. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_FAIL** | An unspecified error occurred. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read-only or read/write lock. |

## Remarks

If the property has no value over *pRange*, *pRange* contains more than one value for the property or the property does not completely cover *pRange*, *pvarValue* receives a VT_EMPTY value and the method returns S_FALSE.

``` syntax

COLOR:      RR      GGGGGGGG
TEXT:  this is some colored text
    range-->||<-

```

``` syntax

COLOR:      RR      GGGGGGGG
TEXT:  this is some colored text
    range-->|    |<-

```

``` syntax

COLOR:      RR      GGGGGGGG
TEXT:  this is some colored text
    range-->|             |<-

```

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfReadOnlyProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreadonlyproperty)