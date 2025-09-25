# ITextRange::SetChar

## Description

Sets the character at the starting position of the range.

## Parameters

### `Char`

Type: **long**

New value for character at the starting position.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Text is write-protected. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

**ITextRange::SetChar** lets you specify the precise character code to use. However, string literals with similar looking glyphs can be misleading.

The characters set by this method are **LONG** instead of a **BSTR**. This hides the way that they are stored in the backing store, (as bytes, words, variable-length, and so forth).

Frequently on systems that do not have automatic word-wrapping, documents have hard carriage returns inserted just for line breaks. The following code shows a simple, but not perfect, way to convert such hard carriage returns back to blanks for the story that is associated with the range r.

```
    Sub EnableWrap(r As ITextRange)   // Convert false hard CRs to soft
        r.SetRange 0, 0               // r is set at start of story
        While r.Move(tomParagraph)    // Go to start of next paragraph
            If r.MoveWhile(C1_WHITE, 1) = 0 Then    // Next char isn't white space
                r.Move tomCharacter, -1
                r.SetChar = Asc(" ")    // Replace CR by blank
            End If
        Wend        // Loop till no more CRs in story
    End Sub
```

Alternatively, you could use the following inside the IF loop.

```
r.MoveStart tomCharacter, -1        // Select previous char (the CR)
r = " "        // Replace it with a blank
```

This approach enables you to wrap the text to other widths. However, the algorithm isn't perfect: it assumes that a hard carriage return that is followed by anything other than white space (blank, tab, line feed, carriage return, and so forth) should be replaced by a blank. The algorithm also assumes that the carriage return character is a single character like carriage return or the Unicode end-of-paragraph (EOP) 0x2029 character. And, the combination carriage return and line feed isn't matched and would require writing and executing more code (or use `FindText(^p)`). Another caution is that there are other cases, such as mixed code and documentation, where the algorithm does not work correctly.

However, **ITextRange::SetChar** is more efficient than a replace operation that is accomplished by a delete followed by an insertion. Thus, rewriting the code without using **ITextRange::SetChar** would probably be much slower.

The *Char* property, which can do most things that a characters collection can, has two big advantages: it can reference any character in the parent story instead of being limited to the parent range, and it's significantly faster, since **LONG**s rather than range objects are involved. Because of these advantages, the Text Object Model (TOM) does not support a characters collection.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)