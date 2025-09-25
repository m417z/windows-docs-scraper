# PdhRemoveCounter function

## Description

Removes a counter from a query.

## Parameters

### `hCounter` [in]

Handle of the counter to remove from its query. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

The following is a possible value.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## Remarks

Do not use the counter handle after removing the counter from the query.

The following shows the syntax if calling this function from Visual Basic.

``` syntax
PdhRemoveCounter(
  ByVal CounterHandle as Long
)
as Long
```

## See also

[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)