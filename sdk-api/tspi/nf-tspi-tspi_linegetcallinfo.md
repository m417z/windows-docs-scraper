# TSPI_lineGetCallInfo function

## Description

The
**TSPI_lineGetCallInfo** function returns detailed information about the specified call.

## Parameters

### `hdCall`

The service provider's handle to the call whose call information is to be retrieved. The call state of *hdCall* can be any state.

### `lpCallInfo`

A pointer to a variably sized data structure of type
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo). Upon successful completion of the request, this structure is filled with call-related information.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_OPERATIONUNAVAIL.

## Remarks

The following table indicates which members of the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) data structure are filled in by TAPI and which members are filled in by the service provider. The service provider must preserve (it must not overwrite) the values filled in by TAPI.

| Member name | TAPI | Service provider |
| --- | --- | --- |
| **dwTotalSize;** | X |  |
| **dwNeededSize;** |  | X |
| **dwUsedSize;** |  | X |
| **hLine;** | X |  |
| **dwLineDeviceID;** |  | X |
| **dwAddressID;** |  | X |
| **dwBearerMode;** |  | X |
| **dwRate;** |  | X |
| **dwMediaMode;** |  | X |
| **dwAppSpecific;** |  | X |
| **dwCallID;** |  | X |
| **dwRelatedCallID;** |  | X |
| **dwCallParamFlags;** |  | X |
| **dwCallStates;** | X | X |
| **dwMonitorDigitModes;** | X |  |
| **dwMonitorMediaModes;** | X |  |
| **DialParams;** |  | X |
| **dwOrigin;** |  | X |
| **dwReason;** |  | X |
| **dwCompletionID;** |  | X |
| **dwNumOwners;** | X |  |
| **dwNumMonitors;** | X |  |
| **dwCountryCode;** |  | X |
| **dwTrunk;** |  | X |
| **dwCallerIDFlags;** |  | X |
| **dwCallerIDSize;** |  | X |
| **dwCallerIDOffset;** |  | X |
| **dwCallerIDNameSize;** |  | X |
| **dwCallerIDNameOffset;** |  | X |
| **dwCalledIDFlags;** |  | X |
| **dwCalledIDSize;** |  | X |
| **dwCalledIDOffset;** |  | X |
| **dwCalledIDNameSize;** |  | X |
| **dwCalledIDNameOffset;** |  | X |
| **dwConnectedIDFlags;** |  | X |
| **dwConnectedIDSize;** |  | X |
| **dwConnectedIDOffset;** |  | X |
| **dwConnectedIDNameSize;** |  | X |
| **dwConnectedIDNameOffset;** |  | X |
| **dwRedirectionIDFlags;** |  | X |
| **dwRedirectionIDSize;** |  | X |
| **dwRedirectionIDOffset;** |  | X |
| **dwRedirectionIDNameSize;** |  | X |
| **dwRedirectionIDNameOffset;** |  | X |
| **dwRedirectingIDFlags;** |  | X |
| **dwRedirectingIDSize;** |  | X |
| **dwRedirectingIDOffset;** |  | X |
| **dwRedirectingIDNameSize;** |  | X |
| **dwRedirectingIDNameOffset;** |  | X |
| **dwAppNameSize;** | X |  |
| **dwAppNameOffset;** | X |  |
| **dwDisplayableAddressSize;** | X |  |
| **dwDisplayableAddressOffset;** | X |  |
| **dwCalledPartySize;** | X |  |
| **dwCalledPartyOffset;** | X |  |
| **dwCommentSize;** | X |  |
| **dwCommentOffset;** | X |  |
| **dwDisplaySize;** |  | X |
| **dwDisplayOffset;** |  | X |
| **dwUserUserInfoSize;** |  | X |
| **dwUserUserInfoOffset;** |  | X |
| **dwHighLevelCompSize;** |  | X |
| **dwHighLevelCompOffset;** |  | X |
| **dwLowLevelCompSize;** |  | X |
| **dwLowLevelCompOffset;** |  | X |
| **dwChargingInfoSize;** |  | X |
| **dwChargingInfoOffset;** |  | X |
| **dwTerminalModesSize;** |  | X |
| **dwTerminalModesOffset;** |  | X |
| **dwDevSpecificSize;** |  | X |
| **dwDevSpecificOffset;** |  | X |

TAPI fills in the size and offset fields for the **dwAppNameSize/Offset**, **dwCalledPartySize/Offset**, and **dwCommentSize/Offset** members and updates the value in **dwUsedSize** to reflect these after calling the service provider.

After the service provider returns from the
**TSPI_lineGetCallInfo** function, TAPI sets the **dwCallStates** member of the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure as follows:

``` syntax
LINECALLINFO.dwCallStates |= LINECALLSTATE_UNKNOWN;
```

If the service provider models lines as "pools" of channel resources and does inverse multiplexing of a call over several address identifiers, it should consistently choose one of these address identifiers as the primary identifier reported by this function in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) data structure.