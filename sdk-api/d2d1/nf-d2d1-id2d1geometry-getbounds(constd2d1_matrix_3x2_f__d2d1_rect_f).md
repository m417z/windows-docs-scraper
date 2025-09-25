# ID2D1Geometry::GetBounds(const D2D1_MATRIX_3X2_F &,D2D1_RECT_F)

## Description

Retrieves the bounds of the geometry.

## Parameters

### `worldTransform` [ref]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)**

The transform to apply to this geometry before calculating its bounds.

### `bounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)***

When this method returns, contains the bounds of this geometry. If the bounds are empty, this parameter will be a rect where *bounds.left* > *bounds.right*. You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)