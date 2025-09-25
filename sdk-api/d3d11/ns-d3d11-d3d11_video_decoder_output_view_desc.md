# D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC structure

## Description

Describes a video decoder output view.

## Members

### `DecodeProfile`

The decoding profile. To get the list of profiles supported by the device, call the [ID3D11VideoDevice::GetVideoDecoderProfile](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderprofile) method.

### `ViewDimension`

The resource type of the view, specified as a member of the [D3D11_VDOV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_vdov_dimension) enumeration.

### `Texture2D`

A [D3D11_TEX2D_VDOV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_vdov) structure that identifies the texture resource for the output view.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoDevice::CreateVideoDecoderOutputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoderoutputview)