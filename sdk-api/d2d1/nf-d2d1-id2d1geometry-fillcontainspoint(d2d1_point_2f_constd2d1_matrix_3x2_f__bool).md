# ID2D1Geometry::FillContainsPoint(D2D1_POINT_2F,const D2D1_MATRIX_3X2_F &,BOOL)

## Description

Indicates whether the area filled by the geometry would contain the specified point.

## Parameters

### `point`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The point to test.

### `worldTransform` [ref]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)**

The transform to apply to the geometry prior to testing for containment.

### `contains` [out]

Type: **BOOL***

When this method returns, contains a bool value that is true if the area filled by the geometry contains *point*; otherwise, false.
You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)