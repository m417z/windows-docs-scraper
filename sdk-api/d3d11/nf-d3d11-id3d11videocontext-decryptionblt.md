# ID3D11VideoContext::DecryptionBlt

## Description

Writes encrypted data to a protected surface.

## Parameters

### `pCryptoSession` [in]

A pointer to the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface.

### `pSrcSurface` [in]

A pointer to the surface that contains the source data.

### `pDstSurface` [in]

A pointer to the protected surface where the encrypted data is written.

### `pEncryptedBlockInfo` [in]

A pointer to a [D3D11_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_encrypted_block_info) structure, or **NULL**.

If the driver supports partially encrypted buffers, *pEncryptedBlockInfo* indicates which portions of the buffer are encrypted. If the entire surface is encrypted, set this parameter to **NULL**.

To check whether the driver supports partially encrypted buffers, call [ID3D11VideoDevice::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getcontentprotectioncaps) and check for the **D3D11_CONTENT_PROTECTION_CAPS_PARTIAL_DECRYPTION** capabilities flag. If the driver does not support partially encrypted buffers, set this parameter to **NULL**.

### `ContentKeySize` [in]

The size of the encrypted content key, in bytes.

### `pContentKey` [in]

A pointer to a buffer that contains a content encryption key, or **NULL**. To query whether the driver supports the use of content keys, call [ID3D11VideoDevice::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getcontentprotectioncaps) and check for the **D3D11_CONTENT_PROTECTION_CAPS_CONTENT_KEY** capabilities flag.

If the driver supports content keys, use the content key to encrypt the surface. Encrypt the content key using the session key, and place the resulting cipher text in *pContentKey*. If the driver does not support content keys, use the session key to encrypt the surface and set *pContentKey* to **NULL**.

### `IVSize` [in]

The size of the *pIV* buffer, in bytes.

### `pIV` [in]

A pointer to a buffer that contains the initialization vector (IV).

For 128-bit AES-CTR encryption, *pIV* points to a [D3D11_AES_CTR_IV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_aes_ctr_iv) structure. The caller allocates the structure and generates the IV. When you generate the first IV, initialize the structure to a random number. For each subsequent IV, simply increment the **IV** member of the structure, ensuring that the value always increases. This procedure enables the driver to validate that the same IV is never used more than once with the same key pair.

For other encryption types, a different structure might be used, or the encryption might not use an IV.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Not all hardware or drivers support this functionality for all cryptographic types. This function can only be called when the [D3D11_CONTENT_PROTECTION_CAPS_DECRYPTION_BLT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_content_protection_caps) cap is reported.

This method does not support writing to sub-rectangles of the surface.

If the hardware and driver support a content key:

* The data is encrypted by the caller using the content key.
* The content key is encrypted by the caller using the session key.
* The encrypted content key is passed to the driver.

Otherwise, the data is encrypted by the caller using the session key and NULL is passed as the content key.

If the driver and hardware support partially encrypted buffers, *pEncryptedBlockInfo* indicates which portions of the buffer are encrypted and which is not. If the entire buffer is encrypted, *pEncryptedBlockinfo* should be **NULL**.

The [D3D11_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_encrypted_block_info) allows the application to indicate which bytes in the buffer are encrypted. This is specified in bytes, so the application must ensure that the encrypted blocks match the GPU’s crypto block alignment.

This function does not honor a D3D11 predicate that may have been set.

If the application uses [D3D11 queries](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_query), this function may not be accounted for with **D3D11_QUERY_EVENT** and **D3D11_QUERY_TIMESTAMP** when using feature levels lower than 11. **D3D11_QUERY_PIPELINE_STATISTICS** will not include this function for any feature level.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)