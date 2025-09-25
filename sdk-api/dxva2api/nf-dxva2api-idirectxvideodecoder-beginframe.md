# IDirectXVideoDecoder::BeginFrame

## Description

Starts the decoding operation.

## Parameters

### `pRenderTarget` [in]

Pointer to the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface of the render target where the decoded frame will be written.

### `pvPVPData` [in]

Reserved; set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid surface type. See Remarks. |

## Remarks

After this method is called, call [IDirectXVideoDecoder::Execute](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-execute) to perform decoding operations. When all decoding operations have been executed, call [IDirectXVideoDecoder::EndFrame](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-endframe).

Each call to **BeginFrame** must have a matching call to [EndFrame](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-endframe), and **BeginFrame** calls cannot be nested.

DXVA 1.0 migration note: Unlike the **IAMVideoAccelerator::BeginFrame** method, which specifies the buffer as an index, this method takes a pointer directly to the uncompressed buffer.

The surface pointed to by *pRenderTarget* must be created by calling [IDirectXVideoAccelerationService::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoaccelerationservice-createsurface) with the value DXVA2_VideoDecoderRenderTarget for *DxvaType*.

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoder](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoder)