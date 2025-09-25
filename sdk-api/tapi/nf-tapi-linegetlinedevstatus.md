# lineGetLineDevStatus function

## Description

The
**lineGetLineDevStatus** function enables an application to query the specified open line device for its current status.

## Parameters

### `hLine`

Handle to the open line device to be queried.

### `lpLineDevStatus`

Pointer to a variably sized data structure of type
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus). Upon successful completion of the request, this structure is filled with the line's device status. Prior to calling
**lineGetLineDevStatus**, the application should set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL.

## Remarks

An application uses
**lineGetLineDevStatus** to query the line device for its current line status. This status information applies globally to all addresses on the line device. Use
[lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddressstatus) to determine status information about a specific address on a line.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddressstatus)