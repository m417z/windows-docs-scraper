# D3DXTANGENT enumeration

Defines settings used for mesh tangent frame computations.

## Constants

**D3DXTANGENT\_WRAP\_U**

Texture coordinate values in the u direction are between 0 and 1. In this case a texture coordinate set will be chosen that minimizes the perimeter of the triangle. See [Texture Wrapping (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/texture-wrapping).

**D3DXTANGENT\_WRAP\_V**

Texture coordinate values in the v direction are between 0 and 1. In this case a texture coordinate set will be chosen that minimizes the perimeter of the triangle. See [Texture Wrapping (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/texture-wrapping).

**D3DXTANGENT\_WRAP\_UV**

Texture coordinate values in both u and v directions are between 0 and 1. In this case a texture coordinate set will be chosen that minimizes the perimeter of the triangle. See [Texture Wrapping (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/texture-wrapping).

**D3DXTANGENT\_DONT\_NORMALIZE\_PARTIALS**

Do not normalize partial derivatives with respect to texture coordinates. If not normalized, the scale of the partial derivatives is proportional to the scale of the 3D model divided by the scale of the triangle in (u, v) space. This scale value provides a measure of how much the texture is stretched in a given direction. The resulting vector length is a weighted sum of the lengths of the partial derivatives.

**D3DXTANGENT\_DONT\_ORTHOGONALIZE**

Do not transform texture coordinates to orthogonal Cartesian coordinates. Mutually exclusive with D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U and D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V.

**D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V**

Compute the partial derivative with respect to texture coordinate v independently for each vertex, and then compute the partial derivative with respect to u as the cross product of the partial derivative with respect to v and the normal vector. Mutually exclusive with D3DXTANGENT\_DONT\_ORTHOGONALIZE and D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U.

**D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U**

Compute the partial derivative with respect to texture coordinate u independently for each vertex, and then compute the partial derivative with respect to v as the cross product of the normal vector and the partial derivative with respect to u. Mutually exclusive with D3DXTANGENT\_DONT\_ORTHOGONALIZE and D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V.

**D3DXTANGENT\_WEIGHT\_BY\_AREA**

Weight the direction of the computed per-vertex normal or partial derivative vector according to the areas of triangles attached to that vertex. Mutually exclusive with D3DXTANGENT\_WEIGHT\_EQUAL.

**D3DXTANGENT\_WEIGHT\_EQUAL**

Compute a unit-length normal vector for each triangle of the input mesh. Mutually exclusive with D3DXTANGENT\_WEIGHT\_BY\_AREA.

**D3DXTANGENT\_WIND\_CW**

Vertices are ordered in a clockwise direction around each triangle. The computed normal vector direction is therefore inverted 180 degrees from the direction computed using counterclockwise vertex ordering.

**D3DXTANGENT\_CALCULATE\_NORMALS**

Compute the per-vertex normal vector for each triangle of the input mesh, and ignore any normal vectors already in the input mesh.

**D3DXTANGENT\_GENERATE\_IN\_PLACE**

The results are stored in the original input mesh, and the output mesh is not used.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

[**D3DXComputeTangentFrameEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcomputetangentframeex)

