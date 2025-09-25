# Edit_GetFileLine macro

## Syntax

```cpp
void Edit_GetFileLine(
    HWND hwndCtl,
    UINT lineNumber,
    LPSTR textBuffer
);
```

## Description

Gets the text of the specified file (or logical) line (text wrap delimiters are ignored). You can use this macro or send the [EM_GETFILELINE](https://learn.microsoft.com/windows/desktop/controls/em-getfileline) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `lineNumber`

The logical line number.

### `textBuffer`

The buffer that receives the text.

## Remarks

This macro and corresponding message do not recognize text wrapping (visible lines) and, instead, recognize file (logical) lines with an end-of-line delimiter. When text wrap is turned off, visible lines are equivalent to file lines.

The [EM_LINEFROMCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-linefromchar), [EM_LINEINDEX](https://learn.microsoft.com/windows/desktop/controls/em-lineindex), [EM_LINELENGTH](https://learn.microsoft.com/windows/desktop/Controls/em-linelength), [EM_GETLINE](https://learn.microsoft.com/windows/desktop/Controls/em-getline), and [EM_GETLINECOUNT](https://learn.microsoft.com/windows/desktop/Controls/em-getlinecount) messages recognize visible line text wrapping and provide information for the line of text up to the wrapping line break. (Each subsequent line is delimited by the next text wrap break.)