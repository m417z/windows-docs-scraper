# lineSetStatusMessages function

## Description

The
**lineSetStatusMessages** function enables an application to specify which notification messages to receive for events related to status changes for the specified line or any of its addresses.

## Parameters

### `hLine`

Handle to the line device.

### `dwLineStates`

Bit array that identifies for which line-device status changes a message is to be sent to the application. This parameter uses one or more of the
[LINEDEVSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevstate--constants).

### `dwAddressStates`

Bit array that identifies for which address status changes a message is to be sent to the application. This parameter uses one or more of the
[LINEADDRESSSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressstate--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESSSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALLINESTATE, LINEERR_UNINITIALIZED, LINEERR_NOMEM, LINEERR_OPERATIONUNAVAIL.

## Remarks

TAPI defines a number of messages that notify applications about events occurring on lines and addresses. An application may not be interested in receiving all address and line status change messages. The
**lineSetStatusMessages** function can be used to select which messages the application receives. By default, address and line status reporting is disabled.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/line-close)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitialize)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen)