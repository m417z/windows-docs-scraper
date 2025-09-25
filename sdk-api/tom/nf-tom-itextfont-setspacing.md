# ITextFont::SetSpacing

## Description

Sets the amount of horizontal spacing between characters.

## Parameters

### `Value` [in]

Type: **float**

The new amount of horizontal spacing between characters, in floating-point points.

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

Displayed text typically has an intercharacter spacing value of zero. Positive values expand the spacing, and negative values compress it.

## See also

**Conceptual**

[GetSpacing](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getspacing)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)