# ComboBox_ShowDropdown macro

## Syntax

```cpp
BOOL ComboBox_ShowDropdown(
   HWND hwndCtl,
   BOOL fShow
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Always returns **TRUE**.

## Description

Shows or hides the list in a combo box. You can use this macro or send the [CB_SHOWDROPDOWN](https://learn.microsoft.com/windows/desktop/Controls/cb-showdropdown) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fShow`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to show the dropdown, or **FALSE** to hide it.

## Remarks

This macro has no effect on a combo box created with the [CBS_SIMPLE](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style.