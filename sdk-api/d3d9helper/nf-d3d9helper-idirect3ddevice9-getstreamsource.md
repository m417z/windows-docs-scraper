## Description

Retrieves a vertex buffer bound to the specified data stream.

## Parameters

### `StreamNumber`

Type: [in] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the data stream, in the range from 0 to the maximum number of streams minus one.

### `ppStreamData`

Type: [in, out] **[IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)****

Address of a pointer to an [IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9) interface, representing the returned vertex buffer bound to the specified data stream.

### `OffsetInBytes`

Type: [out] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer containing the offset from the beginning of the stream to the beginning of the vertex data. The offset is measured in bytes. See Remarks.

### `pStride`

Type: [out] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a returned stride of the component, in bytes. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

A stream is defined as a uniform array of component data, where each component consists of one or more elements representing a single entity such as position, normal, color, and so on.

When a FVF vertex shader is used, the stride of the vertex stream must match the vertex size, computed from the FVF. When a declaration is used, the stride should be greater than or equal to the stream size computed from the declaration.

Calling this method increases the internal reference count on the [IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DVertexBuffer9** interface results in a memory leak.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawIndexedPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive)

[IDirect3DDevice9::DrawIndexedPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitiveup)

[IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive)

[IDirect3DDevice9::DrawPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitiveup)

[IDirect3DDevice9::SetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setstreamsource)

[Vertex Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-buffers)