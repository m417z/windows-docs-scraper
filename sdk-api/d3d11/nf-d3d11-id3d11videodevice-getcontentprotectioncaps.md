# ID3D11VideoDevice::GetContentProtectionCaps

## Description

Queries the driver for its content protection capabilities.

## Parameters

### `pCryptoType` [in]

A pointer to a GUID that specifies the type of encryption to be used. The following GUIDs are defined.

| Value | Meaning |
| --- | --- |
| **D3D11_CRYPTO_TYPE_AES128_CTR** | 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher. |

If no encryption will be used, set this parameter to **NULL**.

### `pDecoderProfile` [in]

A pointer to a GUID that specifies the decoding profile. To get profiles that the driver supports, call [ID3D11VideoDevice::GetVideoDecoderProfile](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderprofile). If decoding will not be used, set this parameter to **NULL**.

The driver might disallow some combinations of encryption type and profile.

### `pCaps` [out]

A pointer to a [D3D11_VIDEO_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_content_protection_caps) structure. The method fills in this structure with the driver's content protection capabilities.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)