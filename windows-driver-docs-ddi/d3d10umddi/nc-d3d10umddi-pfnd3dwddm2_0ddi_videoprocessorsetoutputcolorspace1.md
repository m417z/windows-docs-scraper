# PFND3DWDDM2_0DDI_VIDEOPROCESSORSETOUTPUTCOLORSPACE1 callback function

## Description

Sets the color space information for the video processor output surface. This function must be implemented by Windows Display Driver Model (WDDM) 2.0, or later, drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hVideoProcessor`

A handle to the video processor object.

### `ColorSpace`

Contains a [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type) enumeration identifying the color space.

## Remarks

The legacy [VideoProcessorSetOutputColorSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputcolorspace)device driver interface (DDI) will not be called for WDDM 2.0 drivers.

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type)

[VideoProcessorSetOutputColorSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputcolorspace)