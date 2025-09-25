# ITextRange::GetText

## Description

Gets the plain text in this range. The Text property is the default property of the [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) interface.

## Parameters

### `pbstr`

Type: **BSTR***

The text.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pbstr* is null. |
| **E_OUTOFMEMORY** | Insufficient memory to hold the text. |

## Remarks

The **ITextRange::GetText** method returns the plain text in the range. The Text property is the default property for [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange); this is, it is automatically invoked for a range, as in the following Microsoft Visual Basic for Applications (VBA) example.

`print range`

Some of the examples below use this fact. The [ITextRange::SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext) method substitutes *bstr* for the range text. For processing a single character, the Char property is more efficient than the Text property and does not require creating a single character range for storing a character. If the range is degenerate, the Text property lets you insert text easily. You can also delete the text in a range, as shown in the following VBA examples.

`range.delete`

`range = ""`

You can use the **Text** property to copy plain text from one place to another, simply by setting one range equal to another. (This is quite different from the **Duplicate** property; for more information, see [ITextRange::GetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getduplicate)). The following Microsoft Visual Basic example statement
sets the text in the range1 to that in range2.

`range1 = range2 ' Replace range1's text by range2's`

The ranges can be in different stories or even in different applications. However, they do imply copying the text first into a **BSTR** and then from that string to the target location. For large amounts of text, the [ITextRange::Copy](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-copy) and [ITextRange::Paste](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-paste) methods can be faster, since they can perform the copy directly from source to target and with any format supported by the source and target.

The text returned by the Text property is given in Unicode. The end-of-paragraph mark may be given by 0x2029 (the Unicode Paragraph Separator), or by carriage return/line feed (CR/LF) (0xd, 0xa), or by a carriage return alone, depending on the original file. Microsoft Word uses a carriage return alone, unless it reads another choice in from a file, the clipboard, or an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject). The placeholder for an embedded object is given by the special character, **WCH_EMBEDDING**, which has the Unicode value 0xFFFC.

## See also

**Conceptual**

[Copy](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-copy)

[GetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getduplicate)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Paste](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-paste)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)