# ITextRange::Paste

## Description

Pastes text from a specified data object.

## Parameters

### `pVar`

Type: **VARIANT***

The [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) to paste. However, the contents of the clipboard are used if any of the following are true.

*pVar* is null

*pVar* punkVal is null

*pVar* is not **VT_UNKNOWN**

*pVar* punkVal does not return an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) when queried for one

### `Format`

Type: **long**

The clipboard format to use in the paste operation. Zero is best format, which usually is RTF, but **CF_UNICODETEXT** and other formats are also possible. The default value is zero. For more information, see [Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats).

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Destination is write-protected. |
| **E_OUTOFMEMORY** | Destination cannot contain the text to be pasted. |

## Remarks

For more information, see[ITextRange::Copy](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-copy).

## See also

[Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats)

**Conceptual**

[Copy](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-copy)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)