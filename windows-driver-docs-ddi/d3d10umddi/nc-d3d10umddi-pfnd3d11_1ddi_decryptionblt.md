# PFND3D11_1DDI_DECRYPTIONBLT callback function

## Description

Writes encrypted data to a protected surface. This function is called only if **D3D11_1DDI_CONTENT_PROTECTION_CAPS_DECRYPTION_BLT** is set in the **Caps** member of the [D3D11_1DDI_VIDEO_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_content_protection_caps) structure.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCryptoSession`

A handle to the driver's private data for the cryptographic session. This handle was created by the Direct3D runtime and passed to the driver in the call to the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `hSrcResource`

A handle to the resource that contains the source data.

### `hDstResource`

A pointer to the resource where the encrypted data is to be written.

### `pEncryptedBlockInfo`

A pointer to a [D3D11_1DDI_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_encrypted_block_info) structure that describes the portions of the buffer that are encrypted.

**Note** If the entire buffer is encrypted, *pEncryptedBlockinfo* should be set to NULL.

### `ContentKeySize`

The size, in bytes, of the content key.

### `pContentKey`

A pointer to a block of memory that contains the content key that is required to decrypt the bit-block transfer (bitblt) data.

If *pContentKey* is not set to NULL, the buffer data is encrypted by using the specified content key. The data for this key is encrypted by using the session key with the AES-ECB algorithm.

If *pContentKey* is NULL, the graphics adapter does not require a separate content key to decrypt the data. In this case, the session key is used to decrypt the data.

### `IVSize`

The size, in bytes, of the initialization vector (IV).

### `pIV`

A pointer to a block of memory that contains the initialization vector that is required to decrypt the bitblt data. For more information, see the Remarks section.

**Note**

If *pIV* is NULL, the graphics adapter does not require a separate initialization vector to decrypt the data. That is, the session key is used to decrypt the data.

## Remarks

For 128-bit AES-CTR encryption, the *pIV* parameter points to a [D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv) structure that is allocated by the application. However, the actual contents of this structure are filled in by the driver or graphics adapter. When the first IV is generated, the driver or adapter initializes the **IV** member of this structure to a random number. For each subsequent IV, the caller increments the **IV** member, ensuring that the value always increases. This procedure enables the application to validate that the same IV is never used more than once with the same key pair.

For other encryption types, a different structure might be used, or the encryption might not use an IV.

**Note** This function does not honor a Direct3D version 11 predicate that may have been set.

## See also

[D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv)

[D3D11_1DDI_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_encrypted_block_info)

[D3D11_1DDI_VIDEO_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_content_protection_caps)