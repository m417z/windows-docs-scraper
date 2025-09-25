# PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0072 callback function

## Description

**PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0072** calculates the size of the private video processor.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context).

### `pArgs`

Pointer to a [**D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_processor_0072) structure with arguments for this callback to use.

## Return value

Returns the size of the video processor in bytes.

## Remarks

The Direct3D runtime allocates memory for storing the driver's CPU object that represents the video processor. This method is used to calculate the driver object size.

See the [D3D Video Protected Resource Support Specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_processor_0072)