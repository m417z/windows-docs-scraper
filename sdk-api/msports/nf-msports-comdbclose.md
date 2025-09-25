# ComDBClose function

## Description

**ComDBClose** closes a handle to the COM port database.

## Parameters

### `HComDB` [in]

Handle to the COM port database that was returned by [ComDBOpen](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbopen).

## Return value

**ComDBClose** returns one of the following status values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The COM port database was closed. |
| **ERROR_INVALID_PARAMETER** | The specified COM port database handle is not valid. |

## Remarks

To open the COM port database, call **ComDBOpen**.

**ComDBOpen** is called from user mode.

For more information, see [Opening and Closing the COM Port Database](https://learn.microsoft.com/previous-versions/ff546481(v=vs.85)).

## See also

[ComDBOpen](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbopen)