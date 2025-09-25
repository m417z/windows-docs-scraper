# PFND3D12DDI_CREATEVIDEODECODER_0072 callback function

## Description

A client driver's **PFND3D12DDI_CREATEVIDEODECODER_0072** callback function creates a video decoder.

## Parameters

### `hDrvDevice`

[in] Handle for the D3D12 device.

### `pArgs`

[in] Pointer to a [**D3D12DDIARG_CREATE_VIDEO_DECODER_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_0072) structure with arguments to create this video decoder object.

### `hDrvVideoDecoder`

[out] Handle to the created video decoder object.

## Return value

Returns an [**HRESULT**](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) value.

## Remarks

See the [D3D Video Protected Resource Support Specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_DECODER_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_0072)