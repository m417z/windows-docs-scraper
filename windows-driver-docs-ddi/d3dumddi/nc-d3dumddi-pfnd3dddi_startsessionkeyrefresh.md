# PFND3DDDI_STARTSESSIONKEYREFRESH callback function

## Description

The *StartSessionKeyRefresh* function returns a random number that the driver's [FinishSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh) function subsequently uses to perform an exclusive OR operation (XOR) with the session key.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_STARTSESSIONKEYREFRESH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_startsessionkeyrefresh) structure that contains information about the random number.

## Return value

*StartSessionKeyRefresh* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The random number is successfully returned.|
|D3DDDIERR_NOTAVAILABLE|The driver does not support the StartSessionKeyRefresh function.|

## Remarks

The hardware and driver can optionally support *StartSessionKeyRefresh* for all crypto types.

When the Direct3D runtime calls the driver's *StartSessionKeyRefresh* function, the driver generates and saves a random number and returns the random number in the buffer that the **pRandomNumber** member of the [D3DDDIARG_STARTSESSIONKEYREFRESH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_startsessionkeyrefresh) structure points to.

When the runtime subsequently calls the driver's [FinishSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh) function, the driver performs an XOR operation of the random number with the session key.

## See also

[D3DDDIARG_STARTSESSIONKEYREFRESH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_startsessionkeyrefresh)

[FinishSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh)