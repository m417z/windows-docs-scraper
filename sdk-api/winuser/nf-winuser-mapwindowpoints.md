# MapWindowPoints function

## Description

The **MapWindowPoints** function converts (maps) a set of points from a coordinate space relative to one window to a coordinate space relative to another window.

## Parameters

### `hWndFrom` [in]

A handle to the window from which points are converted. If this parameter is **NULL** or HWND_DESKTOP, the points are presumed to be in screen coordinates.

### `hWndTo` [in]

A handle to the window to which points are converted. If this parameter is **NULL** or HWND_DESKTOP, the points are converted to screen coordinates.

### `lpPoints` [in, out]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that contain the set of points to be converted. The points are in device units. This parameter can also point to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure, in which case the *cPoints* parameter should be set to 2.

### `cPoints` [in]

The number of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures in the array pointed to by the *lpPoints* parameter.

## Return value

If the function succeeds, the low-order word of the return value is the number of pixels added to the horizontal coordinate of each source point in order to compute the horizontal coordinate of each destination point. (In addition to that, if precisely one of *hWndFrom* and *hWndTo* is mirrored, then each resulting horizontal coordinate is multiplied by -1.) The high-order word is the number of pixels added to the vertical coordinate of each source point in order to compute the vertical coordinate of each destination point.

If the function fails, the return value is zero. Call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) prior to calling this method to differentiate an error return value from a legitimate "0" return value.

## Remarks

If *hWndFrom* or *hWndTo* (or both) are mirrored windows (that is, have **WS_EX_LAYOUTRTL** extended style) and precisely two points are passed in *lpPoints*, **MapWindowPoints** will interpret those two points as a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) and possibly automatically swap the left and right fields of that rectangle to ensure that left is not greater than right. If any number of points other than 2 is passed in *lpPoints*, then **MapWindowPoints** will correctly map the coordinates of each of those points separately, so if you pass in a pointer to an array of more than one rectangle in *lpPoints*, the new rectangles may get their left field greater than right. Thus, to guarantee the correct transformation of rectangle coordinates, you must call **MapWindowPoints** with one **RECT** pointer at a time, as shown in the following example:

```cpp

   RECT        rc[10];

   for(int i = 0; i < (sizeof(rc)/sizeof(rc[0])); i++)
   {
       MapWindowPoints(hWnd1, hWnd2, (LPPOINT)(&rc[i]), (sizeof(RECT)/sizeof(POINT)) );
   }

```

Also, if you need to map precisely two independent points and don't want the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) logic applied to them by **MapWindowPoints**, to guarantee the correct result you must call **MapWindowPoints** with one [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) pointer at a time, as shown in the following example:

```cpp

   POINT pt[2];

   MapWindowPoints(hWnd1, hWnd2, &pt[0], 1);
   MapWindowPoints(hWnd1, hWnd2, &pt[1], 1);

```

## See also

[ClientToScreen](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clienttoscreen)

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[ScreenToClient](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-screentoclient)