# lineGetProxyStatus function

## Description

The
**lineGetProxyStatus** function returns a list of proxy request types that are currently being serviced for the specified device.

## Parameters

### `hLineApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Line device to be queried.

### `dwAppAPIVersion`

Version number of TAPI to be used.

### `lpLineProxyReqestList`

Pointer to a variably sized structure of type
[LINEPROXYREQUESTLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequestlist). Upon successful completion of the request, this structure is filled with a list of the currently supported proxy requests. Prior to calling
**lineGetProxyStatus**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds; otherwise, the function returns one of the following negative error values:

LINEERR_BADDEVICEID, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEPROXYREQUESTLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequestlist)