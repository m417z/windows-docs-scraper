# ITextRange::GetFont

## Description

Gets an [ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont) object with the character attributes of the specified range.

## Parameters

### `ppFont`

Type: **[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)****

The pointer to an [ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont) object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If *ppFont* is null, the method fails and it returns E_INVALIDARG.

## Remarks

For plain-text controls, these objects do not vary from range to range, but in rich-text solutions, they do. See the section on [ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont) for further details.

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)