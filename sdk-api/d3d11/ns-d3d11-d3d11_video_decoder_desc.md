# D3D11_VIDEO_DECODER_DESC structure

## Description

Describes a video stream for a Microsoft Direct3D 11 video decoder or video processor.

## Members

### `Guid`

The decoding profile. To get the list of profiles supported by the device, call the [ID3D11VideoDevice::GetVideoDecoderProfile](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderprofile) method.

### `SampleWidth`

The width of the video frame, in pixels.

### `SampleHeight`

The height of the video frame, in pixels.

### `OutputFormat`

The output surface format, specified as a [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) value.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)