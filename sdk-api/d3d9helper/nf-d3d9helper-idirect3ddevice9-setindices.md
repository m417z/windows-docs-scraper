# IDirect3DDevice9::SetIndices

## Description

Sets index data.

## Parameters

### `pIndexData` [in]

Type: **[IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9)***

Pointer to an [IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9) interface, representing the index data to be set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## Remarks

When an application no longer holds a references to this interface, the interface will automatically be freed.

The **IDirect3DDevice9::SetIndices** method sets the current index array to an index buffer. The single set of indices is used to index all streams.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawIndexedPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive)

[IDirect3DDevice9::DrawIndexedPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitiveup)

[IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive)

[IDirect3DDevice9::DrawPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitiveup)

[IDirect3DDevice9::GetIndices](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getindices)

[Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/index-buffers)