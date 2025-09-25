# PFND3D11_1DDI_STARTSESSIONKEYREFRESH callback function

## Description

Gets a random number that can be used to refresh the session key.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCryptoSession`

A handle to the cryptographic session object that was created through a call to the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `RandomNumberSize`

The size, in bytes, of the number in the buffer that is referenced by the *pRandomNumber* parameter.

### `pRandomNumber`

A pointer to a buffer that contains the status sequence number for the random start.

## Remarks

The hardware and driver can optionally support **StartSessionKeyRefresh** for all cryptographic types.

When the Microsoft Direct3D runtime calls the driver's **StartSessionKeyRefresh** function, the driver generates and saves a random number and returns it in the buffer that the *pRandomNumber* parameter points to.

When the runtime subsequently calls the driver's [FinishSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh) function, the driver refreshes the session key by performing an XOR operation of the random number with the key.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[FinishSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh)