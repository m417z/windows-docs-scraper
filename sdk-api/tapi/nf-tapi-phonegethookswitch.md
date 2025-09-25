# phoneGetHookSwitch function

## Description

The
**phoneGetHookSwitch** function returns the current hookswitch mode of the specified open phone device.

## Parameters

### `hPhone`

Handle to the open phone device.

### `lpdwHookSwitchDevs`

Pointer to a **DWORD** to be filled with the mode of the phone's hookswitch devices. If a bit position is **FALSE**, the corresponding hookswitch device is onhook; if **TRUE**, the microphone and/or speaker part of the corresponding hookswitch device is offhook. To find out whether the microphone and/or speaker are enabled, the application can use
[phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetstatus). This parameter uses one or more of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_OPERATIONUNAVAIL, PHONEERR_UNINITIALIZED.

## Remarks

After the hookswitch state of a device changes, and if hookswitch monitoring is enabled, the application is sent a
[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state) message.

## See also

[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneGetStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetstatus)