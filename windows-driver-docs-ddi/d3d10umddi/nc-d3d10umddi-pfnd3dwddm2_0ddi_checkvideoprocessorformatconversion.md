# PFND3DWDDM2_0DDI_CHECKVIDEOPROCESSORFORMATCONVERSION callback function

## Description

Indicates whether the driver supports a specific format/color-space conversion combination. This function must be implemented by Windows Display Driver Model (WDDM) 2.0 or later drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hProcessorEnum`

A handle to a video processor enumeration object that was created through a call to the [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

### `pConversion`

A pointer to a [D3DWDDM2_0DDI_CHECK_VIDEO_PROCESSOR_FORMAT_CONVERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_check_video_processor_format_conversion) structure that contains the input and output format/color-space combination.

## See also

[CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DWDDM2_0DDI_CHECK_VIDEO_PROCESSOR_FORMAT_CONVERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_check_video_processor_format_conversion)