# D3D11_1DDI_VIDEO_DECODER_DESC structure

## Description

Describes a video stream for a Microsoft Direct3D video decoder or video processor.

## Members

### `Guid`

The DXVA decoding profile. To get the list of profiles supported by the device, call the [**GetVideoDecoderProfile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderprofile) function.

### `SampleWidth`

The width of the video frame, in pixels.

### `SampleHeight`

The height of the video frame, in pixels.

### `OutputFormat`

The output surface format, specified as a **DXGI_FORMAT** value. The **DXGI_FORMAT** enumeration is defined in *Dxgiformat.h*.

## See also

[**GetVideoDecoderProfile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderprofile)

[**PFND3D11_1DDI_VIDEODECODERSUBMITBUFFERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecodersubmitbuffers)