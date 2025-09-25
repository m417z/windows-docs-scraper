## Description

Retrieves index data.

## Parameters

### `ppIndexData`

Type: [out] **[IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9)****

Address of a pointer to an [IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9) interface, representing the returned index data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

Calling this method increases the internal reference count on the [IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DIndexBuffer9** interface results in a memory leak.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawIndexedPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive)

[IDirect3DDevice9::DrawIndexedPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitiveup)

[IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive)

[IDirect3DDevice9::DrawPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitiveup)

[IDirect3DDevice9::SetIndices](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setindices)

[Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/index-buffers)