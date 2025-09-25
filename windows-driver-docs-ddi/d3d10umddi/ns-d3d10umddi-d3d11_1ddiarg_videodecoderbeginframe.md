# D3D11_1DDIARG_VIDEODECODERBEGINFRAME structure

## Description

Specifies a content key in a call to the [VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe) function.

## Members

### `hOutputView`

A handle to the driver's private data for the video decoder output view. This handle was created through a call to the [CreateVideoProcessorOutputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessoroutputview) function.

### `pContentKey`

A pointer to a content key that was used to encrypt the video frame data. If no content key was used, set this member to **NULL**. If the caller provides a content key, the caller must use the session key to encrypt the content key.

For more information, see the [VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe) function.

### `ContentKeySize`

The size, in bytes, of the content key that is specified in the **pContentKey** member.

## See also

[CreateVideoProcessorOutputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessoroutputview)

[VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe)