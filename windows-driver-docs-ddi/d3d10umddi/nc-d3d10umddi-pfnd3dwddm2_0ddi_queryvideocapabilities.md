# PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES callback function

## Description

**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES** queries the driver for its video capabilities. WDDM 2.0 or later drivers must implement this function.

## Parameters

### `hDevice`

[in] A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [**D3DDDIARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `QueryType`

[in] A [**D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_capability_query) value that indicates the type of data being queried.

### `DataSize`

[in] Size in bytes of the data that **pData** points to. This value is dependent on the **QueryType** member. For example, if **QueryType** is D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_DECODER_CAPS, set **DataSize** to ```sizeof(D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS)```.

### `pData`

[in/out] Pointer to a structure containing both caller-provided input parameters and output parameters that are to be filled in by the driver. The type of structure depends on the value of **QueryType**.

| Value of QueryType | Structure that pData points to |
| ------------------ | ------------------------------ |
| D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_DECODER_DOWNSAMPLING | [**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_downsampling) |
| D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_RECOMMEND_DECODER_DOWNSAMPLING | [**D3DWDDM2_0DDI_VIDEO_CAPABILITY_RECOMMEND_DECODER_DOWNSAMPLING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_recommend_decoder_downsampling) |
| D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_DECODER_CAPS | [**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_caps) |
| D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_DECODER_DOWNSAMPLE_OUTPUT_FORMAT | [**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLE_OUTPUT_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_downsample_output_format) |
| D3DWDDM2_4DDI_VIDEO_CAPABILITY_QUERY_DECODER_HISTOGRAM | [**D3DWDDM2_4DDI_VIDEO_CAPABILITY_DECODER_HISTOGRAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_4ddi_video_capability_decoder_histogram) |

## See also

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_caps)

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLE_OUTPUT_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_downsample_output_format)

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_downsampling)

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_capability_query)

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_RECOMMEND_DECODER_DOWNSAMPLING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_recommend_decoder_downsampling)