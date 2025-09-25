# DXVA2_AES_CTR_IV structure

## Description

Contains an initialization vector (IV) for 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher encryption.

## Members

### `IV`

The IV, in big-endian format.

### `Count`

The block count, in big-endian format.

## Remarks

For AES-CTR encryption, the **pvPVPState** member of the [DXVA2_DecodeBufferDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_decodebufferdesc) structure points to a **DXVA2_AES_CTR_IV** structure.

The [D3DAES_CTR_IV](https://learn.microsoft.com/windows/desktop/medfound/d3daes-ctr-iv) structure and the **DXVA2_AES_CTR_IV** structure are equivalent.

### Sequential Counts

If the [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method returns the **D3DCPCAPS_SEQUENTIAL_CTR_IV** flag, the caller should keep **IV** unchanged when submitting multiple buffers for the same video frame, and **Count** should be in sequential order of the previous submission for the frame.

Example: Suppose the software decoder submits three buffers for a single frame, and that each buffer contains three 128-bit blocks. For the first buffer, **IV** can be any value. For the next two buffers, the same value of **IV** must be used. The value of **Count** starts at 1. For the second buffer, **Count** equals 4 (1 + 3 blocks from the first submission). For the third buffer, **Count** equals 7 (4 + 3 blocks from the second submission).

When the **D3DCPCAPS_SEQUENTIAL_CTR_IV** capability is present, it is recommended to submit data in 128-bit blocks.

## See also

[DXVA2_DecodeBufferDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_decodebufferdesc)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)