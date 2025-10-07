# D3DXPATCHINFO structure

Structure that contains the attributes of a patch mesh.

## Members

**PatchType**

Type: **[**D3DXPATCHMESHTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxpatchmeshtype)**

The patch type. For information about patch types, see [**D3DXPATCHMESHTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxpatchmeshtype).

**Degree**

Type: **[**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype)**

Degree of the curves used to construct the patch. For information about the degrees supported, see [**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype).

**Basis**

Type: **[**D3DBASISTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbasistype)**

Type of curve used to construct the patch. For information about the basis types supported, see [**D3DBASISTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbasistype).

## Remarks

A mesh is a set of faces, each of which is described by a simple polygon. Objects can be created by connecting several meshes together. A patch mesh is constructed from patches. A patch is a four-sided piece of geometry constructed from curves. The type of curve used and the order of the curve can be varied so that the patch surface will fit almost any surface shape.

The following types of patch combinations are supported:

| Patch Type | Basis | Degree |
|------------|-------------|--------|
| Rectangle | Bezier | 2,3,5 |
| Rectangle | B-Spline | 2,3,5 |
| Rectangle | Catmull-Rom | 3 |
| Triangle | Bezier | 2,3,5 |
| N-patch | N/A | 3 |

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**D3DRECTPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3drectpatch-info)

[**D3DTRIPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtripatch-info)

[**D3DXCreatePatchMesh**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatepatchmesh)

