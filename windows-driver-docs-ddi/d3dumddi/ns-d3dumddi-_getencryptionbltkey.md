# _GETENCRYPTIONBLTKEY structure

## Description

The _GETENCRYPTIONBLTKEY structure describes an encrypted bit-block transfer (bitblt) session for which the [GetEncryptionBltKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getencryptionbltkey) function retrieves the encryption key.

## Members

### `hCryptoSession` [in]

A handle to the encryption session that is created in a call to the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `pReadBackKey` [in]

A pointer to a buffer that contains the encryption key.

### `KeySize` [in]

The size, in bytes, of the encryption key that the **pReadBackKey** member points to.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[GetEncryptionBltKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getencryptionbltkey)