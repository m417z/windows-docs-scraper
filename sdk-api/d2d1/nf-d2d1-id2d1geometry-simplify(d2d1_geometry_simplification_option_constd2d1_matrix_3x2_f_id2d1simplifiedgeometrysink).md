## Description

Creates a simplified version of the geometry that contains only lines and (optionally) cubic Bezier curves and writes the result to an [ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink).

## Parameters

### `simplificationOption`

Type: [in] **[D2D1_GEOMETRY_SIMPLIFICATION_OPTION](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_geometry_simplification_option)**

A value that specifies whether the simplified geometry should contain curves.

### `worldTransform`

Type: [in] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the simplified geometry.

### `geometrySink`

Type: [in] **[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)***

The [ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink) to which the simplified geometry is appended.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)