# TSPI_phoneGetVolume function

## Description

The
**TSPI_phoneGetVolume** function returns the volume setting of the specified phone's hookswitch device.

## Parameters

### `hdPhone`

The handle to the phone containing the hookswitch device whose volume setting is to be retrieved.

### `dwHookSwitchDev`

Identifies a single hookswitch device whose volume level is queried. This parameter uses one of the
[PHONEHOOKSWITCHDEV_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `lpdwVolume`

A pointer to a **DWORD**-sized location into which the service provider writes the current volume setting of the hookswitch device. This is a number in the range from 0x00000000 (silence) through 0x0000FFFF (maximum volume). The actual granularity and quantization of volume settings in this range are service-provider specific.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneSetVolume](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetvolume)