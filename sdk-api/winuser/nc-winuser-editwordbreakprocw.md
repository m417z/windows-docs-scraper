# EDITWORDBREAKPROCW callback function

## Description

An application-defined callback function used with the [EM_SETWORDBREAKPROC](https://learn.microsoft.com/windows/desktop/Controls/em-setwordbreakproc) message. A multiline edit control or a rich edit control calls an *EditWordBreakProc* function to break a line of text.

The **EDITWORDBREAKPROC** type defines a pointer to this callback function. *EditWordBreakProc* is a placeholder for the application-defined function name.

## Parameters

### `lpch` [in]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the text of the edit control.

### `ichCurrent` [in]

Type: **int**

An index to a character position in the buffer of text that identifies the point at which the function should begin checking for a word break.

### `cch` [in]

Type: **int**

The number of **TCHARs** in the edit control text. For the ANSI text, this is the number of bytes; for the Unicode text, this is the number of WCHARs.

### `code` [in]

Type: **int**

The action to be taken by the callback function. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WB_CLASSIFY** | Retrieves the character class and word break flags of the character at the specified position. This value is for use with rich edit controls. |
| **WB_ISDELIMITER** | Checks whether the character at the specified position is a delimiter. |
| **WB_LEFT** | Finds the beginning of a word to the left of the specified position. |
| **WB_LEFTBREAK** | Finds the end-of-word delimiter to the left of the specified position. This value is for use with rich edit controls. |
| **WB_MOVEWORDLEFT** | Finds the beginning of a word to the left of the specified position. This value is used during CTRL+LEFT key processing. This value is for use with rich edit controls. |
| **WB_MOVEWORDRIGHT** | Finds the beginning of a word to the right of the specified position. This value is used during CTRL+RIGHT key processing. This value is for use with rich edit controls. |
| **WB_RIGHT** | Finds the beginning of a word to the right of the specified position. This is useful in right-aligned edit controls. |
| **WB_RIGHTBREAK** | Finds the end-of-word delimiter to the right of the specified position. This is useful in right-aligned edit controls. This value is for use with rich edit controls. |

## Return value

Type: **int**

If the
*code* parameter specifies **WB_ISDELIMITER**, the return value is nonzero (TRUE) if the character at the specified position is a delimiter, or zero if it is not. If the
*code* parameter specifies **WB_CLASSIFY**, the return value is the character class and word break flags of the character at the specified position. Otherwise, the return value is an index to the beginning of a word in the buffer of text.

## Remarks

A carriage return followed by a line feed must be treated as a single word by the callback function. Two carriage returns followed by a line feed also must be treated as a single word.

An application must install the callback function by specifying the address of the callback function in an [EM_SETWORDBREAKPROC](https://learn.microsoft.com/windows/desktop/Controls/em-setwordbreakproc) message.

**Rich Edit 1.0:**Microsoft Rich Edit 1.0 only passes back ANSI characters to *EditWordBreakProc*. For rich edit controls, you can alternately use the [EM_SETWORDBREAKPROCEX](https://learn.microsoft.com/windows/desktop/Controls/em-setwordbreakprocex) message to replace the default extended word break procedure with an [EditWordBreakProcEx](https://learn.microsoft.com/windows/desktop/api/richedit/nc-richedit-editwordbreakprocex) callback function. This function provides additional information about the text, such as the character set.

**Rich Edit 2.0 and later:**Microsoft Rich Edit 2.0 and later only pass back Unicode characters to *EditWordBreakProc*. Thus, an ANSI application would convert the Rich Edit-supplied Unicode string using [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte), and then translate the indices appropriately.

> [!NOTE]
> The winuser.h header defines EDITWORDBREAKPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EM_FINDWORDBREAK](https://learn.microsoft.com/windows/desktop/Controls/em-findwordbreak)

[EM_SETWORDBREAKPROC](https://learn.microsoft.com/windows/desktop/Controls/em-setwordbreakproc)

[EM_SETWORDBREAKPROCEX](https://learn.microsoft.com/windows/desktop/Controls/em-setwordbreakprocex)

[EditWordBreakProcEx](https://learn.microsoft.com/windows/desktop/api/richedit/nc-richedit-editwordbreakprocex)

**Other Resources**

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)