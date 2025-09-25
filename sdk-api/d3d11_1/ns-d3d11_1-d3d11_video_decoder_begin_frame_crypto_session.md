## Description

Provides data to the [ID3D11VideoContext::DecoderBeginFrame](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-decoderbeginframe) method.

## Members

### `pCryptoSession`

A pointer to the ID3D11CryptoSession interface. To get this pointer, call [ID3D11VideoDevice1::CreateCryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-createcryptosession).

### `BlobSize`

The size of the memory buffer referenced by the *pBlob* member.

### `pBlob`

The definition of this buffer is dependent on the implementation of the secure execution environment. It could contain a sealed key blob or any other per-key data that the secure execution environment needs to pass to the decode API.

The definition of this buffer is dependent on the implementation of the secure environment. It may contain data specific to the current frame.

### `pKeyInfoId`

A pointer to a GUID identifying the hardware key.

### `PrivateDataSize`

The size of the memory buffer referenced by the *pPrivateData* member.

### `pPrivateData`

## Remarks

This structure is passed in the *pContentKey* parameter of the [ID3D11VideoContext::DecoderBeginFrame](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-decoderbeginframe) function when [D3D11_DECODER_ENCRYPTION_HW_CENC](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-guids) is specified in the **guidConfigBitstreamEncryption** member of the [D3D11_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_config) structure when creating the video decoder interface.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)