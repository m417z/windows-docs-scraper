# ID2D1Geometry::GetWidenedBounds

## Description

Gets the bounds of the geometry after it has been widened by the specified stroke width and style and transformed by the specified matrix.

## Parameters

### `strokeWidth`

Type: **FLOAT**

The amount by which to widen the geometry by stroking its outline.

### `strokeStyle` [in, optional]

Type: **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of the stroke that widens the geometry.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

A transform to apply to the geometry after the geometry is transformed and after the geometry has been stroked, or **NULL**.

### `flatteningTolerance`

Type: **FLOAT**

The maximum error allowed when constructing a polygonal approximation of the geometry. No point in the polygonal representation will diverge from the original geometry by more than the flattening tolerance. Smaller values produce more accurate results but cause slower execution.

### `bounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)***

When this method returns, contains the bounds of the widened geometry. You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)