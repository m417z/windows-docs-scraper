# PFND3D11_1DDI_VIDEODECODERBEGINFRAME callback function

## Description

Starts a DirectX Video Acceleration (DXVA) decoding operation to decode a video frame.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDecoder* [in]

A handle to the video decoder object that was created through a call to the [CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder) function.

### `unnamedParam3`

*pBeginFrame* [in]

A pointer to a [D3D11_1DDIARG_VIDEODECODERBEGINFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_videodecoderbeginframe) structure. For more information, see the Remarks section.

## Return value

**VideoDecoderBeginFrame** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The decoding operation was started successfully.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

If the **VideoDecoderBeginFrame** returns **S_OK**, the Microsoft Direct3D runtime calls the [VideoDecoderSubmitBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecodersubmitbuffers) function to perform the decoding operations. When all decoding operations have been executed, the runtime calls the [VideoDecoderEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderendframe) function to stop the decoding operation on a video frame.

**Note** Each call to **VideoDecoderBeginFrame** must have a matching call to [VideoDecoderEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderendframe), and **VideoDecoderBeginFrame** calls cannot be nested.

The [D3D11_1DDIARG_VIDEODECODERBEGINFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_videodecoderbeginframe) structure contains the following data:

* The resource that will receive the decrypted and decoded data.
* A content key that was used to encrypt the video frame data.

  If the **pContentKey** member of this structure is not set to NULL, the buffer that is referenced by this member contains a per-frame content key. This key must be used to decrypt the data instead of using the session key.

  **Note** If the **pContentKey** member is not set to NULL, the buffer that is referenced by this member is encrypted by using the session key with the AES-ECB algorithm.

  If the **pContentKey** member is set to NULL, the video frame data should be decrypted by using the session key.

## See also

[CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)

[VideoDecoderEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderendframe)

[VideoDecoderSubmitBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecodersubmitbuffers)