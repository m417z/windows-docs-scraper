# _D3DDDIARG_ENCRYPTIONBLT structure

## Description

The D3DDDIARG_ENCRYPTIONBLT structure describes the parameters of an encrypted bit-block transfer (bitblt) in a call to the [EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt) function.

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

### `DstResourceSize` [in]

The size, in bytes, of the destination resource.

### `pIV` [out]

A pointer to a block of memory in which [EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt) returns the initialization vector that is required to decrypt the bitblt data. If **pIV** is **NULL**, hardware does not require a separate key to decrypt the data that is read back.

## See also

[EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt)