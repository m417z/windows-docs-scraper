# phoneGetRing function

## Description

The
**phoneGetRing** function enables an application to query the specified open phone device as to its current ring mode.

## Parameters

### `hPhone`

Handle to the open phone device.

### `lpdwRingMode`

Ringing pattern with which the phone is ringing. Zero indicates that the phone is not ringing.

### `lpdwVolume`

Volume level with which the phone is ringing. This is a number in the range 0x00000000 (silence) to 0x0000FFFF (maximum volume). The actual granularity and quantization of volume settings in this range are service provider-specific.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPHONESTATE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_OPERATIONFAILED, PHONEERR_OPERATIONUNAVAIL, PHONEERR_UNINITIALIZED.

## Remarks

The service provider defines the actual audible ringing patterns corresponding to each of the phone's ring modes.

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)