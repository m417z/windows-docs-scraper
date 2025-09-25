# phoneGetStatusMessages function

## Description

The
**phoneGetStatusMessages** function returns which phone-state changes on the specified phone device generate a callback to the application.

## Parameters

### `hPhone`

Handle to the open phone device to be monitored.

### `lpdwPhoneStates`

Pointer to a **DWORD** holding zero, one or more of the
[PHONESTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonestate--constants). These flags specify the set of phone status changes and events for which the application can receive notification messages. Monitoring can be individually enabled and disabled.

### `lpdwButtonModes`

Pointer to a **DWORD** containing flags that specify the set of phone-button modes for which the application can receive notification messages. This parameter uses zero, one or more of the
[PHONEBUTTONMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonmode--constants).

### `lpdwButtonStates`

Pointer to a **DWORD** that contains flags specifying the set of phone button state changes for which the application can receive notification messages. This parameter uses zero, one or more of the
[PHONEBUTTONSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonstate--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_OPERATIONFAILED, PHONEERR_UNINITIALIZED.

## Remarks

An application can use
**phoneGetStatusMessages** to query the generation of the corresponding messages. Message generation can be controlled by
**phoneGetStatusMessages**. All phone status messages are disabled by default.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[PHONE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/phone-close)

[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps)

[phoneSetStatusMessages](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonesetstatusmessages)