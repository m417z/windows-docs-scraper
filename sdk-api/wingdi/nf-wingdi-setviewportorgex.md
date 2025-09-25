# SetViewportOrgEx function

## Description

The **SetViewportOrgEx** function specifies which device point maps to the window origin (0,0).

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in device units, of the new viewport origin.

### `y` [in]

The y-coordinate, in device units, of the new viewport origin.

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the previous viewport origin, in device coordinates. If *lpPoint* is **NULL**, this parameter is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

This function (along with [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) and [SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex)) helps define the mapping from the logical coordinate space (also known as a *window*) to the device coordinate space (the *viewport*). **SetViewportOrgEx** specifies which device point maps to the logical point (0,0). It has the effect of shifting the axes so that the logical point (0,0) no longer refers to the upper-left corner.

```cpp

//map the logical point (0,0) to the device point (xViewOrg, yViewOrg)
SetViewportOrgEx ( hdc, xViewOrg, yViewOrg, NULL)

```

This is related to the [SetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindoworgex) function. Generally, you will use one function or the other, but not both. Regardless of your use of **SetWindowOrgEx** and **SetViewportOrgEx**, the device point (0,0) is always the upper-left corner.

#### Examples

For an example, see [Redrawing in the Update Region](https://learn.microsoft.com/windows/desktop/gdi/redrawing-in-the-update-region).

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getviewportorgex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[SetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindoworgex)