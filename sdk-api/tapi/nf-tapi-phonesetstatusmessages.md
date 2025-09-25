# phoneSetStatusMessages function

## Description

The
**phoneSetStatusMessages** function enables an application to monitor the specified phone device for selected status events.

## Parameters

### `hPhone`

Handle to the open phone device to be monitored.

### `dwPhoneStates`

Set of phone status changes and events for which the application can receive notification messages. This parameter can have zero, one, or more of the
[PHONESTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonestate--constants).

### `dwButtonModes`

Set of phone-button modes for which the application can receive notification messages. This parameter can have zero, one, or more of the
[PHONEBUTTONMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonmode--constants).

### `dwButtonStates`

Set of phone-button state changes for which the application can receive notification messages. If the *dwButtonModes* parameter is zero, *dwButtonStates* is ignored. If *dwButtonModes* has one or more bits set, this parameter must also have at least one bit set. This parameter uses the
[PHONEBUTTONSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonstate--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPHONESTATE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALBUTTONMODE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALBUTTONSTATE, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONUNAVAIL.

## Remarks

An application can use the
**phoneSetStatusMessages** function to enable or disable the generation of the corresponding messages. All phone status messages are disabled by default.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[PHONE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/phone-close)

[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps)

[phoneInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitialize)

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)

[phoneOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneopen)