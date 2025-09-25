# Edit_GetExtendedStyle macro

## Syntax

```cpp
DWORD Edit_GetExtendedStyle(
    HWND hwndCtl
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that represents the styles currently in use for a given edit control.

## Description

Gets the extended styles that are currently in use for a given edit control. You can use this macro or send the [EM_GETEXTENDEDSTYLE](https://learn.microsoft.com/windows/desktop/controls/em-getextendedstyle) message explicitly.

## Parameters

### `hwndCtl`

A handle to a list-view control.