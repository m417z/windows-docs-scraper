# D2D1_GEOMETRY_SIMPLIFICATION_OPTION enumeration

## Description

Specifies how a geometry is simplified to an [ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink).

## Constants

### `D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES:0`

The output can contain cubic Bezier curves and line segments.

### `D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES:1`

The output is flattened so that it contains only line segments.

### `D2D1_GEOMETRY_SIMPLIFICATION_OPTION_FORCE_DWORD:0xffffffff`

## See also

[ID2D1Geometry::Simplify](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1geometry-simplify(d2d1_geometry_simplification_option_constd2d1_matrix_3x2_f_id2d1simplifiedgeometrysink))