# ITextFont::GetItalic

## Description

Gets whether characters are in italics.

## Parameters

### `pValue`

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Characters are in italics. |
| **tomFalse** | Characters are not in italics. |
| **tomUndefined** | The Italic property is undefined. |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetItalic](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setitalic)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)