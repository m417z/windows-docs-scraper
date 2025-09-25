# IDirect3DDevice9::SetStreamSource

## Description

Binds a vertex buffer to a device data stream. For more information, see [Setting the Stream Source (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/setting-the-stream-source).

## Parameters

### `StreamNumber` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the data stream, in the range from 0 to the maximum number of streams -1.

### `pStreamData` [in]

Type: **[IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)***

Pointer to an [IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9) interface, representing the vertex buffer to bind to the specified data stream.

### `OffsetInBytes` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from the beginning of the stream to the beginning of the vertex data, in bytes. To find out if the device supports stream offsets, see the D3DDEVCAPS2_STREAMOFFSET constant in [D3DDEVCAPS2](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevcaps2).

### `Stride` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Stride of the component, in bytes. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

When a FVF vertex shader is used, the stride of the vertex stream must match the vertex size, computed from the FVF. When a declaration is used, the stride should be greater than or equal to the stream size computed from the declaration.

When calling SetStreamSource, the stride is normally required to be equal to the vertex size. However, there are times when you may want to draw multiple instances of the same or similar geometry (such as when using instancing to draw). For this case, use a zero stride to tell the runtime not to increment the vertex buffer offset (ie: use the same vertex data for all instances). For more information about instancing, see [Efficiently Drawing Multiple Instances of Geometry (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/efficiently-drawing-multiple-instances-of-geometry).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawIndexedPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive)

[IDirect3DDevice9::DrawIndexedPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitiveup)

[IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive)

[IDirect3DDevice9::DrawPrimitiveUP](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitiveup)

[IDirect3DDevice9::GetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getstreamsource)

[Vertex Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-buffers)