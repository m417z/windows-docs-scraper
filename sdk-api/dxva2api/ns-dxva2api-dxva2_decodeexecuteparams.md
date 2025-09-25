# DXVA2_DecodeExecuteParams structure

## Description

Contains parameters for the [IDirectXVideoDecoder::Execute](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-execute) method.

## Members

### `NumCompBuffers`

Number of compressed buffers.

### `pCompressedBuffers`

Pointer to an array of [DXVA2_DecodeBufferDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_decodebufferdesc) structures that describe the compressed buffers. The number of elements in the array is given by the **NumCompBuffers** member.

### `pExtensionData`

Pointer to a [DXVA2_DecodeExtensionData](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_decodeextensiondata) structure that contains private data. Set this member to **NULL** unless you need to send private data to or from the driver.

## See also

[DXVA2_DecodeBufferDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_decodebufferdesc)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)