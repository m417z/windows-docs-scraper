# ITextFont::GetSpacing

## Description

Gets the amount of horizontal spacing between characters.

## Parameters

### `pValue`

Type: **float***

The amount of horizontal spacing between characters, in floating-point points.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

Displayed text typically has an intercharacter spacing value of zero. Positive values expand the spacing, and negative values compress it.

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetSpacing](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setspacing)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)