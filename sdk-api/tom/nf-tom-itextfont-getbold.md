# ITextFont::GetBold

## Description

Gets whether the characters are bold.

## Parameters

### `pValue`

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Characters are bold. |
| **tomFalse** | Characters are not bold. |
| **tomUndefined** | The Bold property is undefined. |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

You can use the [ITextFont::SetWeight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setweight) and [ITextFont::GetWeight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getweight) methods to set or retrieve the font weight more precisely than the [ITextFont::SetBold](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setbold) and **ITextFont::GetBold** methods.

## See also

**Conceptual**

[GetWeight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getweight)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetBold](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setbold)

[SetWeight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setweight)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)