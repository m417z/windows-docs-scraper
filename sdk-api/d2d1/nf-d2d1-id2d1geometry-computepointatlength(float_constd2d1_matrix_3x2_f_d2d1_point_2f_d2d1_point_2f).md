## Description

Calculates the point and tangent vector at the specified distance along the geometry after it has been transformed by the specified matrix and flattened using the default tolerance.

## Parameters

### `length`

Type: [in] **FLOAT**

The distance along the geometry of the point and tangent to find. If this distance is less than 0, this method calculates the first point in the geometry. If this distance is greater than the length of the geometry, this method calculates the last point in the geometry.

### `worldTransform`

Type: [in, optional] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the geometry before calculating the specified point and tangent, or **NULL**.

### `point`

Type: [out, optional] **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)***

The location at the specified distance along the geometry. If the geometry is empty, this point contains NaN as its x and y values.

### `unitTangentVector`

Type: [out, optional] **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)***

The tangent vector at the specified distance along the geometry. If the geometry is empty, this vector contains NaN as its x and y values.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)