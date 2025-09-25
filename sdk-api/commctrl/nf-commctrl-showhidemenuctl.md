# ShowHideMenuCtl function

## Description

[**ShowHideMenuCtl** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Sets or removes the specified menu item's check mark attribute and shows or hides the corresponding control. The function adds a check mark to the specified menu item if it does not have one and then displays the corresponding control. If the menu item already has a check mark, the function removes the check mark and hides the corresponding control.

## Parameters

### `hWnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the menu and controls.

### `uFlags`

Type: **[UINT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The identifier of the menu item to receive or lose a check mark.

### `lpInfo`

Type: **[LPINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to an array that contains pairs of values. The second value in the first pair must be the handle to the application's main menu. Each subsequent pair consists of a menu item identifier and a control window identifier. The function searches the array for a value that matches *uFlags* and, if the value is found, checks or unchecks the menu item and shows or hides the corresponding control.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.