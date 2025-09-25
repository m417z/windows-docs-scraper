# D3DWDDM2_0DDI_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION structure

## Description

**D3DWDDM2_0DDI_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION** is used along with [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) to perform crypto operations into and out of protected memory.

## Members

### `hCryptoSession`

A handle to a cryptographic session object created using [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession).

### `pBlob`

A pointer to an IHV-defined blob allocated by an upstream DRM component. The blob identifies the sealed decryption key to be used for the current frame.

### `BlobSize`

Size of the IHV-defined blob referenced in the **pBlob** member.

### `pKeyInfoId`

A pointer to a **GUID** identifying the hardware key.

### `pPrivateData`

The definition of this buffer is dependent on the implementation of the secure environment. It may contain data specific to the current frame.

### `PrivateDataSize`

Contains the size of the memory buffer referenced by the **pPrivateData** member.

## Remarks

A pointer to this structure is passed in the **pContentKey** member of the [D3D11_1DDIARG_VIDEODECODERBEGINFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_videodecoderbeginframe) structure when **D3DWDDM2_0DDI_DECODER_ENCRYPTION_HW_CENC** is specified in the **guidConfigBitstreamEncryption** member of the [D3D11_1DDI_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_config) structure when creating the video decoder object.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[D3D11_1DDIARG_VIDEODECODERBEGINFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_videodecoderbeginframe)

[D3D11_1DDI_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_config)