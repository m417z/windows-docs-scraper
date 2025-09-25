# Edit_EnableSearchWeb macro

## Syntax

```cpp
BOOL Edit_EnableSearchWeb(
    HWND hwndCtl,
    BOOL enable
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Zero if web search was previously disabled; otherwise nonzero.

## Description

Enables or disables the "Search with Bing…" context menu item in edit controls. You can use this macro or send the [EM_ENABLESEARCHWEB](https://learn.microsoft.com/windows/desktop/controls/em-enablesearchweb) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `enable`

**TRUE** to enable web search, or **FALSE** to disable it.