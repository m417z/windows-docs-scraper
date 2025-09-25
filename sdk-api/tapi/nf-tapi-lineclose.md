# lineClose function

## Description

The
**lineClose** function closes the specified open line device.

## Parameters

### `hLine`

Handle to the open line device to be closed. After the line has been successfully closed, this handle is no longer valid.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL.

## Remarks

If an application calls
**lineClose** while it still has active calls on the opened line, the application's ownership of these calls is revoked. If the application was the sole owner of these calls, the calls are dropped as well. It is good programming practice for an application to dispose of the calls it owns on an opened line by explicitly relinquishing ownership and/or by dropping these calls prior to closing the line.

If the line was closed successfully, a
[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate) message is sent to all applications that are monitoring the line status of open/close changes. Outstanding asynchronous replies are suppressed.

Service providers may find it useful or necessary to forcibly reclaim line devices from an application that has the line open. This can be useful to prevent an application from monopolizing the line device for too long. If this happens, a LINE_CLOSE message is sent to the application, specifying the line handle of the line device that was closed.

The
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) function allocates resources to the invoking application, and applications can be prevented from opening a line if resources are unavailable. Therefore, an application that only occasionally uses a line device (such as for making outgoing calls) should close the line to free resources and allow other applications to open the line.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/line-close)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen)