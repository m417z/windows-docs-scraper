# ITextRange::GetPara

## Description

Gets an [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) object with the paragraph attributes of the specified range.

## Parameters

### `ppPara`

Type: **[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)****

The pointer to the [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If *ppPara* is null, the method fails and it returns E_INVALIDARG.

## Remarks

For plain-text controls, these objects do not vary from range to range, but in rich-text solutions, they do. See the section on [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) for further details.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)