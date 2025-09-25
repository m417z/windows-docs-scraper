# Edit_ScrollCaret macro

## Syntax

```cpp
BOOL Edit_ScrollCaret(
   HWND hwndCtl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not meaningful.

## Description

Scrolls the caret into view in an edit or rich edit control. You can use this macro or send the [EM_SCROLLCARET](https://learn.microsoft.com/windows/desktop/Controls/em-scrollcaret) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.