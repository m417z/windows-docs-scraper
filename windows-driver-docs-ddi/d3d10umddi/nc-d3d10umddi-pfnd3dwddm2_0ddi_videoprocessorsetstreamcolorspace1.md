# PFND3DWDDM2_0DDI_VIDEOPROCESSORSETSTREAMCOLORSPACE1 callback function

## Description

Sets the color space information for the video processor input stream. This function must be implemented by Windows Display Driver Model (WDDM) 2.0, or later, drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hVideoProcessor`

A handle to the video processor object.

### `StreamIndex`

Indicates the input stream.

### `ColorSpace`

Contains a [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type) enumeration value identifying the color space.

## Remarks

The legacy [VideoProcessorSetStreamColorSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamcolorspace)device driver interface (DDI) will not be called for WDDM 2.0 drivers.

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)