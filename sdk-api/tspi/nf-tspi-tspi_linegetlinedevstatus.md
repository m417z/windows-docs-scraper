# TSPI_lineGetLineDevStatus function

## Description

The
**TSPI_lineGetLineDevStatus** function queries the specified open line device for its current status. The information returned is global to all addresses on the line.

## Parameters

### `hdLine`

The service provider's handle to the line to be queried.

### `lpLineDevStatus`

A pointer to a variably sized data structure of type
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus). This structure is filled with the line's device status.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_OPERATIONUNAVAIL.

## Remarks

The following table indicates which members of the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) data structure are filled in by TAPI and which are filled in by the service provider. The service provider must preserve (it must not overwrite) the values filled in by TAPI.

| Member name | TAPI | Service provider |
| --- | --- | --- |
| **dwTotalSize;** | X |  |
| **dwNeededSize;** |  | X |
| **dwUsedSize;** |  | X |
| **dwNumOpens;** | X |  |
| **dwOpenMediaModes;** | X |  |
| **dwNumActiveCalls;** |  | X |
| **dwNumOnHoldCalls;** |  | X |
| **dwNumOnHoldPendCalls;** |  | X |
| **dwLineFeatures;** |  | X |
| **dwNumCallCompletions;** |  | X |
| **dwRingMode;** |  | X |
| **dwSignalLevel;** |  | X |
| **dwBatteryLevel;** |  | X |
| **dwRoamMode;** |  | X |
| **dwDevStatusFlags;** |  | X |
| **dwTerminalModesSize;** |  | X |
| **dwTerminalModesOffset;** |  | X |
| **dwDevSpecificSize;** |  | X |
| **dwDevSpecificOffset;** |  | X |

## See also

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[TSPI_lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetaddressstatus)