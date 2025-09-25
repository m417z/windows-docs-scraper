# IDirect3DDevice9::DrawIndexedPrimitiveUP

## Description

Renders the specified geometric primitive with data specified by a user memory pointer.

## Parameters

### `PrimitiveType` [in]

Type: **[D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype)**

Member of the [D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype) enumerated type, describing the type of primitive to render.

### `MinVertexIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum vertex index. This is a zero-based index.

### `NumVertices` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

 Number of vertices used during this call. The first vertex is located at index: MinVertexIndex.

### `PrimitiveCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives to render. The maximum number of primitives allowed is determined by checking the MaxPrimitiveCount member of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure (the number of indices is a function of the primitive count and the primitive type).

### `pIndexData` [in]

Type: **const void***

User memory pointer to the index data.

### `IndexDataFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, describing the format of the index data. The valid settings are either:

* [D3DFMT_INDEX16](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)
* [D3DFMT_INDEX32](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)

### `pVertexStreamZeroData` [in]

Type: **const void***

User memory pointer to the vertex data. The vertex data must be in stream 0.

### `VertexStreamZeroStride` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes of data for each vertex. This value may not be 0.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be the following:
D3DERR_INVALIDCALL.

## Remarks

This method is intended for use in applications that are unable to store their vertex data in vertex buffers. This method supports only a single vertex stream, which must be declared as stream 0.

Following any **IDirect3DDevice9::DrawIndexedPrimitiveUP** call, the stream 0 settings, referenced by [IDirect3DDevice9::GetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getstreamsource), are set to **NULL**. Also, the index buffer setting for [IDirect3DDevice9::SetIndices](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setindices) is set to **NULL**.

The vertex data passed to **IDirect3DDevice9::DrawIndexedPrimitiveUP** does not need to persist after the call. Direct3D completes its access to that data prior to returning from the call.

When converting a legacy application to Direct3D 9, you must add a call to either [IDirect3DDevice9::SetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setfvf) to use the fixed function pipeline, or [IDirect3DDevice9::SetVertexDeclaration](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexdeclaration) to use a vertex shader before you make any Draw calls.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive)

[Rendering from Vertex and Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/rendering-from-vertex-and-index-buffers)