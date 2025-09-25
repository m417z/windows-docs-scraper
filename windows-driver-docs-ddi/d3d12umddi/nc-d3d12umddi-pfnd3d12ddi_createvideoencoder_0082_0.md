## Description

A client driver's **PFND3D12DDI_CREATEVIDEOENCODER_0082_0** callback function creates a video encoder object.

## Parameters

### `hDrvDevice` [in]

Handle to the D3D12 device.

### `pCreationArgs` [in]

Pointer to a [**D3D12DDIARG_CREATE_VIDEO_ENCODER_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_0082_0) structure with arguments to create this video encoder object.

### `hDrvVideoEncoder` [in/out]

Handle to the created video encoder object. The D3D12 runtime has allocated space for the driver to place its object based on the result of a prior call to [**PFND3D12DDI_CALCPRIVATEVIDEOENCODERSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoencodersize_0082_0).

## Return value

Returns an [**HRESULT**](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) value.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_DEVICE_FUNCS_VIDEO_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_video_0082_0)

[**D3D12DDIARG_CREATE_VIDEO_ENCODER_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_0082_0)

[**PFND3D12DDI_CALCPRIVATEVIDEOENCODERSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoencodersize_0082_0)

[**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2)