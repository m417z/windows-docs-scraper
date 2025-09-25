# TSPI_phoneSetRing function

## Description

The
**TSPI_phoneSetRing** function rings the specified open phone device using the specified ring mode and volume.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone to be rung.

### `dwRingMode`

The ringing pattern with which to ring the phone. This parameter must be within the range from zero through the value of the **dwNumRingModes** member in the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure. If **dwNumRingModes** is zero, the ring mode of the phone cannot be controlled; if **dwNumRingModes** is 1, a value of 0 for *dwRingMode* indicates that the phone should not be rung (silence), and other values from 1 through **dwNumRingModes** are valid ring modes for the phone device.

### `dwVolume`

The volume level with which the phone is to be rung. This is a number in the range from 0x00000000 (silence) through 0x0000FFFF (maximum volume). The actual granularity and quantization of volume settings in this range are service-provider specific. A value for *dwVolume* that is out of range is clamped by TAPI to the nearest value in range.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALRINGMODE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## Remarks

The service provider defines the actual audible ringing patterns corresponding to each of the phone's ring modes.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneGetRing](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetring)