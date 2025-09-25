# TSPI_phoneGetHookSwitch function

## Description

The
**TSPI_phoneGetHookSwitch** function returns the current hookswitch mode of the specified open phone device.

## Parameters

### `hdPhone`

The service provider's opaque handle to the phone whose hookswitch mode is to be retrieved.

### `lpdwHookSwitchDevs`

A pointer to a **DWORD**-sized location into which the service provider writes the mode of the phone's hookswitch devices. This parameter uses one of the
[PHONEHOOKSWITCHDEV_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants). If a bit position is **FALSE**, the corresponding hookswitch device is onhook. If **TRUE**, the microphone and/or speaker part of the corresponding hookswitch device is offhook. To find out whether microphone and/or speaker are enabled, TAPI can use
[TSPI_phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetstatus).

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL.

## Remarks

After the hookswitch state of a device changes, and if hookswitch monitoring is enabled, TAPI is sent a PHONE_STATE message.

## See also

[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants)

[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus)

[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85))

[TSPI_phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetstatus)

[TSPI_phoneSetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesethookswitch)