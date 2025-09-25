# _D3DDDIARG_STARTSESSIONKEYREFRESH structure

## Description

The D3DDDIARG_STARTSESSIONKEYREFRESH structure contains information about the random number for the encryption session.

## Members

### `hCryptoSession` [in]

A handle to the encryption session that is created in a call to the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `pRandomNumber` [out]

A pointer to a buffer that contains the status sequence number for the random start.

### `RandomNumberSize` [in/out]

The size, in bytes, of the number that the **pRandomNumber** member points to.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)