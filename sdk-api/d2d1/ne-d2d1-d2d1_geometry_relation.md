# D2D1_GEOMETRY_RELATION enumeration

## Description

Describes how one geometry object is spatially related to another geometry object.

## Constants

### `D2D1_GEOMETRY_RELATION_UNKNOWN:0`

The relationship between the two geometries cannot be determined. This value is never returned by any D2D method.

### `D2D1_GEOMETRY_RELATION_DISJOINT:1`

The two geometries do not intersect at all.

### `D2D1_GEOMETRY_RELATION_IS_CONTAINED:2`

The instance geometry is entirely contained by the passed-in geometry.

### `D2D1_GEOMETRY_RELATION_CONTAINS:3`

The instance geometry entirely contains the passed-in geometry.

### `D2D1_GEOMETRY_RELATION_OVERLAP:4`

The two geometries overlap but neither completely contains the other.

### `D2D1_GEOMETRY_RELATION_FORCE_DWORD:0xffffffff`

## See also

[ID2D1Geometry::CompareWithGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1geometry-comparewithgeometry(id2d1geometry_constd2d1_matrix_3x2_f_d2d1_geometry_relation))