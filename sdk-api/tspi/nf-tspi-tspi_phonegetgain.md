# TSPI_phoneGetGain function

## Description

The
**TSPI_phoneGetGain** function returns the gain setting of the microphone of the specified phone's hookswitch device.

## Parameters

### `hdPhone`

The handle to the phone whose gain is to be retrieved.

### `dwHookSwitchDev`

The hookswitch device whose gain level is queried. This parameter may be one and only one of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `lpdwGain`

A pointer to a **DWORD**-sized location into which the service provider writes the current gain setting of the hookswitch microphone component. The *dwGain* gain parameter specifies the volume level of the hookswitch device. This is a number in the range from 0x00000000 (silence) through 0x0000FFFF (maximum volume). The actual granularity and quantization of gain settings in this range are service provider-specific.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneSetGain](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetgain)