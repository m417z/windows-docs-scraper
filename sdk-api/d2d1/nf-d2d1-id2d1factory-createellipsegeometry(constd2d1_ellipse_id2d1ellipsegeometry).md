## Description

Creates an [ID2D1EllipseGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1ellipsegeometry).

## Parameters

### `ellipse`

Type: [in] **const [D2D1_ELLIPSE](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_ellipse)***

A value that describes the center point, x-radius, and y-radius of the ellipse geometry.

### `ellipseGeometry`

Type: [out] **[ID2D1EllipseGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1ellipsegeometry)****

When this method returns, contains the address of the pointer to the ellipse geometry created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)