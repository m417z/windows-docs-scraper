# ITextSelection::TypeText

## Description

Types the string given by *bstr* at this selection as if someone typed it. This is similar to the underlying [SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext) method, but is sensitive to the Insert/Overtype key state and UI settings like AutoCorrect and smart quotes.

## Parameters

### `bstr`

Type: **BSTR**

String to type into this selection.

## Return value

Type: **HRESULT**

The method returns an
**HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Text is write-protected. |
| **E_INVALIDARG** | bstr is null. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

This method types the string given by *bstr* at this selection as if someone typed it. Using **TypeText** is faster than sending characters through the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function, but it is slower than using [SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext).

**TypeText** is similar to the underlying [SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext) method, however, it is sensitive to the Insert/Overtype key state and UI settings like AutoCorrect and smart quotes. For example, it deletes any nondegenerate selection and then inserts or overtypes (depending on the Insert/Overtype key state—see the [SetFlags](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-setflags) method) the string *bstr* at the insertion point, leaving this selection as an insertion point following the inserted text.

## See also

**Conceptual**

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

**Other Resources**

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)

[SetFlags](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-setflags)

[SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)