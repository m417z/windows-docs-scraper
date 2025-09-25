# D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY enumeration

## Description

A **D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY** value describes the video capabilities being queried through a call to the driver's [**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities) function.

## Constants

### `D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_DECODER_DOWNSAMPLING:2`

Query the driver's support for the specified down sampling parameters.

### `D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_RECOMMEND_DECODER_DOWNSAMPLING:3`

Query the driver's support for the specified down sampling parameters recommended by the user-mode driver.

### `D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_DECODER_CAPS:4`

Query the driver's video decoder capabilities.

### `D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY_DECODER_DOWNSAMPLE_OUTPUT_FORMAT:5`

Query the driver's support for the specified down sample output format.

### `D3DWDDM2_4DDI_VIDEO_CAPABILITY_QUERY_DECODER_HISTOGRAM:6`

Query the driver's support for the specified decoder histogram.

## See also

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_caps)

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLE_OUTPUT_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_downsample_output_format)

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_decoder_downsampling)

[**D3DWDDM2_4DDI_VIDEO_CAPABILITY_DECODER_HISTOGRAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_4ddi_video_capability_decoder_histogram)

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_RECOMMEND_DECODER_DOWNSAMPLING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_capability_recommend_decoder_downsampling)

[**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities)