# PFND3D11_1DDI_CHECKVIDEOPROCESSORFORMAT callback function

## Description

Queries whether the video processor supports a specified video format.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessorEnum* [in]

A handle to a video processor enumeration object that was created through a call to the [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

### `unnamedParam3`

*Format* [in]

The video format to query.

### `unnamedParam4`

*pSupported* [out]

Specifies a bitwise OR of zero or more flags from the [D3D11_1DDI_VIDEO_PROCESSOR_FORMAT_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_format_support) enumeration.

For more information, see the Remarks section.

## Remarks

If the driver can support the format as an input format for the video processor, the driver sets the **D3D11_1DDI_VIDEO_FORMAT_SUPPORT_VIDEO_PROCESSOR_INPUT** flag in the *pSupported* parameter.

If the driver can support the format as a video processing render target output format, the driver sets the **D3D11_1DDI_VIDEO_FORMAT_SUPPORT_VIDEO_PROCESSOR_OUTPUT** flag in the *pSupported* parameter.

If the driver can support neither, it must set the *pSupported* parameter to 0.

## See also

[CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum)

[D3D11_1DDI_VIDEO_PROCESSOR_FORMAT_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_format_support)