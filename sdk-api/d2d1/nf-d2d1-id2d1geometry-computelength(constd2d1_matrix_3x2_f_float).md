## Description

Calculates the length of the geometry as though each segment were unrolled into a line.

## Parameters

### `worldTransform`

Type: [in, optional] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the geometry before calculating its length, or **NULL**.

### `length`

Type: [out] **FLOAT***

When this method returns, contains a pointer to the length of the geometry. For closed geometries, the length includes an implicit closing segment. You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)