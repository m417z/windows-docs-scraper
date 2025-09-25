# IDirectXVideoDecoder::GetBuffer

## Description

Retrieves a pointer to a DirectX Video Acceleration (DXVA) decoder buffer.

## Parameters

### `BufferType` [in]

Type of buffer to retrieve. Use one of the following values.

| Value | Meaning |
| --- | --- |
| **DXVA2_PictureParametersBufferType** | Picture decoding parameter buffer. |
| **DXVA2_MacroBlockControlBufferType** | Macroblock control command buffer. |
| **DXVA2_ResidualDifferenceBufferType** | Residual difference block data buffer. |
| **DXVA2_DeblockingControlBufferType** | Deblocking filter control command buffer. |
| **DXVA2_InverseQuantizationMatrixBufferType** | Inverse quantization matrix buffer. |
| **DXVA2_SliceControlBufferType** | Slice-control buffer. |
| **DXVA2_BitStreamDateBufferType** | Bitstream data buffer. |
| **DXVA2_MotionVectorBuffer** | Motion vector buffer. |
| **DXVA2_FilmGrainBuffer** | Film grain synthesis data buffer. |

### `ppBuffer` [out]

Receives a pointer to the start of the memory buffer.

### `pBufferSize` [out]

Receives the size of the buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The method locks the Direct3D surface that contains the buffer. When you are done using the buffer, call [IDirectXVideoDecoder::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-releasebuffer) to unlock the surface.

This method might block if too many operations have been queued on the GPU. The method unblocks when a free buffer becomes available.

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoder](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoder)