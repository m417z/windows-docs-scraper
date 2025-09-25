# IDirect3DDevice9::CreateVertexDeclaration

## Description

Create a vertex shader declaration from the device and the vertex elements.

## Parameters

### `pVertexElements` [in]

Type: **const [D3DVERTEXELEMENT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvertexelement9)***

An array of [D3DVERTEXELEMENT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvertexelement9) vertex elements.

### `ppDecl` [out, retval]

Type: **[IDirect3DVertexDeclaration9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexdeclaration9)****

Pointer to an [IDirect3DVertexDeclaration9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexdeclaration9) pointer that returns the created vertex shader declaration.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## Remarks

See the [Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-declaration) page for a detailed description of how to map vertex declarations between different versions of DirectX.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)