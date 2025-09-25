# TabCtrl_HighlightItem macro

## Syntax

```cpp
BOOL TabCtrl_HighlightItem(
   HWND hwnd,
   INT  i,
   WORD fHighlight
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the highlight state of a tab item. You can use this macro or send the [TCM_HIGHLIGHTITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-highlightitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `i`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of a tab control item.

### `fHighlight`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying the highlight state to be set. If this value is nonzero, the tab is highlighted. If this value is zero, the tab is set to its default state.

## Remarks

In Comctl32.dll version 6.0, this macro has no visible effect when a theme is active.