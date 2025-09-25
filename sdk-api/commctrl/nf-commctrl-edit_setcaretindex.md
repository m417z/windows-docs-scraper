# Edit_SetCaretIndex macro

## Syntax

```cpp
void Edit_SetCaretIndex(
    HWND hwndCtl,
    int newCaretPosition
);
```

## Description

Sets the character index at which to locate the caret. You can use this macro or send the [EM_SETCARETINDEX](https://learn.microsoft.com/windows/desktop/controls/em-setcaretindex) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `newCaretPosition`

The character index.