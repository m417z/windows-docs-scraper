# SetWindowOrgEx function

## Description

The **SetWindowOrgEx** function specifies which window point maps to the viewport origin (0,0).

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in logical units, of the new window origin.

### `y` [in]

The y-coordinate, in logical units, of the new window origin.

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the previous origin of the window, in logical units. If *lpPoint* is **NULL**, this parameter is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

This helps define the mapping from the logical coordinate space (also known as a *window*) to the device coordinate space (the *viewport*). **SetWindowOrgEx** specifies which logical point maps to the device point (0,0). It has the effect of shifting the axes so that the logical point (0,0) no longer refers to the upper-left corner.

```cpp

//map the logical point (xWinOrg, yWinOrg) to the device point (0,0)
SetWindowOrgEx (hdc, xWinOrg, yWinOrg, NULL)

```

This is related to the [SetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportorgex) function. Generally, you will use one function or the other, but not both. Regardless of your use of **SetWindowOrgEx** and **SetViewportOrgEx**, the device point (0,0) is always the upper-left corner.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getviewportorgex)

[GetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwindoworgex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[SetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportorgex)