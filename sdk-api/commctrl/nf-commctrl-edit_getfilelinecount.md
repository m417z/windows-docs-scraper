# Edit_GetFileLineCount macro

## Syntax

```cpp
void Edit_GetFileLineCount(
    HWND hwndCtl
);
```

## Description

Gets the number of file (or logical) lines (text wrap delimiters are ignored). You can use this macro or send the [EM_GETFILELINECOUNT](https://learn.microsoft.com/windows/desktop/controls/em-getfilelinecount) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

## Remarks

This macro and corresponding message do not recognize text wrapping (visible lines) and, instead, recognize file (logical) lines with an end-of-line delimiter. When text wrap is turned off, visible lines are equivalent to file lines.

The [EM_LINEFROMCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-linefromchar), [EM_LINEINDEX](https://learn.microsoft.com/windows/desktop/controls/em-lineindex), [EM_LINELENGTH](https://learn.microsoft.com/windows/desktop/Controls/em-linelength), [EM_GETLINE](https://learn.microsoft.com/windows/desktop/Controls/em-getline), and [EM_GETLINECOUNT](https://learn.microsoft.com/windows/desktop/Controls/em-getlinecount) messages recognize visible line text wrapping and provide information for the line of text up to the wrapping line break. (Each subsequent line is delimited by the next text wrap break.)