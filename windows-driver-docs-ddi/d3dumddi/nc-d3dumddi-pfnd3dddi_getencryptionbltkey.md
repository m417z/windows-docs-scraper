# PFND3DDDI_GETENCRYPTIONBLTKEY callback function

## Description

The *GetEncryptionBltKey* function returns the key that is used to decrypt the data that the driver's [EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt) function returns.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_GETENCRYPTIONBLTKEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_getencryptionbltkey) structure that describes the key for an encrypted session.

## Return value

*GetEncryptionBltKey* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The key for an encrypted session is successfully retrieved.|
|D3DDDIERR_NOTAVAILABLE|The driver does not support the GetEncryptionBltKey function.|

## Remarks

The hardware and driver can optionally support the *GetEncryptionBltKey* function for all crypto types.

Each time the Direct3D runtime calls the driver's *GetEncryptionBltKey* function, the driver should generate a new read-back key. If the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function previously created the encryption session with the **CryptoType** member of the [D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession) structure set to D3DCRYPTOTYPE_AES128_CTR, the driver and hardware should encrypt the read-back key with the session key.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession)

[D3DDDIARG_GETENCRYPTIONBLTKEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_getencryptionbltkey)

[EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt)