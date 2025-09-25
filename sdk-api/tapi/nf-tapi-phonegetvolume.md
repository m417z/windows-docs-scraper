# phoneGetVolume function

## Description

The
**phoneGetVolume** function returns the volume setting of the specified phone's hookswitch device.

## Parameters

### `hPhone`

Handle to the open phone device.

### `dwHookSwitchDev`

A single hookswitch device whose volume level is queried. This parameter uses one of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `lpdwVolume`

Pointer to a **DWORD**. The function returns the current volume setting of the hookswitch device in this location. This is a number in the range 0x00000000 (silence) to 0x0000FFFF (maximum volume). The actual granularity and quantization of volume settings in this range are service provider-specific.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPHONESTATE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_OPERATIONFAILED, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONUNAVAIL.

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)