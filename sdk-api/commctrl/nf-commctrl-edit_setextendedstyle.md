# Edit_SetExtendedStyle macro

## Syntax

```cpp
void Edit_SetExtendedStyle(
    HWND hwndCtl,
    DWORD dw,
    DWORD dwMask
);
```

## Description

Sets extended styles for edit controls using the style mask. You can use this macro or send the [EM_SETEXTENDEDSTYLE](https://learn.microsoft.com/windows/desktop/controls/em-setextendedstyle) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `dw`

A [DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) value that specifies the extended edit control styles to set.

### `dwMask`

A [DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) value that specifies which styles are to be affected.