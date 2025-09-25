# Button_SetDropDownState macro

## Syntax

```cpp
BOOL Button_SetDropDownState(
  [in] HWND hwnd,
  [in] BOOL fDropDown
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the drop down state for a specified button with style of [BS_SPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles). Use this macro or send the [BCM_SETDROPDOWNSTATE](https://learn.microsoft.com/windows/desktop/Controls/bcm-setdropdownstate) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `fDropDown` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** for state of BST_DROPDOWNPUSHED, or **FALSE** otherwise.