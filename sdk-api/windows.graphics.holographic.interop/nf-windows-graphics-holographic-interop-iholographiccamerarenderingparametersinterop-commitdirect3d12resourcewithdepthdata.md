## Description

Commits a Direct3D 12 buffer for presentation on outputs associated with the [HolographicCamera](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographiccamera). The buffer must have been created by calling [CreateDirect3D12BackBufferResource](https://learn.microsoft.com/windows/win32/api/windows.graphics.holographic.interop/nf-windows-graphics-holographic-interop-iholographiccamerainterop-createdirect3d12backbufferresource) or [CreateDirect3D12HardwareProtectedBackBufferResource](https://learn.microsoft.com/windows/win32/api/windows.graphics.holographic.interop/nf-windows-graphics-holographic-interop-iholographiccamerainterop-createdirect3d12hardwareprotectedbackbufferresource) on the same [HolographicCamera](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographiccamera) that it is committed for.

This method also accepts an optional depth buffer parameter, along with fence and fence value for app work completion on that buffer. This depth buffer will be used for image stabilization when showing the frame it is committed to. The depth buffer must contain depth data correlated with geometry used to draw holograms in the color buffer, which is submitted at the same time. The depth buffer should not contain depth data for invisible content, such as depth data used for occlusion.

## Parameters

### `pColorResourceToCommit`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\***

The Direct3D 12 texture resource with content to display when presenting the [HolographicFrame](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographicframe) used to retrieve this rendering parameters object.

### `pColorResourceFence`

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)\***

A fence used to signal app work completion on the color buffer resource indicated by *pColorResourceToCommit*. Completion of this fence at the value indicated by *colorResourceFenceSignalValue* signals transfer of control of the color resource from your application to the platform in the GPU work queue. The platform relies upon this fence, and the value indicated in *colorResourceFenceSignalValue*, to queue work on the GPU that reads from the color buffer.

### `colorResourceFenceSignalValue`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The value used to signal work completion on *pColorResourceFence*. The platform relies upon this fence value to queue work on the GPU that reads from the color buffer.

### `pDepthResourceToCommit`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\***

The Direct3D 12 depth buffer with depth data to use for image stabilization when presenting the [HolographicFrame](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographicframe) used to retrieve this rendering parameters object. Applications typically submit the depth stencil used when rendering to *pColorResourceToCommit*, or a depth buffer that is derived from the same rendering pass. The depth buffer should only include data corresponding to geometry used to render holograms in the color buffer; for example, occlusion data shouldn't be included, and may be ignored by the platform.

### `pDepthResourceFence`

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)\***

A fence used to signal work completion on the depth buffer resource indicated by *pDepthResourceToCommit*. Completion of this fence at the value indicated by *depthResourceFenceSignalValue* signals transfer of control of the depth resource from your application to the platform in the GPU work queue. The platform relies upon this fence, and the value indicated in *colorResourceFenceSignalValue*, to queue work on the GPU that reads from the depth buffer.

### `depthResourceFenceSignalValue`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The value used to signal work completion on *pDepthResourceFence*. The platform relies upon this fence value to queue work on the GPU that reads from the depth buffer.

## Return value

**S_OK** if successful, otherwise returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) error code indicating the reason for failure. Also see [COM Error Codes (UI, Audio, DirectX, Codec)](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## See also