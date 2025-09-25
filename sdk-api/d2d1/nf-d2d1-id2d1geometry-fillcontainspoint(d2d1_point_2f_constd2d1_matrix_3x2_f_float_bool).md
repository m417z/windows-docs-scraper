# ID2D1Geometry::FillContainsPoint

## Description

Indicates whether the area filled by the geometry would contain the specified point given the specified flattening tolerance.

## Parameters

### `point`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The point to test.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the geometry prior to testing for containment, or **NULL**.

### `flatteningTolerance`

Type: **FLOAT**

The numeric accuracy with which the precise geometric path and path intersection is calculated. Points missing the fill by less than the tolerance are still considered inside. Smaller values produce more accurate results but cause slower execution.

### `contains` [out]

Type: **BOOL***

When this method returns, contains a **BOOL** value that is **TRUE** if the area filled by the geometry contains *point*; otherwise, **FALSE**.
You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)