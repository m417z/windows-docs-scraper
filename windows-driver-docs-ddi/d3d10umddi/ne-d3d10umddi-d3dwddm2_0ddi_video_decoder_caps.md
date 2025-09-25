# D3DWDDM2_0DDI_VIDEO_DECODER_CAPS enumeration

## Description

Describes the video decoder capabilities.

## Constants

### `D3DWDDM2_0DDI_VIDEO_DECODER_CAP_DOWNSAMPLE`

Indicates that the driver can support at least some downsampling scenarios.

### `D3DWDDM2_0DDI_VIDEO_DECODER_CAP_NON_REAL_TIME`

The decode operation is supported, but cannot be performed real-time. Indicates that the decode hardware cannot support the decode operation in real-time. Decode is still viable for transcode scenarios.

It is possible that decode can occur in real-time if downsampling is applied.

### `D3DWDDM2_0DDI_VIDEO_DECODER_CAP_DOWNSAMPLE_REQUIRED`

 Indicates that the decode configuration can be supported only if down sampling is applied.

### `D3DWDDM2_0DDI_VIDEO_DECODER_CAP_UNSUPPORTED`

 Indicates that the decode configuration is not supported.

## Syntax

```c
typedef enum D3DWDDM2_0DDI_VIDEO_DECODER_CAPS
{
    D3DWDDM2_0DDI_VIDEO_DECODER_CAP_DOWNSAMPLE           = 0x01,
    D3DWDDM2_0DDI_VIDEO_DECODER_CAP_NON_REAL_TIME        = 0x02,
    D3DWDDM2_0DDI_VIDEO_DECODER_CAP_DOWNSAMPLE_REQUIRED  = 0x04,
    D3DWDDM2_0DDI_VIDEO_DECODER_CAP_UNSUPPORTED          = 0x08
} D3DWDDM2_0DDI_VIDEO_DECODER_CAPS;
```

## See also

[QueryVideoCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities)