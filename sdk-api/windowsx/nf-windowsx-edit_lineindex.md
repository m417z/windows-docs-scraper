# Edit_LineIndex macro

## Syntax

```cpp
int Edit_LineIndex(
   HWND hwndCtl,
   int  line
);
```

## Return value

Type: **int**

The character index of the first character in the line, or –1 if the specified line number is greater than the number of lines in the edit control.

## Description

Gets the character index of the first character of a specified line in a multiline edit or rich edit control. You can use this macro or send the [EM_LINEINDEX](https://learn.microsoft.com/windows/desktop/controls/em-lineindex) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `line`

Type: **int**

The zero-based line number. A value of –1 specifies the current line number (the line that contains the caret).