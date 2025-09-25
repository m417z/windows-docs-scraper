# PFND3D11_1DDI_GETCONTENTPROTECTIONCAPS callback function

## Description

Queries the available content protection for a specified encryption algorithm and video decoder profile.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `pCryptoType`

A pointer to a GUID that specifies the type of encryption algorithm to query.

### `pDecodeProfile`

A pointer to a GUID that specifies the decoder profile to query.

### `pCaps`

A pointer to a [D3D11_1DDI_VIDEO_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_content_protection_caps) structure that contains the protection capabilities for the specified encryption algorithm and decoder profile.

## Return value

**GetContentProtectionCaps** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The content protection capabilities were queried successfully.|
|D3DERR_INVALID_CRYPTO|The encryption algorithm specified by the pCryptoType parameter is not supported.|

## Remarks

The *pCryptoType* parameter can contain one of the following values:

* D3DCRYPTOTYPE_AES128_CTR if the driver is configured to use the 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher.

* D3DCRYPTOTYPE_PROPRIETARY if the driver is configured to use a proprietary encryption algorithm.

* NULL_GUID if the driver is not configured to use any encryption algorithm.

> [!NOTE]
> The Microsoft Direct3D runtime verifies that the *pDecodeProfile* and *pCryptoType* parameter data is valid before it calls the [GetContentProtectionCaps]() function.

## See also

[D3D11_1DDI_VIDEO_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_content_protection_caps)