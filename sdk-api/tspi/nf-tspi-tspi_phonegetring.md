# TSPI_phoneGetRing function

## Description

The
**TSPI_phoneGetRing** function enables an application to query the specified open phone device as to its current ring mode.

## Parameters

### `hdPhone`

The handle to the phone whose ring mode is to be queried.

### `lpdwRingMode`

The ringing pattern with which the phone is ringing. Zero indicates that the phone is not ringing.

### `lpdwVolume`

The volume level with which the phone is ringing. This is a number in the range from 0x00000000 (silence) through 0x0000FFFF (maximum volume). The actual granularity and quantization of volume settings in this range are service-provider specific.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL.

## Remarks

The service provider defines the actual audible ringing patterns corresponding to each of phone's ring modes.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneSetRing](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetring)