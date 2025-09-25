# ComDBReleasePort function

## Description

**ComDBReleasePort** releases a COM port number in the COM port database.

## Parameters

### `HComDB` [in]

Handle to the COM port database that was returned by [ComDBOpen](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbopen).

### `ComNumber` [in]

Specifies the COM port number to release. A port number is an integer that ranges from one to COMDB_MAX_PORTS_ARBITRATED.

## Return value

**ComDBReleasePort** returns one of the following status values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The COM port number was released. |
| **ERROR_CANTWRITE** | The routine could not write to the database. |
| **ERROR_INVALID_PARAMETER** | One of the following is true: The specified handle to the COM port database is not valid. The specified port number is not in the COM port database. |
| **ERROR_NOT_CONNECTED** | The routine could not access the database. To get extended error information, call **GetLastError**. |

## Remarks

*Releasing* a COM port number means to log the port number as "not in use".

**ComDBReleasePort** runs in user mode.

For more information, see [Obtaining and Releasing a COM Port Number](https://learn.microsoft.com/previous-versions/ff546481(v=vs.85)).

## See also

[ComDBClaimNextFreePort](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbclaimnextfreeport)

[ComDBClaimPort](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbclaimport)