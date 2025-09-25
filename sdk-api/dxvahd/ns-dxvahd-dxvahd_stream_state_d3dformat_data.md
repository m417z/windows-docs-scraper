# DXVAHD_STREAM_STATE_D3DFORMAT_DATA structure

## Description

Specifies the format for an input stream, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Format`

The surface format, specified as a **D3DFORMAT** value. You can also use a FOURCC code to specify a format that is not defined in the **D3DFORMAT** enumeration. For more information, see [Video FOURCCs](https://learn.microsoft.com/windows/desktop/medfound/video-fourccs).

The default state value is **D3DFMT_UNKNOWN**.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)