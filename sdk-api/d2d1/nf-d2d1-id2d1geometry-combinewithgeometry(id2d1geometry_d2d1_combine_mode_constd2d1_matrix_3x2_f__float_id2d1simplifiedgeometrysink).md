## Description

Combines this geometry with the specified geometry and stores the result in an [ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink).

## Parameters

### `inputGeometry`

Type: [in] **[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)***

The geometry to combine with this instance.

### `combineMode`

Type: [in] **[D2D1_COMBINE_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_combine_mode)**

The type of combine operation to perform.

### `inputGeometryTransform`

Type: [in] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f) &**

The transform to apply to *inputGeometry* before combining.

### `flatteningTolerance`

Type: [in] **FLOAT**

The maximum error allowed when constructing a polygonal approximation of the geometry. No point in the polygonal representation will diverge from the original geometry by more than the flattening tolerance. Smaller values produce more accurate results but cause slower execution.

### `geometrySink`

Type: [in] **[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)***

The result of the combine operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)