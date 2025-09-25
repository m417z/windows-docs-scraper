# PFND3DWDDM2_0DDI_VIDEODECODERENABLEDOWNSAMPLING callback function

## Description

Indicates that decoder down-sampling will be used and that the driver should allocate the appropriate reference frames. Optional for Windows Display Driver Model (WDDM) 2.0 or later drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hDecoder`

A handle to the decoder object.

### `InputColorSpace`

A [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type) value that indicates the color space information of the reference frame data.

### `pOutputDesc`

Indicates the resolution and the format of the output/display frames. This is the destination resolution and format of the down-sample operation.

**Note** The decode profile member (**Guid**) of **pOutputDesc** can be ignored.

### `OutputColorSpace`

A [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type) value that indicates the color space information of the output/display frames.

### `ReferenceFrameCount`

Indicates the number of reference frame used.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function can only be called once, prior to the first [VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe) call.

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type)

[VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe)