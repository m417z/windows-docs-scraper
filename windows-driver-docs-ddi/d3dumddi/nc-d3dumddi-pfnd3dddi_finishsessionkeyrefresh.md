# PFND3DDDI_FINISHSESSIONKEYREFRESH callback function

## Description

The *FinishSessionKeyRefresh* function indicates that all buffers from that point in time use the updated session key value.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_FINISHSESSIONKEYREFRESH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_finishsessionkeyrefresh) structure that describes the session.

## Return value

*FinishSessionKeyRefresh* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The session is successfully updated.|
|D3DDDIERR_NOTAVAILABLE|The driver does not support the FinishSessionKeyRefresh function.|

## Remarks

The hardware and driver can optionally support the *FinishSessionKeyRefresh* function for all crypto types.

When the Direct3D runtime calls the driver's [StartSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_startsessionkeyrefresh) function, the driver generates and saves a random number and returns the random number in the buffer that the **pRandomNumber** member of the [D3DDDIARG_STARTSESSIONKEYREFRESH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_startsessionkeyrefresh) structure points to.

When the runtime subsequently calls the driver's *FinishSessionKeyRefresh* function, the driver performs an XOR operation of the random number with the session key.

## See also

[D3DDDIARG_FINISHSESSIONKEYREFRESH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_finishsessionkeyrefresh)

[D3DDDIARG_STARTSESSIONKEYREFRESH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_startsessionkeyrefresh)

[StartSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_startsessionkeyrefresh)