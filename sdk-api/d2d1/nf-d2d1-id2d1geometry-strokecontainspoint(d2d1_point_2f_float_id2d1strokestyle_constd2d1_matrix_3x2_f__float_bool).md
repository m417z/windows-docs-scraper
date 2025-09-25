## Description

Determines whether the geometry's stroke contains the specified point given the specified stroke thickness, style, and transform.

## Parameters

### `point`

Type: [in] **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The point to test for containment.

### `strokeWidth`

Type: [in] **FLOAT**

The thickness of the stroke to apply.

### `strokeStyle`

Type: [in, optional] **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of stroke to apply.

### `worldTransform`

Type: [in] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f) &**

The transform to apply to the stroked geometry.

### `flatteningTolerance`

Type: [in] **FLOAT**

The numeric accuracy with which the precise geometric path and path intersection is calculated. Points missing the stroke by less than the tolerance are still considered inside. Smaller values produce more accurate results but cause slower execution.

### `contains`

Type: [out] **BOOL***

When this method returns, contains a boolean value set to true if the geometry's stroke contains the specified point; otherwise, false. You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)