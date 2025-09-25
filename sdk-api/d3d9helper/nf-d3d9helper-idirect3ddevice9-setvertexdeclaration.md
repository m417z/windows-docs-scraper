# IDirect3DDevice9::SetVertexDeclaration

## Description

Sets a [Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-declaration).

## Parameters

### `pDecl` [in]

Type: **[IDirect3DVertexDeclaration9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexdeclaration9)***

Pointer to an [IDirect3DVertexDeclaration9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexdeclaration9) object, which contains the vertex declaration.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.
The return value can be D3DERR_INVALIDCALL.

## Remarks

A vertex declaration is an IDirect3DVertexDeclaration9 object that defines the data members of a vertex (i.e. texture coordinates, colors, normals, etc.). This data can be useful for implementing [vertex shaders and pixel shaders](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-pguide).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetVertexDeclaration](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getvertexdeclaration)