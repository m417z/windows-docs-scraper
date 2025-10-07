# D3DDECLUSAGE enumeration

Identifies the intended use of vertex data.

## Constants

**D3DDECLUSAGE\_POSITION**

Position data ranging from (-1,-1) to (1,1). Use D3DDECLUSAGE\_POSITION with a usage index of 0 to specify untransformed position for fixed function vertex processing and the n-patch tessellator. Use D3DDECLUSAGE\_POSITION with a usage index of 1 to specify untransformed position in the fixed function vertex shader for vertex tweening.

**D3DDECLUSAGE\_BLENDWEIGHT**

Blending weight data. Use D3DDECLUSAGE\_BLENDWEIGHT with a usage index of 0 to specify the blend weights used in indexed and nonindexed vertex blending.

**D3DDECLUSAGE\_BLENDINDICES**

Blending indices data. Use D3DDECLUSAGE\_BLENDINDICES with a usage index of 0 to specify matrix indices for indexed paletted skinning.

**D3DDECLUSAGE\_NORMAL**

Vertex normal data. Use D3DDECLUSAGE\_NORMAL with a usage index of 0 to specify vertex normals for fixed function vertex processing and the n-patch tessellator. Use D3DDECLUSAGE\_NORMAL with a usage index of 1 to specify vertex normals for fixed function vertex processing for vertex tweening.

**D3DDECLUSAGE\_PSIZE**

Point size data. Use D3DDECLUSAGE\_PSIZE with a usage index of 0 to specify the point-size attribute used by the setup engine of the rasterizer to expand a point into a quad for the point-sprite functionality.

**D3DDECLUSAGE\_TEXCOORD**

Texture coordinate data. Use D3DDECLUSAGE\_TEXCOORD, n to specify texture coordinates in fixed function vertex processing and in pixel shaders prior to ps\_3\_0. These can be used to pass user defined data.

**D3DDECLUSAGE\_TANGENT**

Vertex tangent data.

**D3DDECLUSAGE\_BINORMAL**

Vertex binormal data.

**D3DDECLUSAGE\_TESSFACTOR**

Single positive floating point value. Use D3DDECLUSAGE\_TESSFACTOR with a usage index of 0 to specify a tessellation factor used in the tessellation unit to control the rate of tessellation. For more information about the data type, see D3DDECLTYPE\_FLOAT1.

**D3DDECLUSAGE\_POSITIONT**

Vertex data contains transformed position data ranging from (0,0) to (viewport width, viewport height). Use D3DDECLUSAGE\_POSITIONT with a usage index of 0 to specify transformed position. When a declaration containing this is set, the pipeline does not perform vertex processing.

**D3DDECLUSAGE\_COLOR**

Vertex data contains diffuse or specular color. Use D3DDECLUSAGE\_COLOR with a usage index of 0 to specify the diffuse color in the fixed function vertex shader and pixel shaders prior to ps\_3\_0. Use D3DDECLUSAGE\_COLOR with a usage index of 1 to specify the specular color in the fixed function vertex shader and pixel shaders prior to ps\_3\_0.

**D3DDECLUSAGE\_FOG**

Vertex data contains fog data. Use D3DDECLUSAGE\_FOG with a usage index of 0 to specify a fog blend value used after pixel shading finishes. This applies to pixel shaders prior to version ps\_3\_0.

**D3DDECLUSAGE\_DEPTH**

Vertex data contains depth data.

**D3DDECLUSAGE\_SAMPLE**

Vertex data contains sampler data. Use D3DDECLUSAGE\_SAMPLE with a usage index of 0 to specify the displacement value to look up. It can be used only with D3DDECLUSAGE\_LOOKUPPRESAMPLED or D3DDECLUSAGE\_LOOKUP.

## Remarks

Vertex data is declared with an array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) structures. Each element in the array contains a usage type.

For more information about vertex declarations, see [Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-declaration).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-declaration)

