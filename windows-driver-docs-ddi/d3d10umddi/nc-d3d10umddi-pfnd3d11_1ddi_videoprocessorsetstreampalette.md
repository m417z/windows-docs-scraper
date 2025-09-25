# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMPALETTE callback function

## Description

Sets the color-palette entries for an input stream on the video processor.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*StreamIndex* [in]

The zero-based index of the input stream.

### `unnamedParam4`

*Count* [in]

The number of elements in the array that is referenced by the *pEntries* parameter.

### `unnamedParam5`

*pEntries* [in]

A pointer to an array of palette entries. For RGB streams, the palette entries are specified in the **DXGI_FORMAT_B8G8R8A8** format. For YCbCr streams, the palette entries are specified in the **DXGI_FORMAT_AYUV** format.

## Remarks

The **VideoProcessorSetStreamPalette** function is called only for input streams that have a palettized color format. Palettized formats with 4 bits per pixel (bpp) use the first 16 entries in the list. Formats with 8 bpp use the first 256 entries.

If a pixel has a palette index greater than the number of entries, the device treats the pixel as white with opaque alpha. For full-range RGB, this value is (255, 255, 255, 255); for YCbCr the value is (255, 235, 128, 128).

The driver reports its ability to support palettized color formats in the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure that is returned through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. If the driver supports the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE** capability, it can be configured with color-palette entries for an input stream.

**Note** If the driver does not support the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE** capability, the Microsoft Direct3D runtime does not call the [VideoProcessorSetOutputStereoMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputstereomode) function.

If the driver does not report the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE** capability, every palette entry must have an alpha value of 0xFF (opaque).

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps)