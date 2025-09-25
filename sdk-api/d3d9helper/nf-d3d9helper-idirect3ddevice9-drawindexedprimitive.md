# IDirect3DDevice9::DrawIndexedPrimitive

## Description

Based on indexing, renders the specified geometric primitive into an array of vertices.

## Parameters

### `unnamedParam1` [in]

Type: **[D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype)**

Member of the [D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype) enumerated type, describing the type of primitive to render. D3DPT_POINTLIST is not supported with this method. See Remarks.

### `BaseVertexIndex` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from the start of the vertex buffer to the first vertex. See [Scenario 4](https://learn.microsoft.com/windows/desktop/direct3d9/rendering-from-vertex-and-index-buffers).

### `MinVertexIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum vertex index for vertices used during this call. This is a zero based index relative to BaseVertexIndex.

### `NumVertices` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of vertices used during this call. The first vertex is located at index: BaseVertexIndex + MinIndex.

### `startIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first index to use when accessing the vertex buffer. Beginning at StartIndex to index vertices from the vertex buffer.

### `primCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives to render. The number of vertices used is a function of the primitive count and the primitive type. The maximum number of primitives allowed is determined by checking the MaxPrimitiveCount member of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be the following:
D3DERR_INVALIDCALL.

## Remarks

This method draws indexed primitives from the current set of data input streams. MinIndex and all the indices in the index stream are relative to the BaseVertexIndex.

The MinIndex and NumVertices parameters specify the range of vertex indices used for each **IDirect3DDevice9::DrawIndexedPrimitive** call. These are used to optimize vertex processing of indexed primitives by processing a sequential range of vertices prior to indexing into these vertices. It is invalid for any indices used during this call to reference any vertices outside of this range.

**IDirect3DDevice9::DrawIndexedPrimitive** fails if no index array is set.

The D3DPT_POINTLIST member of the [D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype) enumerated type is not supported and is not a valid type for this method.

When converting a legacy application to Direct3D 9, you must add a call to either [IDirect3DDevice9::SetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setfvf) to use the fixed function pipeline, or [IDirect3DDevice9::SetVertexDeclaration](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexdeclaration) to use a vertex shader before you make any Draw calls.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive)

[Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/index-buffers)

[Rendering from Vertex and Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/rendering-from-vertex-and-index-buffers)

[Vertex Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-buffers)