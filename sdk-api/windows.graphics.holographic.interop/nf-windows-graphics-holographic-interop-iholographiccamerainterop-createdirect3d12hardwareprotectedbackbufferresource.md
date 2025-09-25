## Description

The **CreateDirect3D12HardwareProtectedBackBufferResource** method creates a Direct3D 12 resource for use as a back buffer for the corresponding [HolographicCamera](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographiccamera) API object, with optional hardware-based content protection.

The behavior of **CreateDirect3D12HardwareProtectedBackBufferResource** is the same as that of [CreateDirect3D12BackBufferResource](https://learn.microsoft.com/windows/win32/api/windows.graphics.holographic.interop/nf-windows-graphics-holographic-interop-iholographiccamerainterop-createdirect3d12backbufferresource), except that it accepts an optional [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) API object interface pointer. Provide a Direct3D 12 protected resource session via this optional parameter to create a resource buffer with hardware-based content protection enabled.

## Parameters

### `pDevice`

Type: **[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)\***

A Direct3D 12 device, which will be used to create the resource.

### `pTexture2DDesc`

Type: **[D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc)\***

The Direct3D 12 resource description.

**CreateDirect3D12HardwareProtectedBackBufferResource** adjusts the description as needed to comply with platform requirements, such as buffer size or format restrictions, which are determined at runtime. Your application should inspect the descriptor for the texture returned in *ppCreatedTexture2DResource* and respond appropriately to any differences from what was specified.

### `pProtectedResourceSession`

Type: **[ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession)\***

An optional Direct3D 12 protected resource session. Passing in a valid protected session will cause this method to create a Direct3D 12 hardware-protected resource.

### `ppCreatedTexture2DResource`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\*\***

If successful, the hardware-protected Direct3D 12 2D texture resource for use as a back buffer. Otherwise, `nullptr`.

## Return value

**S_OK** if successful, otherwise returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) error code indicating the reason for failure. Also see [COM Error Codes (UI, Audio, DirectX, Codec)](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## See also