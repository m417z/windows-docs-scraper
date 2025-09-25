# IDirect3DDevice9::DrawPrimitiveUP

## Description

Renders data specified by a user memory pointer as a sequence of geometric primitives of the specified type.

## Parameters

### `PrimitiveType` [in]

Type: **[D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype)**

Member of the [D3DPRIMITIVETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dprimitivetype) enumerated type, describing the type of primitive to render.

### `PrimitiveCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives to render. The maximum number of primitives allowed is determined by checking the MaxPrimitiveCount member of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure.

### `pVertexStreamZeroData` [in]

Type: **const void***

User memory pointer to the vertex data.

### `VertexStreamZeroStride` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes of data for each vertex. This value may not be 0.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## Remarks

This method is intended for use in applications that are unable to store their vertex data in vertex buffers. This method supports only a single vertex stream. The effect of this call is to use the provided vertex data pointer and stride for vertex stream 0. It is invalid to have the declaration of the current vertex shader refer to vertex streams other than stream 0.

Following any **IDirect3DDevice9::DrawPrimitiveUP** call, the stream 0 settings, referenced by [IDirect3DDevice9::GetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getstreamsource), are set to **NULL**.

The vertex data passed to **IDirect3DDevice9::DrawPrimitiveUP** does not need to persist after the call. Direct3D completes its access to that data prior to returning from the call.

When converting a legacy application to Direct3D 9, you must add a call to either [IDirect3DDevice9::SetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setfvf) to use the fixed function pipeline, or [IDirect3DDevice9::SetVertexDeclaration](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexdeclaration) to use a vertex shader before you make any Draw calls.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawIndexedPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitiveup)

[Rendering from Vertex and Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/rendering-from-vertex-and-index-buffers)