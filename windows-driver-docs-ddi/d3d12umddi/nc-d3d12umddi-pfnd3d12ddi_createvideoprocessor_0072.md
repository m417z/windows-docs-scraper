# PFND3D12DDI_CREATEVIDEOPROCESSOR_0072 callback function

## Description

The *pfnCreateVideoProcessor* callback function creates a video processor.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context).

### `pArgs`

A [**D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_processor_0072) structure with arguments used to create a video processor.

### `hDrvVideoProcessor`

The video processor.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [**D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_processor_0072) and then calling Pfnd3d12ddiCreatevideoprocessor0072.

See the [D3D Video Protected Resource Support Specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_processor_0072)