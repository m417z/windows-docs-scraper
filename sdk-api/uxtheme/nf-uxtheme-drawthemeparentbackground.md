# DrawThemeParentBackground function

## Description

Draws the part of a parent control that is covered by a partially-transparent or alpha-blended child control.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The child control.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The child control's DC.

### `prc` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

The area to be drawn. The rectangle is in the child window's coordinates. If this parameter is NULL, the area to be drawn includes the entire area occupied by the child control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.