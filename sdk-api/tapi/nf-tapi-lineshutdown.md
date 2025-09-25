# lineShutdown function

## Description

The
**lineShutdown** function shuts down the application's usage of the line abstraction of the API.

## Parameters

### `hLineApp`

Application's usage handle for the line API.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALAPPHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

If this function is called when the application has lines open or calls active, the call handles are deleted and TAPI automatically performs the equivalent of a
[lineClose](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineclose) on each open line. However, it is recommended that applications explicitly close all open lines before invoking
**lineShutdown**. If shutdown is performed while asynchronous requests are outstanding, those requests are canceled.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineClose](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineclose)