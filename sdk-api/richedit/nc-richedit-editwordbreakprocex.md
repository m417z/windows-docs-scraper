# EDITWORDBREAKPROCEX callback function

## Description

The *EditWordBreakProcEx* function is an application defined callback function used with the [EM_SETWORDBREAKPROCEX](https://learn.microsoft.com/windows/win32/controls/em-setwordbreakprocex) message. It determines the character index of the word break or the character class and word-break flags of the characters in the specified text. The
**EDITWORDBREAKPROCEX** type defines a pointer to this callback function. *EditWordBreakProcEx* is a placeholder for the application-defined function name.

## Parameters

### `pchText` [in]

Type: **char***

Pointer to the text at the current position. If
*code* specifies movement to the left, the text is in the elements
*pchText*
[–1] through
*pchText* [-*cchText*], and
*pchText*[0] is undefined. For all other actions, the text is in the elements
*pchText*[0] through
*pchText*[
*cchText*–1].

### `cchText` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of characters in the buffer in the direction specified by
*code*.

### `bCharSet` [in]

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character set of the text.

### `action`

#### - code [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Word break action. Can be one of the values described for the
*code* parameter in the [EM_FINDWORDBREAK](https://learn.microsoft.com/windows/win32/controls/em-findwordbreak) message.

## Return value

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The function returns a value based on the
*code* parameter.

| Return code | Description |
| --- | --- |
| **code parameter** | Return value |
| **WB_CLASSIFY** | Returns the character class and word-break flags of the character at the specified position. |
| **WB_ISDELIMITER** | Returns **TRUE** if the character at the specified position is a delimiter or **FALSE** if the character is not. |
| **All other values** | Returns the character index of the word break. |

## Remarks

An application must install the callback function by specifying the address of the callback function in an [EM_SETWORDBREAKPROCEX](https://learn.microsoft.com/windows/win32/controls/em-setwordbreakprocex) message.

For Microsoft Rich Edit 2.0 and later, Rich Edit no longer supports *EditWordBreakProcEx*. Users can send
[EM_SETWORDBREAKPROC](https://learn.microsoft.com/windows/win32/controls/em-setwordbreakproc) to set [EditWordBreakProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-editwordbreakproca), which is now enhanced to support the passing of Unicode text.

## See also

[EM_FINDWORDBREAK](https://learn.microsoft.com/windows/win32/controls/em-findwordbreak)

[EM_SETWORDBREAKPROCEX](https://learn.microsoft.com/windows/win32/controls/em-setwordbreakprocex)

[EditWordBreakProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-editwordbreakproca)

**Reference**