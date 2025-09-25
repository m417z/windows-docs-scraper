# IDirect3DVertexBuffer9::GetDesc

## Description

Retrieves a description of the vertex buffer resource.

## Parameters

### `pDesc` [out]

Type: **[D3DVERTEXBUFFER_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvertexbuffer-desc)***

Pointer to a [D3DVERTEXBUFFER_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvertexbuffer-desc) structure, describing the returned vertex buffer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if the argument is invalid.

## See also

[IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)

[Vertex Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-buffers)