# PFND3DDDI_DESTROYCRYPTOSESSION callback function

## Description

The **DestroyCryptoSession** function releases resources for the encryption session that the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function creates.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DESTROYCRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroycryptosession) structure that contains one member that specifies the handle to the encryption session to destroy.

## Return value

**DestroyCryptoSession** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The encryption session is successfully destroyed.|
|E_OUTOFMEMORY|DestroyCryptoSession could not allocate the required memory for it to complete.|

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[D3DDDIARG_DESTROYCRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroycryptosession)