# PFND3DDDI_GETPITCH callback function

## Description

The *GetPitch* function retrieves the pitch of a protected or non-lockable surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_GETPITCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getpitch) structure that describes the protected surface.

## Return value

The *GetPitch* function returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The pitch of the protected surface is successfully retrieved.|
|D3DDDIERR_NOTAVAILABLE|The driver does not support the GetPitch function.|

## Remarks

Hardware and drivers can optionally support the *GetPitch* function.

The surface for which the *GetPitch* function returns the pitch can be non-lockable or protected. Therefore, the application cannot retrieve the pitch of the surface through a call to the driver's [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function. The application must retrieve the pitch of the surface to properly allocate the system memory buffer that the application subsequently uses in calls to the driver's [EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt) and [DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt) functions.

## See also

[D3DDDIARG_GETPITCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getpitch)

[DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt)

[EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt)