# TSPI_phoneSetGain function

## Description

The
**TSPI_phoneSetGain** function sets the gain of the microphone of the specified hookswitch device to the specified gain level.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone containing the hookswitch device whose gain is to be set.

### `dwHookSwitchDev`

The hookswitch device whose microphone's gain is to be set. This parameter uses one and only one of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `dwGain`

A **DWORD**-sized location containing the desired new gain setting of the device. This is a number in the range from 0x00000000 (silence) through 0x0000FFFF (maximum volume). The actual granularity and quantization of gain settings in this range are service-provider-specific. A value for *dwGain* that is out of range is clamped by TAPI to the nearest in-range value.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)