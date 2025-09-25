# D3D11_VDOV_DIMENSION enumeration

## Description

Specifies how to access a resource that is used in a video decoding output view.

## Constants

### `D3D11_VDOV_DIMENSION_UNKNOWN:0`

Not a valid value.

### `D3D11_VDOV_DIMENSION_TEXTURE2D:1`

The resource will be accessed as a 2D texture.

## Remarks

This enumeration is used with the [D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_output_view_desc) structure.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)

[ID3D11VideoDevice::CreateVideoDecoderOutputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoderoutputview)