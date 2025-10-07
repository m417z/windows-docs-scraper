# D3DXBoxBoundProbe function (D3DX10math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Determines whether a ray intersects the volume of a box's bounding box.

## Parameters

*pMin* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3), describing the lower-left corner of the bounding box. See Remarks.

*pMax* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) structure, describing the upper-right corner of the bounding box. See Remarks.

*pRayPosition* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a D3DXVECTOR3 structure, specifying the origin coordinate of the ray.

*pRayDirection* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a D3DXVECTOR3 structure, specifying the direction of the ray. This vector should not be (0,0,0) but does not need to be normalized.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Returns **TRUE** if the ray intersects the volume of the box's bounding box. Otherwise, returns **FALSE**.

## Remarks

**D3DXBoxBoundProbe** determines if the ray intersects the volume of the box's bounding box, not just the surface of the box.

The values passed to **D3DXBoxBoundProbe** are xmin, xmax, ymin, ymax, zmin, and zmax. Thus, the following defines the corners of the bounding box.

```
xmax, ymax, zmax
xmax, ymax, zmin
xmax, ymin, zmax
xmax, ymin, zmin
xmin, ymax, zmax
xmin, ymax, zmin
xmin, ymin, zmax
xmin, ymin, zmin
```

The depth of the bounding box in the z direction is zmax - zmin, in the y direction is ymax - ymin, and in the x direction is xmax - xmin. For example, with the following minimum and maximum vectors, min (-1, -1, -1) and max (1, 1, 1), the bounding box is defined in the following manner.

```
 1,  1,  1
 1,  1, -1
 1, -1,  1
 1, -1, -1
-1,  1,  1
-1,  1, -1
-1, -1,  1
-1, -1, -l
```

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header | D3DX10math.h |
| Library | D3DX10.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-mesh)

