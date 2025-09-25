# ITextFont::SetKerning

## Description

Sets the minimum font size at which kerning occurs.

## Parameters

### `Value` [in]

Type: **float**

The new value of the minimum kerning size, in floating-point points.

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

If this value is zero, kerning is turned off. Positive values turn on pair kerning for font sizes greater than this kerning value. For example, the value 1 turns on kerning for all legible sizes, whereas 16 turns on kerning only for font sizes of 16 points and larger.

## See also

**Conceptual**

[GetKerning](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getkerning)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)