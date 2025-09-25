# _D3DDDIARG_DECRYPTIONBLT structure

## Description

The D3DDDIARG_DECRYPTIONBLT structure describes the parameters of a decrypted bit-block transfer (bitblt) in a call to the [DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt) function.

## Members

### `hCryptoSession` [in]

A handle to the encryption session.

### `hSrcResource` [in]

A handle to the source resource.

### `SrcSubResourceIndex` [in]

The index to the source surface within the resource.

### `hDstResource` [in]

A handle to the destination resource.

### `DstSubResourceIndex` [in]

The index to the destination surface within the resource.

### `SrcResourceSize` [in]

The size, in bytes, of the source resource.

### `pEncryptedBlockInfo` [in]

A pointer to a [D3DDDIENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiencrypted_block_info) structure that describes the portions of the buffer that are encrypted.

### `pContentKey` [in]

A pointer to a block of memory that contains the content key that is required to decrypt the bitblt data. If **pContentKey** is **NULL**, hardware does not require a separate content key to decrypt the data. That is, the session key is used to encrypt the data.

### `pIV` [in]

A pointer to a block of memory that contains the initialization vector that is required to decrypt the bitblt data. If **pIV** is **NULL**, hardware does not require a separate initialization vector to decrypt the data. That is, the session key is used to encrypt the data.

## Remarks

A pointer to a populated D3DDDIARG_DECRYPTIONBLT structure is passed to the driver's [DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt) function to write data to a protected surface.

## See also

[D3DDDIENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiencrypted_block_info)

[DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt)