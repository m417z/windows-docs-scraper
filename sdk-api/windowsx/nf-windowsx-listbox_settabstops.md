# ListBox_SetTabStops macro

## Syntax

```cpp
BOOL ListBox_SetTabStops(
   HWND hwndCtl,
   int  cTabs,
   int  *lpTabs
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If all the specified tabs are set, the return value is **TRUE**; otherwise, it is **FALSE**.

## Description

Sets the tab-stop positions in a list box. You can use this macro or send the [LB_SETTABSTOPS](https://learn.microsoft.com/windows/desktop/Controls/lb-settabstops) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `cTabs`

Type: **int**

The number of elements in the *lpTabs* array.

### `lpTabs`

Type: **int***

A pointer to an array of integers containing the tab stops. The integers represent the number of quarters of the average character width for the font that is selected into the list box. For example, a tab stop of 4 is placed at 1.0 character units, and a tab stop of 6 is placed at 1.5 average character units. However, if the list box is part of a dialog box, the integers are in dialog template units. The tab stops must be sorted in ascending order; backward tabs are not allowed.

## Remarks

For more information, see [LB_SETTABSTOPS](https://learn.microsoft.com/windows/desktop/Controls/lb-settabstops).