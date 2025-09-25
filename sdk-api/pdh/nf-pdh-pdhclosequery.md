# PdhCloseQuery function

## Description

Closes all counters contained in the specified query, closes all handles related to the query, and frees all memory associated with the query.

## Parameters

### `hQuery` [in]

Handle to the query to close. This handle is returned by the
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function.

## Return value

If the function succeeds, it returns ERROR_SUCCESS. Otherwise, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

The following is a possible value.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The query handle is not valid. |

## Remarks

Do not use the counter handles associated with this query after calling this function.

The following shows the syntax if calling this function from Visual Basic.

``` syntax
PdhCloseQuery(
  ByVal QueryHandle as Long
)
as Long
```

#### Examples

For an example, see
[Browsing Performance Counters](https://learn.microsoft.com/windows/desktop/PerfCtrs/browsing-performance-counters) or
[Reading Performance Data from a Log File](https://learn.microsoft.com/windows/desktop/PerfCtrs/reading-performance-data-from-a-log-file).

## See also

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)