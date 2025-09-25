# ITextFont::SetStyle

## Description

Sets the character style handle of the characters in a range.

## Parameters

### `Value` [in]

Type: **long**

The new character style handle.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

The Text Object Model (TOM) version 1.0 does not specify the meanings of the style handles. The meanings depend on other facilities of the text system that implements TOM.

## See also

**Conceptual**

[GetStyle](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getstyle)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)