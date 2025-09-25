# Pager_RecalcSize macro

## Syntax

```cpp
void Pager_RecalcSize(
   HWND hwnd
);
```

## Description

Forces the pager control to recalculate the size of the contained window. Using this macro will result in a [PGN_CALCSIZE](https://learn.microsoft.com/windows/desktop/Controls/pgn-calcsize) notification being sent. You can use this macro or send the [PGM_RECALCSIZE](https://learn.microsoft.com/windows/desktop/Controls/pgm-recalcsize) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.