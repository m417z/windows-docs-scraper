# ITextRange::SetFont

## Description

Sets this range's character attributes to those of the specified [ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont) object.

## Parameters

### `pFont` [in]

Type: **[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)***

A font object with the desired character format.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_ACCESSDENIED** | Text is protected. |
| **E_INVALIDARG** | *pFont* is null. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

For occasional format changes, use the **ITextRange::SetFont** method. However, to make a number of character formatting changes, it is more efficient to use a font duplicate. This is because every time you execute a statement like `range.font.bold = tomTrue`, a font object is allocated and freed. However, a font duplicate can be allocated once and used many times. Furthermore, you can save the font duplicate, reset it to the default or undefined states with the [Reset](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-reset) method, and give it values as needed for your rich-text processing. For sample code that shows how to use font duplicates, see [Using a Font Duplicate](https://learn.microsoft.com/windows/desktop/Controls/using-the-text-object-model).

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Reset](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-reset)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)