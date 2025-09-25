# PFND3DWDDM2_0DDI_GETDATAFORNEWHARDWAREKEY callback function

## Description

Allows the driver to return independent hardware vendor (IHV)-specific information used when initializing the new hardware key.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hCryptoSession`

A handle to the cryptographic session object that was created through a call to the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `PrivateInputSize`

The size of the buffer pointed to by **pPrivatInputData**, in bytes.

### `pPrivatInputData`

A pointer to a buffer that receives private input data for the driver.

### `pPrivateOutputData`

A pointer to a UINT64 value that receives private driver output data that could be used later by the secure DRM component when initializing the key.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|Private driver data was successfully returned.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)