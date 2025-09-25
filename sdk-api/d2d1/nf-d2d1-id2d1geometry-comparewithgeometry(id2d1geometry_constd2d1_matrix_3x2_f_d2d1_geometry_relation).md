## Description

Describes the intersection between this geometry and the specified geometry. The comparison is performed using the default flattening tolerance.

## Parameters

### `inputGeometry`

Type: [in] **[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)***

The geometry to test.

### `inputGeometryTransform`

Type: [in, optional] **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to *inputGeometry*, or **NULL**.

### `relation`

Type: [out] **[D2D1_GEOMETRY_RELATION](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_geometry_relation)***

When this method returns, contains a pointer to a value that describes how this geometry is related to *inputGeometry*. You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

When interpreting the returned *relation* value, it is important to remember that the member [D2D1_GEOMETRY_RELATION_IS_CONTAINED](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_geometry_relation) of the **D2D1_GEOMETRY_RELATION** enumeration type means that this geometry is contained inside *inputGeometry*, not that this geometry contains *inputGeometry*.

For more information about how to interpret other possible return values, see [D2D1_GEOMETRY_RELATION](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_geometry_relation).

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)