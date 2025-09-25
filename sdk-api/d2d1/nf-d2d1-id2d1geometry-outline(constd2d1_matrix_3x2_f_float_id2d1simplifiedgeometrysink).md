# ID2D1Geometry::Outline

## Description

Computes the outline of the geometry and writes the result to an [ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink).

## Parameters

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the geometry outline, or **NULL**.

### `flatteningTolerance`

Type: **FLOAT**

The maximum error allowed when constructing a polygonal approximation of the geometry. No point in the polygonal representation will diverge from the original geometry by more than the flattening tolerance. Smaller values produce more accurate results but cause slower execution.

### `geometrySink` [in]

Type: **[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)***

The [ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink) to which the geometry's transformed outline is appended.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The [Outline](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1geometry-outline(constd2d1_matrix_3x2_f__id2d1simplifiedgeometrysink)) method allows the caller to produce a geometry with an equivalent fill to the input geometry, with the following additional properties:

* The output geometry contains no transverse intersections; that is, segments may touch, but they never cross.
* The outermost figures in the output geometry are all oriented counterclockwise.
* The output geometry is fill-mode invariant; that is, the fill of the geometry does not depend on the choice of the fill mode.

   For more information about the fill mode, see [D2D1_FILL_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_fill_mode).

Additionally, the
[Outline](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1geometry-outline(constd2d1_matrix_3x2_f__id2d1simplifiedgeometrysink)) method can be useful in removing redundant portions of said geometries to simplify complex geometries. It can also be useful in combination with [ID2D1GeometryGroup](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrygroup) to create unions among several geometries simultaneously.

## See also

[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)