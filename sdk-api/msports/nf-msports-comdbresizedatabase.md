# ComDBResizeDatabase function

## Description

**ComDBResizeDatabase** resizes the COM port database.

## Parameters

### `HComDB` [in]

Handle to the COM port database that was returned by [ComDBOpen](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbopen).

### `NewSize` [in]

Specifies a new size for the COM port database, where the database size is the number of port numbers currently arbitrated in the database. This value must be an integer multiple of 1024, must be greater than the current size, and must be less than or equal to COMDB_MAX_PORTS_ARBITRATED.

## Return value

**ComDBResizeDatabase** returns one of the following status values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The database was successfully resized. |
| **ERROR_BAD_LENGTH** | *NewSize* is less than or equal to the current database size, or it is greater than COMDB_MAX_PORTS_ARBITRATED. |
| **ERROR_CANTWRITE** | The routine could not write to the database. |
| **ERROR_INVALID_PARAMETER** | One of the following is true: The specified handle to the COM port database is not valid. *NewSize* is not a multiple of 1024. |
| **ERROR_NOT_CONNECTED** | The routine could not access the database. To get extended error information, call **GetLastError**. |

## Remarks

Use [ComDBGetCurrentPortUsage](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbgetcurrentportusage) to obtain the current database size.

**ComDBResizeDatabase** runs in user mode.

For more information, see [Resizing the COM Port Database](https://learn.microsoft.com/previous-versions/ff546481(v=vs.85)).

## See also

[ComDBGetCurrentPortUsage](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbgetcurrentportusage)