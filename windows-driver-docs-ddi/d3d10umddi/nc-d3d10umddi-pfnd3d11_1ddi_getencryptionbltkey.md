# PFND3D11_1DDI_GETENCRYPTIONBLTKEY callback function

## Description

Queries the key that is used to decrypt the data returned by the [EncryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_encryptionblt) function.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCryptoSession`

A handle to the cryptographic session that was created in a call to the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `KeySize`

The size, in bytes, of the encryption key that the *pReadBackKey* parameter points to.

### `pReadbackKey`

A pointer to a buffer that contains the encryption key.

## Remarks

When the **GetEncryptionBltKey** function is called, the display miniport driver should generate a new encryption key. If the cryptographic session is using the **D3DCRYPTOTYPE_AES128_CTR** cryptographic type, the driver or graphics adapter should encrypt the data that is referenced by the *pReadbackKey* parameter by using the session key with the AES-ECB algorithm.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[EncryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_encryptionblt)