# DrawShadowText function

## Description

Draws text that has a shadow.

## Parameters

### `hdc`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC.

### `pszText`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a string that contains the text to be drawn.

### `cch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **UINT** that specifies the number of characters in the string that is to be drawn.

### `prc`

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains, in logical coordinates, the rectangle in which the text is to be drawn.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **DWORD** that specifies how the text is to be drawn. See [Format Values](https://learn.microsoft.com/windows/desktop/Controls/theme-format-values) for possible parameter values.

### `crText`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure that contains the color of the text.

### `crShadow`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure that contains the color of the text shadow.

### `ixOffset`

Type: **int**

A value of type **int** that specifies the x-coordinate of where the text should begin.

### `iyOffset`

Type: **int**

A value of type **int** that specifies the y-coordinate of where the text should begin.

## Return value

Type: **int**

Returns the height of the text in logical units if the function succeeds, otherwise returns zero.

## Remarks

To use **DrawShadowText**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).