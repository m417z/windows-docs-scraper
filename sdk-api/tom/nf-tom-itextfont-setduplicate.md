# ITextFont::SetDuplicate

## Description

Sets the character formatting by copying another text font object.

## Parameters

### `pFont` [in]

Type: **[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)***

The text font object to apply to this font object.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

Values with the **tomUndefined** attribute have no effect.

For an example of how to use font duplicates, see [SetFont](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setfont).

## See also

**Conceptual**

[GetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getduplicate)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetFont](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setfont)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)