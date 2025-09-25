# ComDBOpen function

## Description

**ComDBOpen** returns a handle to the COM port database.

## Parameters

### `PHComDB` [out]

Pointer, if the routine succeeds, to a handle to the COM port database. Otherwise, the routine sets **PHComDB* to **HCOMDB_INVALID_HANDLE_VALUE**. *PHComDB* must be non-NULL.

## Return value

**ComDBOpen** returns one of the following status values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The COM port database was successfully opened. |
| **ERROR_ACCESS_DENIED** | The routine could not open the database. To get extended error information, call **GetLastError**. |

## Remarks

To close the COM port database, call [ComDBClose](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbclose) and supply the handle that was returned by **ComDBOpen**.

**ComDBOpen** is called from user mode.

For more information, see [Opening and Closing the COM Port Database](https://learn.microsoft.com/previous-versions/ff546481(v=vs.85)).

## See also

[ComDBClose](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbclose)