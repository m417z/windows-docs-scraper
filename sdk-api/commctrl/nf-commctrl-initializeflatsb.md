# InitializeFlatSB function

## Description

Initializes flat scroll bars for a particular window.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that will receive flat scroll bars.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

This function must be called before any other flat scroll bar functions are called. The window will receive flat scroll bars by default. The scroll bar style can be changed with the [FlatSB_SetScrollProp](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-flatsb_setscrollprop) function.

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.