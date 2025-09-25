# Edit_GetCaretIndex macro

## Syntax

```cpp
int Edit_GetCaretIndex(
    HWND hwndCtl
);
```

## Return value

Type: **int**

The character index.

## Description

Gets the character index of the caret location for a given edit control. You can use this macro or send the [EM_GETCARETINDEX](https://learn.microsoft.com/windows/desktop/controls/em-getcaretindex) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.