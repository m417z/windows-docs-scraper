# Pager_SetChild macro

## Syntax

```cpp
void Pager_SetChild(
   HWND hwnd,
   HWND hwndChild
);
```

## Description

Sets the contained window for the pager control. This macro will not change the parent of the contained window; it only assigns a window handle to the pager control for scrolling. In most cases, the contained window will be a child window. If this is the case, the contained window should be a child of the pager control. You can use this macro or send the [PGM_SETCHILD](https://learn.microsoft.com/windows/desktop/Controls/pgm-setchild) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `hwndChild`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the window to be contained.