# ITextRange::FindText

## Description

Searches up to *Count* characters for the text given by *bstr*. The starting position and direction are also specified by *Count*, and the matching criteria are given by *Flags*.

## Parameters

### `bstr`

Type: **BSTR**

String to find.

### `Count`

Type: **long**

Maximum number of characters to search. It can be one of the following.

|  |  |
| --- | --- |
| *tomForward* | Searches to the end of the story. This is the default value. |
| *n* (greater than 0) | Searches forward for *n* chars, starting from *cpFirst.* If the range itself matches *bstr*, another search is attempted from *cpFirst* + 1. |
| *n*(less than 0) | Searches backward for *n* chars, starting from *cpLim.* If the range itself matches *bstr*, another search is attempted from *cpLim*– 1. |
| 0 (degenerate range) | Search begins after the range. |
| 0 (nondegenerate range) | Search is limited to the range. |

In all cases, if a string is found, the range limits are changed to be those of the matched string and *pLength* is set equal to the length of the string. If the string is not found, the range remains unchanged and *pLength* is set equal to zero.

### `Flags`

Type: **long**

Flags governing comparisons. It can be 0 (the default) or any combination of the following values.

|  |  |  |
| --- | --- | --- |
| *tomMatchWord* | 2 | Matches whole words. |
| *tomMatchCase* | 4 | Matches case. |
| *tomMatchPattern* | 8 | Matches regular expressions. |

### `pLength`

Type: **long***

The length of string matched.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns S_FALSE. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

The **ITextRange::FindText** method can also match special characters by using a caret (^) followed by a special letter. For a list of special characters, see the Special list available in the Microsoft Word
**Find and Replace** dialog box. For example, `^p` matches the next paragraph mark. Note, `^c` can be used to represent the Clipboard contents in the string to be replaced. Thus, using `^c` in the find string enables you to search for rich text. For more details, see the Word Help files.

As a comparison with the **ITextRange::FindText** method, the [ITextRange::FindTextStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtextstart) method searches forward or backward from the range's Start
*cp*, and the [ITextRange::FindTextEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtextend) method searches forward or backward from the range's End
*cp*. For more details, see the descriptions of these methods.

The following are several code snippets that show the **ITextRange::FindText** methods.

Example #1. The following Microsoft Visual Basic for Applications (VBA) program prints all the /* ... */ comments in a story identified by the range r.

```
Sub PrintComments (r As ITextRange)
    r.SetRange 0, 0                                      'r = insertion pt at start of story
    Do While r.FindText("/*") And r.FindTextEnd("*/")    'Select comment
        r.MoveStart tomCharacter, 2                      'But do not include the opening or
                                                         'closing comment brackets
        r.MoveEnd tomCharacter, -2
        Print r                                          'Show the folks
    Loop
End Sub
```

Instead of these comments being printed, they could be inserted into another edit instance and saved to a file, or they could be inserted into separate cells in a table or spreadsheet.

To print all lines containing one or more occurrences of the word "laser", replace the loop by the following code:

```
    While r.FindText("laser")            // Select next occurrence of "laser"
        r.Expand tomLine                // Select enclosing line
        Print r                    // Print the line
    Wend
```

Example #2. The following program prints a telephone list, given a story that contains an address list. The address list entries are separated by two or more paragraph marks, and each entry has the following form.

```
Person/Business Name
Address (one or more lines)
(area code) telephone number
```

Note the use of the character `^p` in the **FindText** string argument to locate a pair of consecutive paragraph marks.

```
Sub PrintTelephoneList (r As ITextRange)
    r.SetRange 0, 0                 // r = insertion point at start of story
    r.MoveWhile C1_WHITE            // Bypass any initial white space
    Do
        r.EndOf tomParagraph, 1     // Select next para (line): has name
        Print r                    // Print it
        Do
            r.MoveWhile C1_SPACE        // Bypass possible space chars
            If r.Char = Asc("(") Then Exit Do    // Look for start of telephone #
        Loop While r.Move(tomParagraph)    // Go to next paragraph
        r.EndOf tomParagraph, 1        // Select line with telephone number
        Print r                    // Print it
    Loop While r.FindText("^p^p")        // Find two consecutive para marks
End Sub
```

Example #3. The following subroutine replaces all occurrences of the string, str1, in a range by str2:

```
Sub Replace ( tr As ITextRange, str1 As String, str2 As String )
    Dim r As ITextRange
    r = tr.Duplicate                // Copy tr parameters to r
    r.End = r.Start                    // Convert to insertion point at Start
    While r.FindText(str1, tr.End - r.End)        // Match next occurrence of str
        r = str2                // Replace it with rep
    Wend                        // Iterate till no more matches
End Sub
```

Example #4. The following line of code inserts a blank before the first occurrence of a right parenthesis, "(", that follows an occurrence of HRESULT.

```
    If r.FindText("HRESULT") And r.FindText("(") Then r = " ("
```

To do this for all such occurrences, change the If into a While/Wend loop in the above line of code. This an example of a **FIND/REPLACE** macro that cannot be run with **Find and Replace** dialog boxes.

## See also

**Conceptual**

[FindTextEnd](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtextend)

[FindTextStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtextstart)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)