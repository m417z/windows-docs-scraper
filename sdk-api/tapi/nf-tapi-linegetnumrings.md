# lineGetNumRings function

## Description

The
**lineGetNumRings** function determines the number of rings an incoming call on the given address should ring prior to answering the call.

## Parameters

### `hLine`

Handle to the open line device.

### `dwAddressID`

Address on the line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lpdwNumRings`

Number of rings that is the minimum of all current
[lineSetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetnumrings) requests.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

The
**lineGetNumRings** and
[lineSetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetnumrings) functions, when used in combination, provide a mechanism to support the implementation of toll-saver features across multiple independent applications.

An application that receives a handle for a call in the *offering* state and a
[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate) *ringing* message should wait a number of rings equal to the number returned by
**lineGetNumRings** before answering the call in order to honor the toll-saver settings across all applications. The
**lineGetNumRings** function returns the minimum of all applications' number of rings specified by
[lineSetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetnumrings). Because this number can vary dynamically, an application should invoke
**lineGetNumRings** each time it has the option to answer a call. If no application has called
[lineSetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetnumrings), the number of rings returned is 0xFFFFFFFF. A separate LINE_LINEDEVSTATE *ringing* message is sent to the application for each ring cycle.

If call classification is performed by TAPI of answering all calls of unknown media mode and filtering the media stream, TAPI honors this number as well.

**Note** This operation is purely informational and does not in itself affect the state of any calls on the line device.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineSetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetnumrings)