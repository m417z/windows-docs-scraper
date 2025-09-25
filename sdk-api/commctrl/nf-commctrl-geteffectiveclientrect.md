# GetEffectiveClientRect function

## Description

Calculates the dimensions of a rectangle in the client area that contains all the specified controls.

## Parameters

### `hWnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that has the client area to check.

### `lprc`

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the dimensions of the rectangle.

### `lpInfo` [in]

Type: **const [INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a null-terminated array of integers that identify controls in the client area. Each control requires a pair of consecutive elements. The first element of the pair must be nonzero and the second element of the pair must be the control identifier. The first pair represents the menu and is ignored. The last element must be zero to identify the end of the array.

## Remarks

If a window in the *lprc* array is visible, or will be visible when its parent becomes visible, its rectangle is subtracted from the effective client rectangle.

## See also

[ShowHideMenuCtl](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-showhidemenuctl)