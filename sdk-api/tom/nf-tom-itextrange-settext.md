# ITextRange::SetText

## Description

Sets the text in this range.

## Parameters

### `bstr` [in]

Type: **BSTR**

Text that replaces the current text in this range. If null, the current text is deleted.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Text is write-protected. |
| **E_INVALIDARG** | bstr is null. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

**ITextRange::SetText** replaces the text in the range with the new text. In contrast, [TypeText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-typetext) replaces the selection with the text *bstr* and leaves the selection as an insertion point just following the inserted text, just as if you had typed the text in. For UI selection behavior, see **TypeText**.

If, after you call **ITextRange::SetText**, you call [ITextRange::GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext), you get back the same text that you set with the **ITextRange::SetText** method (unless some other range has changed that text in between the calls).

## See also

**Conceptual**

[GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)

[TypeText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-typetext)