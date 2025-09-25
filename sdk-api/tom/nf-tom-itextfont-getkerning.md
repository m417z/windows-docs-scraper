# ITextFont::GetKerning

## Description

Gets the minimum font size at which kerning occurs.

## Parameters

### `pValue`

Type: **float***

The minimum font size at which kerning occurs, in floating-point points.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

If the value pointed to by
*pValue* is zero, kerning is off. Positive values turn on pair kerning for font point sizes greater than or equal to the kerning value. For example, the value 1 turns on kerning for all legible sizes, whereas 16 turns on kerning only for font sizes of 16 points and larger.

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetKerning](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setkerning)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)