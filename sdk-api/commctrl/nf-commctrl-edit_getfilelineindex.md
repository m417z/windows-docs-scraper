# Edit_GetFileLineIndex macro

## Syntax

```cpp
UINT Edit_GetFileLineIndex(
    HWND hwndCtl,
    UINT lineNumber
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The logical line index.

## Description

Gets the index of the file (or logical) line of text based on the specified visible line. You can use this macro or send the [EM_FILELINEINDEX](https://learn.microsoft.com/windows/desktop/controls/em-filelineindex) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `lineNumber`

The file line number, where the number of the first line is 0. If lineNumber = -1, the file line with the caret is used.

## Remarks

The logical line index is a zero-based index from the beginning of the edit control.

This macro and corresponding message do not recognize text wrapping (visible lines) and, instead, recognize file (logical) lines with an end-of-line delimiter. When text wrap is turned off, visible lines are equivalent to file lines.

The [EM_LINEFROMCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-linefromchar), [EM_LINEINDEX](https://learn.microsoft.com/windows/desktop/controls/em-lineindex), [EM_LINELENGTH](https://learn.microsoft.com/windows/desktop/Controls/em-linelength), [EM_GETLINE](https://learn.microsoft.com/windows/desktop/Controls/em-getline), and [EM_GETLINECOUNT](https://learn.microsoft.com/windows/desktop/Controls/em-getlinecount) messages recognize visible line text wrapping and provide information for the line of text up to the wrapping line break. (Each subsequent line is delimited by the next text wrap break.)