# lineGetStatusMessages function

## Description

The
**lineGetStatusMessages** function enables an application to query which notification messages the application is set up to receive for events related to status changes for the specified line or any of its addresses.

## Parameters

### `hLine`

Handle to the line device.

### `lpdwLineStates`

Bit array that identifies for which line device status changes a message is to be sent to the application. If a flag is **TRUE**, that message is enabled; if **FALSE**, it is disabled. This parameter uses one or more of the
[LINEDEVSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevstate--constants).

### `lpdwAddressStates`

Bit array that identifies for which address status changes a message is to be sent to the application. If a flag is **TRUE**, that message is enabled; if **FALSE**, disabled. This parameter uses one or more of the
[LINEADDRESSSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressstate--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

TAPI defines a number of messages that notify applications about events occurring on lines and addresses. An application may not be interested in receiving all address and line status change messages. The
[lineSetStatusMessages](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetstatusmessages) function can be used to select which messages the application wants to receive. By default, address status and line status reporting is disabled.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/line-close)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineSetStatusMessages](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetstatusmessages)