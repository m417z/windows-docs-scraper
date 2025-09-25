## Description

Creates an [ID2D1RectangleGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rectanglegeometry).

## Parameters

### `rectangle`

Type: [in] **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)***

The coordinates of the rectangle geometry.

### `rectangleGeometry`

Type: [out] **[ID2D1RectangleGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rectanglegeometry)****

When this method returns, contains the address of the pointer to the rectangle geometry created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)