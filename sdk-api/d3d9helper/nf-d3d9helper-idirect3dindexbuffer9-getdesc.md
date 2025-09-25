# IDirect3DIndexBuffer9::GetDesc

## Description

Retrieves a description of the index buffer resource.

## Parameters

### `pDesc` [out]

Type: **[D3DINDEXBUFFER_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dindexbuffer-desc)***

Pointer to a [D3DINDEXBUFFER_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dindexbuffer-desc) structure, describing the returned index buffer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if the argument is invalid.

## See also

[IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9)

[Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/index-buffers)