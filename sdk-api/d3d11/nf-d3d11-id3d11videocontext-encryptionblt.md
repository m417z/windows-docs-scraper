# ID3D11VideoContext::EncryptionBlt

## Description

Reads encrypted data from a protected surface.

## Parameters

### `pCryptoSession` [in]

A pointer to the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface of the cryptographic session.

### `pSrcSurface` [in]

A pointer to the [ID3D11Texture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11texture2d) interface of the protected surface.

### `pDstSurface` [in]

A pointer to the [ID3D11Texture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11texture2d) interface of the surface that receives the encrypted data.

### `IVSize` [in]

The size of the *pIV* buffer, in bytes.

### `pIV` [in]

A pointer to a buffer that receives the initialization vector (IV). The caller allocates this buffer, but the driver generates the IV.

For 128-bit AES-CTR encryption, *pIV* points to a [D3D11_AES_CTR_IV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_aes_ctr_iv) structure. When the driver generates the first IV, it initializes the structure to a random number. For each subsequent IV, the driver simply increments the **IV** member of the structure, ensuring that the value always increases. The application can validate that the same IV is never used more than once with the same key pair.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Not all drivers support this method. To query the driver capabilities, call [ID3D11VideoDevice::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getcontentprotectioncaps) and check for the **D3D11_CONTENT_PROTECTION_CAPS_ENCRYPTED_READ_BACK**
flag in the **Caps** member of the [D3D11_VIDEO_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_content_protection_caps) structure.

Some drivers might require a separate key to decrypt the data that is read back. To check for this requirement, call [GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getcontentprotectioncaps) and check for the **D3D11_CONTENT_PROTECTION_CAPS_ENCRYPTED_READ_BACK_KEY**
flag. If this flag is present, call [ID3D11VideoContext::GetEncryptionBltKey](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-getencryptionbltkey) to get the decryption key.

This method has the following limitations:

* Reading back sub-rectangles is not supported.
* Reading back partially encrypted surfaces is not supported.
* The protected surface must be either an off-screen plain surface or a render target.
* The destination surface must be a [D3D11_USAGE_STAGING](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d11-usage) resource.
* The protected surface cannot be multisampled.
* Stretching and colorspace conversion are not supported.

This function does not honor a D3D11 predicate that may have been set.

If the application uses [D3D11 queries](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_query), this function may not be accounted for with **D3D11_QUERY_EVENT** and **D3D11_QUERY_TIMESTAMP** when using feature levels lower than 11. **D3D11_QUERY_PIPELINE_STATISTICS** will not include this function for any feature level.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)