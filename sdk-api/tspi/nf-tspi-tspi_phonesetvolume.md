# TSPI_phoneSetVolume function

## Description

The
**TSPI_phoneSetVolume** function sets the volume of the speaker component of the specified hookswitch device to the specified level.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone containing the speaker whose volume is to be set.

### `dwHookSwitchDev`

Identifies the hookswitch device whose speaker's volume is to be set. This parameter uses one of the
[PHONEHOOKSWITCHDEV_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `dwVolume`

A **DWORD** specifying the new volume level of the hookswitch device. This is a number in the range from 0x00000000 (silence) through 0x0000FFFF (maximum volume). The actual granularity and quantization of volume settings in this range are service-provider specific. A value for *dwVolume* that is out of range is clamped by TAPI to the nearest value in range.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## Remarks

None.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)