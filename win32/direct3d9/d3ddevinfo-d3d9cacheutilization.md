# D3DDEVINFO\_D3D9CACHEUTILIZATION structure

Measure the cache hit rate performance for textures and indexed vertices.

## Members

**TextureCacheHitRate**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The hit rate for finding a texture in the texture cache. This assumes there is a texture cache. Increasing the level-of-detail bias to use the most detailed texture, using many large textures, or producing a near random texture access pattern on large textures with custom shader code can dramatically affect the texture cache hit rate.

**PostTransformVertexCacheHitRate**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The hit rate for finding transformed vertices in the vertex cache. The GPU is designed to transform indexed vertices and may store them in a vertex cache. If you are using meshes, [**D3DXOptimizeFaces**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxoptimizefaces) or [**D3DXOptimizeVertices**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxoptimizevertices) may result in better vertex cache utilization.

## Remarks

An efficient cache is typically closer to a 90 percent hit rate, and an inefficient cache is typically closer to a 10 percent hit rate (although a low percentage is not necessarily a problem).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetData**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dquery9-getdata)

