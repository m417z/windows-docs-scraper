# ITextRange::CanPaste

## Description

Determines if a data object can be pasted, using a specified format, into the current range.

## Parameters

### `pVar`

Type: **VARIANT***

The
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) to be pasted. However, the Clipboard contents are checked for pasting if any of the following are true:

* *pVar* is null
* *pVar*->punkVal is null
* *pVar*->vt is not **VT_UNKNOWN**
* *pVar*->punkVal does not return an
  [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object when queried for one

### `Format`

Type: **long**

Clipboard format that is used. Zero represents the best format, which usually is RTF, but **CF_UNICODETEXT** and other formats are also possible. The default value is zero.

### `pValue`

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that is **tomTrue** only if the data object identified by
*pVar* can be pasted, using the specified format, into the range. This parameter can null.

## Return value

Type: **HRESULT**

The method returns the following COM error codes. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_OK** | The clipboard contents or [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) can be pasted. |
| **S_FALSE** | The clipboard contents or [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) cannot be pasted. |

## See also

**Conceptual**

[Copy](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-copy)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)