# PFND3D11_1DDI_DESTROYCRYPTOSESSION callback function

## Description

Releases resources for the cryptographic session that were created through a call to the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCryptoSession`

A handle to the driver's private data for the cryptographic session. This handle was created by the Direct3D runtime and passed to the driver in the call to [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession).