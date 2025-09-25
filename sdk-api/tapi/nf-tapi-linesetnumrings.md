# lineSetNumRings function

## Description

The
**lineSetNumRings** function sets the number of rings that must occur before an incoming call is answered. This function can be used to implement a toll-saver-style function. It allows multiple independent applications to each register the number of rings. The function
[lineGetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnumrings) returns the minimum number of rings requested. It can be used by the application that answers incoming calls to determine the number of rings it should wait before answering the call.

## Parameters

### `hLine`

Handle to the open line device.

### `dwAddressID`

Address on the line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwNumRings`

Number of rings before a call should be answered in order to honor the toll-saver requests from all applications.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALADDRESSID, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

The
[lineGetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnumrings) and
**lineSetNumRings** functions, when used in combination, provide a mechanism to support the implementation of toll-saver features across multiple independent applications. If no application ever calls
**lineSetNumRings**,
[lineGetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnumrings) returns 0xFFFFFFFF.

An application that is the owner of a call in the *offering* state and that received a
[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate) *ringing* message should wait a number of rings equal to the number returned by
[lineGetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnumrings) before answering the call in order to honor the toll-saver settings across all applications. A separate LINE_LINEDEVSTATE *ringing* message is sent to the application for each ring cycle, so the application should count these messages. If this call disconnects before being answered, and another call comes in shortly thereafter, the
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message should allow the application to determine that ringing is related to the second call.

If call classification is performed by TAPI by means of answering incoming calls of unknown media type and filtering the media stream, TAPI honors this number as well.

**Note** This operation is purely informational and does not affect the state of any calls on the line device.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnumrings)