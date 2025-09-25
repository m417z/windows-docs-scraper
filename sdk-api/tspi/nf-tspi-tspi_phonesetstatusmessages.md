# TSPI_phoneSetStatusMessages function

## Description

The
**TSPI_phoneSetStatusMessages** function causes the service provider to filter status messages that are not currently of interest to any application.

## Parameters

### `hdPhone`

The opaque handle to the phone whose state-change monitoring filter is to be set.

### `dwPhoneStates`

Flags that specify the set of phone status changes and events for which TAPI wants to receive notification messages. This parameter can have zero, one, or more than one of the
[PHONESTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonestate--constants).

### `dwButtonModes`

Flags that specify the set of phone button modes for which TAPI wants to receive notification messages. If *dwButtonModes* is zero, *dwButtonStates* is ignored. This parameter can have zero, one, or more than one of the
[PHONEBUTTONMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonmode--constants). If *dwButtonModes* has at least one of these flags set, *dwButtonStates* must also have at least one bit set:

### `dwButtonStates`

This parameter specifies the set of phone button state changes for which TAPI wishes to receive notification messages, one of the
[PHONEBUTTONSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonstate--constants).

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPHONESTATE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALBUTTONMODE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALBUTTONSTATE, PHONEERR_OPERATIONUNAVAIL.

## Remarks

TAPI defines a number of messages that notify applications about events occurring on phones. The sets of all change messages in which all applications are interested can be much smaller than the set of possible messages. This procedure allows TAPI to tell the service provider the reduced set of messages to deliver. The service provider delivers all of the messages it supports, within the specified set. It is permitted to deliver more (they are filtered out by TAPI), but is discouraged from doing so for performance reasons. If TAPI requests delivery of a particular message type that is not produced by the provider, the provider nevertheless accepts the request but simply does not produce the message. All phone status messages except PHONESTATE_REINIT are disabled by default.

## See also

[PHONESTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonestate--constants)

[PHONE_BUTTON](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725254(v=vs.85))

[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85))