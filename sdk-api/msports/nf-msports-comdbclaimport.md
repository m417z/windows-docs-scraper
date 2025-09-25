# ComDBClaimPort function

## Description

**ComDBClaimPort** logs an unused COM port number as "in use" in the COM port database.

## Parameters

### `HComDB` [in]

Handle to the COM port database that is returned by [ComDBOpen](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbopen).

### `ComNumber` [in]

Specifies which COM port number the caller attempts to claim. A port number is an integer that can range from 1 to COMDB_MAX_PORTS_ARBITRATED.

### `ForceClaim` [in]

Reserved for internal use only.

### `Forced` [out, optional]

Reserved for internal use only.

## Return value

**ComDBClaimPort** returns one of the following status values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The COM port number was not in use and is now logged as "in use". |
| **ERROR_CANTWRITE** | The routine could not write to the database. |
| **ERROR_INVALID_PARAMETER** | One of the following is true: The specified handle to the COM port database is not valid. The specified port number is greater than COMDB_MAX_PORTS_ARBITRATED. |
| **ERROR_NOT_CONNECTED** | The routine could not access the database. To get extended error information, call **GetLastError**. |
| **ERROR_SHARING_VIOLATION** | The specified port number is already in use. |
| **ERROR_Xxx** | An internal error occurred; call **GetLastError** to get extended error information. |

## Remarks

*Claiming* a COM port number in the COM port database logs the port number as "in use". Note that the database does not contain information about the caller or device that claims a port number.

**ComDBClaimPort** runs in user mode.

For more information, see [Obtaining and Releasing a COM Port Number](https://learn.microsoft.com/previous-versions/ff546481(v=vs.85)).

## See also

[ComDBClaimNextFreePort](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbclaimnextfreeport)

[ComDBReleasePort](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbreleaseport)