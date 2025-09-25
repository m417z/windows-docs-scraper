# Edit_GetFileLineLength macro

## Syntax

```cpp
UINT Edit_GetFileLineLength(
    HWND hwndCtl,
    UINT characterIndex
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The logical line length, from the specified character index.

## Description

Gets the length of the file (or logical) line of text from the specified character index (text wrap delimiters are ignored). You can use this macro or send the [EM_FILELINELENGTH](https://learn.microsoft.com/windows/desktop/controls/em-filelinelength) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `characterIndex`

The character index. If characterIndex = -1, the caret location index is used, not including the length of any selected text.

## Remarks

The character index is the zero-based index of the character from the beginning of the edit control.

This macro and corresponding message do not recognize text wrapping (visible lines) and, instead, recognize file (logical) lines with an end-of-line delimiter. When text wrap is turned off, visible lines are equivalent to file lines.

The [EM_LINEFROMCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-linefromchar), [EM_LINEINDEX](https://learn.microsoft.com/windows/desktop/controls/em-lineindex), [EM_LINELENGTH](https://learn.microsoft.com/windows/desktop/Controls/em-linelength), [EM_GETLINE](https://learn.microsoft.com/windows/desktop/Controls/em-getline), and [EM_GETLINECOUNT](https://learn.microsoft.com/windows/desktop/Controls/em-getlinecount) messages recognize visible line text wrapping and provide information for the line of text up to the wrapping line break. (Each subsequent line is delimited by the next text wrap break.)