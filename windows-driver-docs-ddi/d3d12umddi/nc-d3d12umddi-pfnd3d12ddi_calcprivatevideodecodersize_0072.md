# PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0072 callback function

## Description

**PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0072** calculates the size of a video decoder.

## Parameters

### `hDrvDevice`

The hardware device being processed.

### `pArgs` [in]

Pointer to a [**D3D12DDIARG_CREATE_VIDEO_DECODER_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_0072) structure with arguments used by this callback function.

## Return value

Returns the size of the video decoder in bytes.

## Remarks

 The D3D runtime allocates memory for storing the driver's CPU object representing the video decoder. This method is used to calculate the driver object size.

See the [D3D Video Protected Resource Support Specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_DECODER_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_0072)