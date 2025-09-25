# TSPI_lineGetCallIDs function

## Description

The
**TSPI_lineGetCallIDs** function returns the call identifiers for the service provider. This function requires TAPI 3.0 version negotiation.

## Parameters

### `hdCall`

The service provider's handle to the call whose identifier is needed.

### `lpdwAddressID`

A pointer to the call's address identifier.

### `lpdwCallID`

A pointer to the call's identifier.

### `lpdwRelatedCallID`

A pointer to the identifier of a related call.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

## Remarks

In some telephony environments, the switch or service provider can assign a unique identifier to each call. This allows the call to be tracked across transfers, forwards, or other events. The domain of these call identifiers and their scope is service-provider defined.

## See also

[CallHub Tracking](https://learn.microsoft.com/windows/desktop/Tapi/callhub-support)

[LINECALLHUBTRACKINGINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallhubtrackinginfo)