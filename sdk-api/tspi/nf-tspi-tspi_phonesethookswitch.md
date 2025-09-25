# TSPI_phoneSetHookSwitch function

## Description

The
**TSPI_phoneSetHookSwitch** function sets the hook state of the specified open phone's hookswitch devices to the specified mode. Only the hookswitch state of the hookswitch devices listed is affected.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone containing the hookswitch devices whose modes are to be set.

### `dwHookSwitchDevs`

The device(s) whose hookswitch mode is to be set. This parameter uses one of the
[PHONEHOOKSWITCHDEV_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `dwHookSwitchMode`

The hookswitch mode to set. This parameter can have only one of the
[PHONEHOOKSWITCHMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants).

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALHOOKSWITCHMODE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONUNAVAIL.

## Remarks

The hookswitch mode is changed to the indicated setting for all devices specified. If different settings are desired, this function can be invoked multiple times with a different set of parameters. A
[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85)) message is sent to the application after the hookswitch state has changed.

## See also

[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants)

[PHONEHOOKSWITCHMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants)

[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus)

[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85))

[TSPI_phoneGetHookSwitch](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegethookswitch)