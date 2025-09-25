# TSPI_lineSetCallHubTracking function

## Description

The
**TSPI_lineSetCallHubTracking** function sets the CallHub tracking mode. This function requires TAPI 3.0 version negotiation.

## Parameters

### `hdLine`

The service provider's handle to the call whose call information is to be retrieved. The call state of *hdCall* can be any state.

### `lpTrackingInfo`

A pointer to a variably sized structure of type
[LINECALLHUBTRACKINGINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallhubtrackinginfo). Upon successful completion of the request, this structure is filled with call-related information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL

## See also

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[LINECALLHUBTRACKINGINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallhubtrackinginfo)