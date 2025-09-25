# IDirect3DDevice9::DrawPrimitive

## Description

Renders a sequence of nonindexed, geometric primitives of the specified type from the current set of data input streams.

## Parameters

### `PrimitiveType` [in]

Type: **[D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype)**

Member of the [D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype) enumerated type, describing the type of primitive to render.

### `StartVertex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first vertex to load. Beginning at StartVertex the correct number of vertices will be read out of the vertex buffer.

### `PrimitiveCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives to render. The maximum number of primitives allowed is determined by checking the MaxPrimitiveCount member of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure. PrimitiveCount is the number of primitives as determined by the primitive type. If it is a line list, each primitive has two vertices. If it is a triangle list, each primitive has three vertices.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## Remarks

When converting a legacy application to Direct3D 9, you must add a call to either [IDirect3DDevice9::SetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setfvf) to use the fixed function pipeline, or [IDirect3DDevice9::SetVertexDeclaration](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexdeclaration) to use a vertex shader before you make any Draw calls.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawIndexedPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive)

[Rendering from Vertex and Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/rendering-from-vertex-and-index-buffers)