# ITextRange::Copy

## Description

Copies the text to a data object.

## Parameters

### `pVar`

Type: **VARIANT***

The copied text.
*pVar*->ppunkVal is the out parameter for an
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) provided that the following conditions exist:

* pVar->vt = (VT_UNKNOWN | VT_BYREF)
* pVar is not null
* pVar->ppunkVal is not null

Otherwise, the clipboard is used.

## Return value

Type: **HRESULT**

This method returns an
**HRESULT** value. If successful, it returns **S_OK**. Otherwise, it returns **E_OUTOFMEMORY**.

## Remarks

The [ITextRange::Cut](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-cut),
**ITextRange::Copy**, and [ITextRange::Paste](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-paste) methods let you perform the usual
**Cut**, **Copy**, and
**Paste** operations on a range object using an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject), thereby not changing the contents of the clipboard. Among clipboard formats typically supported are **CF_TEXT** and **CF_RTF**. In addition, private clipboard formats can be used to reference a text solution's own internal rich text formats.

To copy and replace plain text, you can use the [ITextRange::GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext)
 and [ITextRange::SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext)
 methods. To copy formatted text from range r1 to range r2 without using the clipboard, you can use **Copy** and
**Paste** and also the [ITextRange::GetFormattedText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getformattedtext) and [ITextRange::SetFormattedText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setformattedtext) methods, as shown in the following Microsoft Visual Basic example:

`r2.GetFormattedText = r1.GetFormattedText`

## See also

**Conceptual**

[Cut](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-cut)

[GetFormattedText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getformattedtext)

[GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Paste](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-paste)

**Reference**

[SetFormattedText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setformattedtext)

[SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)