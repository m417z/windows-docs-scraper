# PFND3D11_1DDI_VIDEODECODERENDFRAME callback function

## Description

Completes a DirectX Video Acceleration (DXVA) decoding operation for a video frame.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDecoder* [in]

A handle to the video decoder object that was created through a call to the [CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder) function.

## Remarks

The **VideoDecoderEndFrame** completes the decoding operation that was started when the Microsoft Direct3D runtime called [VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe). **VideoDecoderEndFrame** signals to the driver that all video data has been submitted for the video frame.

## See also

[CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)

[VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe)