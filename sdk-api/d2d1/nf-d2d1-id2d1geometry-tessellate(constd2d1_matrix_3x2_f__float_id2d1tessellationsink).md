## Description

Creates a set of clockwise-wound triangles that cover the geometry after it has been transformed using the specified matrix and flattened using the specified tolerance.

## Parameters

### `worldTransform`

Type: [in] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f) &**

The transform to apply to this geometry.

### `flatteningTolerance`

Type: [in] **FLOAT**

The maximum error allowed when constructing a polygonal approximation of the geometry. No point in the polygonal representation will diverge from the original geometry by more than the flattening tolerance. Smaller values produce more accurate results but cause slower execution.

### `tessellationSink`

Type: [in] **[ID2D1TessellationSink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1tessellationsink)***

The [ID2D1TessellationSink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1tessellationsink) to which the tessellated is appended.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)