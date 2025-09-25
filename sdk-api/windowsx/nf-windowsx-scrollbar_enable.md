# ScrollBar_Enable macro

## Syntax

```cpp
BOOL ScrollBar_Enable(
   HWND hwndCtl,
   UINT flags
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the arrows are enabled or disabled as specified, the return value is nonzero.

## Description

Enables or disables a scroll bar control.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that specify the arrows affected and whether they are enabled or disabled. See the *wArrows* parameter of [EnableScrollBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablescrollbar) for more information.

## Remarks

The macro expands to a call to [EnableScrollBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablescrollbar) with SB_CTL in the *wSBFlags* parameter.