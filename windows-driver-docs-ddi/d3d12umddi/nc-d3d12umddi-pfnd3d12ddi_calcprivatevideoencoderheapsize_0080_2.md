## Description

A client driver's **PFND3D12DDI_CALCPRIVATEVIDEOENCODERHEAPSIZE_0080_2** callback function calculates the required amount of memory needed for the driver's object that represents the video encoder heap.

## Parameters

### `hDrvDevice` [in]

Handle for the D3D12 device.

### `pCreationArgs` [in]

Pointer to a [**D3D12DDIARG_CREATE_VIDEO_ENCODER_HEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_heap_0080_2) structure that contains the video encoder heap creation parameters.

## Return value

Returns the number of bytes needed to store the driver's object that represents the video encoder heap.

## Remarks

On return, the D3D12 runtime will allocate the memory needed to store the driver's object and then call [**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2) to create the actual object.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_ENCODER_HEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_heap_0080_2)

[**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2)