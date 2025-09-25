# TSPI_lineGetCallHubTracking function

## Description

The
**TSPI_lineGetCallHubTracking** function returns the current state of CallHub tracking for the service provider. This function requires TAPI 3.0 version negotiation.

## Parameters

### `hdLine`

The service provider's handle to the call whose call information is to be retrieved. The call state of *hdLine* can be any state.

### `lpTrackingInfo`

A pointer to the variably sized
[LINECALLHUBTRACKINGINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallhubtrackinginfo) structure. Upon successful completion of the request, this structure is filled with call-related information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

## See also

[CallHub Tracking](https://learn.microsoft.com/windows/desktop/Tapi/callhub-support)

[LINECALLHUBTRACKINGINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallhubtrackinginfo)