## Description

**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLE_OUTPUT_FORMAT** describes the video decoder down sample output format capabilities. The driver provides these capabilities when its [**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities) function is called.

## Members

### `DecodeProfile`

[in] The decode profile for which capabilities are being queried.

### `Format`

[in] A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) value that specifies the output format.

### `Supported`

[out] The driver sets this value to TRUE if it supports the specified **Format** for the **DecodeProfile**; otherwise it sets this value to FALSE.

## See also

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_capability_query)

[**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities)