# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMOUTPUTRATE callback function

## Description

Sets the rate at which the video processor produces output frames for an input stream.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [**CreateVideoProcessor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*StreamIndex* [in]

The zero-based index of the input stream.

### `unnamedParam4`

*RepeatFrame* [in]

Specifies how the driver performs frame-rate conversion, if it is required.

If the **RepeatFrame** parameter is TRUE, the driver should repeat frames.

If the **RepeatFrame** parameter is FALSE, the driver should interpolate frames.

> [!NOTE]
>
> If **VideoProcessorSetStreamOutputRate** is never called, the driver should interpolate frames by default.

### `unnamedParam5`

*OutputRate* [in]

The output rate, specified as a [**D3D11_1DDI_VIDEO_PROCESSOR_OUTPUT_RATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_output_rate) value.

For more information, see the Remarks section.

### `unnamedParam6`

*pCustomRate* [in]

A pointer to a [**DXGI_RATIONAL**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure. If the **OutputRate** parameter is set to **D3D11_VIDEO_PROCESSOR_OUTPUT_RATE_CUSTOM**, this parameter specifies the exact output rate. Otherwise, this parameter is ignored and can be set to NULL.

## Remarks

The standard output rates that are defined by [**D3D11_1DDI_VIDEO_PROCESSOR_OUTPUT_RATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_output_rate) enumeration values are normal frame-rate (**D3D11_1DDI_VIDEO_PROCESSOR_OUTPUT_RATE_NORMAL**) and half frame-rate (**D3D11_1DDI_VIDEO_PROCESSOR_OUTPUT_RATE_HALF**).

If the driver supports custom rates for rate conversion or inverse telecine, it can use a custom rate if the **OutputRate** parameter is set to **D3D11_1DDI_VIDEO_PROCESSOR_OUTPUT_RATE_CUSTOM**. The custom rate is specified by the **pCustomRate** parameter.

> [!NOTE]
>
> The driver reports its custom rates in the [**D3D11_1DDI_VIDEO_PROCESSOR_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure that is returned through the [**GetVideoProcessorCustomRate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcustomrate) function.

Depending on the output rate, the driver might have to convert the frame rate. If so, the value of the **RepeatFrame** parameter controls whether the driver creates interpolated frames or repeats input frames.

## See also

[**CreateVideoProcessor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[**D3D11_1DDI_VIDEO_PROCESSOR_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[**D3D11_1DDI_VIDEO_PROCESSOR_OUTPUT_RATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_output_rate)

[**DXGI_RATIONAL**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational)

[**GetVideoProcessorCustomRate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcustomrate)