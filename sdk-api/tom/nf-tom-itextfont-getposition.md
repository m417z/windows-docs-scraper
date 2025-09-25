# ITextFont::GetPosition

## Description

Gets the amount that characters are offset vertically relative to the baseline.

## Parameters

### `pValue`

Type: **float***

The amount of vertical offset, in floating-point points.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

Displayed text typically has a zero value for this property. Positive values raise the text, and negative values lower it.

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetPosition](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setposition)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)