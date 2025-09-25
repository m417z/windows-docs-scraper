# PFND3D11_1DDI_CRYPTOSESSIONGETHANDLE callback function

## Description

Returns a handle for a cryptographic session.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCryptoSession`

A handle to the driver's private data for the cryptographic session. This handle was created by the Direct3D runtime and passed to the driver in the call to [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession).

### `pHandle`

A handle that is created by the driver for the cryptographic session.

## Return value

**CryptoSessionGetHandle** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The cryptographic session handle was returned successfully.|
|D3DDDIERR_DEVICEREMOVED|The graphics adapter was removed.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The **CryptoSessionGetHandle** function returns a driver-specified handle for the cryptographic session. This handle is used by the application when it associates the cryptographic session with the video decoder. This enables the decoder to decrypt data that is encrypted by using this session.

This function allows the driver to define its own handle to its state data for the cryptographic session. This bypasses any handle mapping that may be performed by the Direct3D runtime.

**Note** Drivers can return the same handle in the *pHandle* parameter that was passed in the *hCryptoSession* parameter.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)