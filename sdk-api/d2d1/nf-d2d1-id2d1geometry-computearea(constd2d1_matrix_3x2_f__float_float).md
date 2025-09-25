## Description

Computes the area of the geometry after it has been transformed by the specified matrix and flattened using the specified tolerance.

## Parameters

### `worldTransform`

Type: [in] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f) &**

The transform to apply to this geometry before computing its area.

### `flatteningTolerance`

Type: [in] **FLOAT**

The maximum error allowed when constructing a polygonal approximation of the geometry. No point in the polygonal representation will diverge from the original geometry by more than the flattening tolerance. Smaller values produce more accurate results but cause slower execution.

### `area`

Type: [out] **FLOAT***

When this method returns, contains a pointer to the area of the transformed, flattened version of this geometry. You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)