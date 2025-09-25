# PFND3DWDDM2_0DDI_VIDEODECODERUPDATEDOWNSAMPLING callback function

## Description

Updates the decoder down sampling parameters. Optional for Windows Display Driver Model (WDDM) 2.0, or later, drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hDecoder`

A handle to the video decoder object.

### `pOutputDesc`

Contains the resolution and the format of the output/display frames. This is the destination resolution and format of the down sample operation.

**Note** The decode profile member (**Guid**) of **pOutputDesc** can be ignored.

### `OutputColorSpace`

A [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type) value that contains the color space information of the output/display frame data.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function can only be called after [VideoDecoderEnableDownsampling](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecoderenabledownsampling) has been called.

This function will only be called if the driver reports the **D3DWDDM2_0DDI_VIDEO_DECODER_CAPS_DOWN_SAMPLE_DYNAMIC** capability.

## See also

[D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type)

[VideoDecoderEnableDownsampling](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecoderenabledownsampling)