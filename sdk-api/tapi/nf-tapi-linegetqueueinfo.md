# lineGetQueueInfo function

## Description

The
**lineGetQueueInfo** function returns a structure holding the ACD information associated with a particular queue. It generates a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message to be sent to a registered proxy function handler, referencing a
[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest) structure of type LINEPROXYREQUEST_GETQUEUEINFO.

## Parameters

### `hLine`

Handle to the line device.

### `dwQueueID`

Identifier of the queue whose information is to be retrieved.

### `lpLineQueueInfo`

Pointer to a structure of type
[LINEQUEUEINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeueinfo). Upon successful completion of the request, this structure is filled with the queue statistics. Prior to calling
**lineGetQueueInfo**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns a request identifier if the asynchronous operation starts; otherwise, the function returns one of the following error values:

LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINEQUEUEINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeueinfo)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)