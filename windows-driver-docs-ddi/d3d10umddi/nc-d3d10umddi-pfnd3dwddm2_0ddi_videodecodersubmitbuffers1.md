# PFND3DWDDM2_0DDI_VIDEODECODERSUBMITBUFFERS1 callback function

## Description

**VideoDecoderSubmitBuffers1** submits one or more buffers for decoding.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hDecode`

A handle to the video decoder object that was created through a call to the [CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)DDI.

### `BufferCount`

The number of buffers in the array that is referenced by the **pBufferDesc** member.

### `pBufferDesc`

A pointer to an array of one or more [D3DWDDM2_0DDI_VIDEO_DECODER_BUFFER_DESC1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_decoder_buffer_desc1) structures.

## Return value

 Returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|Private driver data was successfully returned.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The **pBufferDesc** member points to an array of one or more [D3DWDDM2_0DDI_VIDEO_DECODER_BUFFER_DESC1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_decoder_buffer_desc1) structures. Each element in the array describes a compressed video frame buffer that is submitted for decoding.

## See also

[CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DWDDM2_0DDI_VIDEO_DECODER_BUFFER_DESC1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_decoder_buffer_desc1)