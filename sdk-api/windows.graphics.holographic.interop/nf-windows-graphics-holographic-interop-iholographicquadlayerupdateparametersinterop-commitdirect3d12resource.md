## Description

The **CommitDirect3D12Resource** method commits a Direct3D 12 buffer for presentation on outputs associated with any [HolographicCamera](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographiccamera) to which the quad layer is attached. The buffer must have been created by calling [CreateDirect3D12ContentBufferResource](https://learn.microsoft.com/windows/win32/api/windows.graphics.holographic.interop/nf-windows-graphics-holographic-interop-iholographicquadlayerinterop-createdirect3d12contentbufferresource) or [CreateDirect3D12HardwareProtectedContentBufferResource](https://learn.microsoft.com/windows/win32/api/windows.graphics.holographic.interop/nf-windows-graphics-holographic-interop-iholographicquadlayerinterop-createdirect3d12hardwareprotectedcontentbufferresource) on the same [HolographicQuadLayer](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographicquadlayer) corresponding to this update parameters object, and the buffer must have been acquired by your application prior to rendering.

## Parameters

### `pColorResourceToCommit`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\***

The Direct3D 12 texture resource with content to display when rendering the [HolographicQuadLayer](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographicquadlayer) corresponding to this update parameters object. The content will also be displayed during any subsequent frames, until another content buffer update is provided for this [HolographicQuadLayer](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographicquadlayer).

### `pColorResourceFence`

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)\***

A fence used to signal app work completion on the content buffer resource indicated by *pColorResourceToCommit*. Completion of this fence at the value indicated by *colorResourceFenceSignalValue* signals transfer of control of the content buffer resource from your application to the platform in the GPU work queue. The platform relies upon this fence, and the value indicated in *colorResourceFenceSignalValue*, to queue work on the GPU that reads from the content buffer.

### `colorResourceFenceSignalValue`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The value used to signal work completion on *pColorResourceFence*. The platform relies upon this fence value to queue work on the GPU that reads from the content buffer.

## Return value

**S_OK** if successful, otherwise returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) error code indicating the reason for failure. Also see [COM Error Codes (UI, Audio, DirectX, Codec)](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## See also