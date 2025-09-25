# TreeView_SetAutoScrollInfo macro

## Syntax

```cpp
LRESULT TreeView_SetAutoScrollInfo(
   HWND hwnd,
   UINT uPixPerSec,
   UINT uUpdateTime
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE**.

## Description

Sets information used to determine auto-scroll characteristics. Use this macro or send the [TVM_SETAUTOSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/tvm-setautoscrollinfo) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `uPixPerSec`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies pixels per second. The offset to scroll is divided by the *uPixPerSec* to determine the total duration of the auto-scroll.

### `uUpdateTime`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the redraw time interval. Redraw at every elapsed interval, until the item is scrolled into view. Given *uPixPerSec*, the location of the item is calculated and a repaint occurs. Set this value to create smooth scrolling.

## Remarks

Autoscroll information is used to scroll a nonvisible item into view. The control must have the [TVS_EX_AUTOHSCROLL](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) extended style. For information on extended styles, see Tree-View Control Extended Styles.