# ID2D1GeometryGroup::GetSourceGeometries

## Description

Retrieves the geometries in the geometry group.

## Parameters

### `geometries` [out]

Type: **const [ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)****

When this method returns, contains the address of a pointer to an array of geometries to be filled by this method. The length of the array is specified by the *geometryCount* parameter. If the array is **NULL**, then this method performs no operation. You must allocate the memory for this array.

### `geometriesCount`

Type: **UINT**

A value indicating the number of geometries to return in the *geometries* array. If this value is less than the number of geometries in the geometry group, the remaining geometries are omitted. If this value is larger than the number of geometries in the geometry group, the extra geometries are set to **NULL**. To obtain the number of geometries currently in the geometry group, use the [GetSourceGeometryCount](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1geometrygroup-getsourcegeometrycount) method.

## Remarks

The returned geometries are referenced and counted, and the caller must release them.

## See also

[ID2D1GeometryGroup](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrygroup)