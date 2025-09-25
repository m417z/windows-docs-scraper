# TSPI_lineGetCallStatus function

## Description

The
**TSPI_lineGetCallStatus** function returns the current status of the specified call.

## Parameters

### `hdCall`

The service provider's handle to the call to be queried for its status. The call state of *hdCall* can be any state.

### `lpCallStatus`

A pointer to a variably sized data structure of type
[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus). This structure is filled with call status information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_OPERATIONUNAVAIL.

## Remarks

The following table indicates which members of the
[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus) data structure are filled in by the service provider and which members are filled in by TAPI. The service provider must preserve (it must not overwrite) the values filled in by TAPI.

| Member name | TAPI | Service provider |
| --- | --- | --- |
| **dwTotalSize;** | X |  |
| **dwNeededSize;** |  | X |
| **dwUsedSize;** |  | X |
| **dwCallState;** |  | X |
| **dwCallStateMode;** |  | X |
| **dwCallPrivilege;** | X |  |
| **dwCallFeatures;** |  | X |
| **dwDevSpecificSize;** |  | X |
| **dwDevSpecificOffset;** |  | X |

**TSPI_lineGetCallStatus** returns the dynamic status of a call, whereas
[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo) returns primarily static information about a call. Call status information includes the current call state, detailed mode information related to the call while in this state (if any), as well as a list of the available TSPI functions TAPI can invoke on the call while the call is in this state.

## See also

[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus)

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)