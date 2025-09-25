# D3DWDDM2_0DDI_CHECK_VIDEO_PROCESSOR_FORMAT_CONVERSION structure

## Description

**D3DWDDM2_0DDI_CHECK_VIDEO_PROCESSOR_FORMAT_CONVERSION** is used with [CheckVideoProcessorFormatConversion](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_checkvideoprocessorformatconversion) to indicate whether the driver supports a specific format/color space conversion combination.

## Members

### `InputFormat`

Indicates the format of the video processor input.

### `InputColorSpace`

Indicates the color space of the video processor input.

### `OutputFormat`

Indicates the format of the video processor output.

### `OutputColorSpace`

Indicates the color space of the video processor output.

### `Supported`

The driver sets this to **TRUE** if the conversion between the input format/color space and the output format/color space is supported.

## See also

[CheckVideoProcessorFormatConversion](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_checkvideoprocessorformatconversion)