# PFND3D11_1DDI_VIDEODECODERSUBMITBUFFERS callback function

## Description

Submits one or more video frame buffers for DirectX Video Acceleration (DXVA) decoding.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDecoder* [in]

A handle to the video decoder object that was created through a call to the [**CreateVideoDecoder**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder) function.

### `unnamedParam3`

**BufferCount** [in]

The number of buffers in the array that is referenced by the **pBufferDesc** parameter.

### `unnamedParam4`

**pBufferDesc** [in]

A pointer to an array of one or more [**D3D11_1DDI_VIDEO_DECODER_BUFFER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_buffer_desc) structures. For more information, see the Remarks section.

## Return value

**VideoDecoderSubmitBuffers** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The video buffers were submitted successfully.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The **pBufferDesc** parameter points to an array of one or more [**D3D11_1DDI_VIDEO_DECODER_BUFFER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_buffer_desc) structures. Each element in the array describes a compressed video frame buffer that is submitted for decoding.

Each [**D3D11_1DDI_VIDEO_DECODER_BUFFER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_buffer_desc) structure includes the following data:

* The resource that will receive the decrypted and decode frame buffers.

* A [D3D11_1DDI_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_encrypted_block_info) structure that specifies which bytes of the frame buffer are encrypted.

* A pointer to a [D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv) structure that contains an initialization vector (IV) for the frame buffer data that was encrypted by using the 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher encryption algorithm.

> [!NOTE]
> If the decode buffer does not contain any encrypted data, this pointer is set to NULL.

> [!NOTE]
> This function does not honor a Microsoft Direct3D 11 predicate that may have been set.

## See also

[**CreateVideoDecoder**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)

[**D3D11_1DDI_AES_CTR_IV**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv)

[**D3D11_1DDI_ENCRYPTED_BLOCK_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_encrypted_block_info)

[**D3D11_1DDI_VIDEO_DECODER_BUFFER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_buffer_desc)