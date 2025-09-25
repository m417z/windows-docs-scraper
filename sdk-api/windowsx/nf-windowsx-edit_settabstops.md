# Edit_SetTabStops macro

## Syntax

```cpp
void Edit_SetTabStops(
   HWND hwndCtl,
   int  cTabs,
   int  *lpTabs
);
```

## Description

Sets the tab stops in a multiline edit or rich edit control. When text is copied to the control, any tab character in the text causes space to be generated up to the next tab stop. You can use this macro or send the [EM_SETTABSTOPS](https://learn.microsoft.com/windows/desktop/Controls/em-settabstops) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `cTabs`

Type: **int**

The number of tab stops contained in the array. If this parameter is zero, the *lpTabs* parameter is ignored and default tab stops are set at every 32 dialog template units. If this parameter is 1, tab stops are set at every *n* dialog template units, where *n* is the distance pointed to by the *lpTabs* parameter. If this parameter is greater than 1, *lpTabs* is a pointer to an array of tab stops.

### `lpTabs`

Type: **int***

A pointer to an array of unsigned integers specifying the tab stops, in dialog template units. If *cTabs* is 1, this parameter is a pointer to an unsigned integer containing the distance between all tab stops, in dialog template units.

## Remarks

For more information, see [EM_SETTABSTOPS](https://learn.microsoft.com/windows/desktop/Controls/em-settabstops).