# _D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE structure

## Description

The D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE structure describes a buffer that contains the session key, which is used for encryption.

## Members

### `hCryptoSession` [in]

A handle to the encryption session that is the runtime creates when the runtime calls the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `DataSize` [in/out]

The size, in bytes, of the data that the **pData** member points to.

### `pData` [in/out]

A pointer to a buffer that contains the session key.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)