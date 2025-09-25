# PdhCollectQueryData function

## Description

Collects the current raw data value for all counters in the specified query and updates the status code of each counter.

## Parameters

### `hQuery` [in, out]

Handle of the query for which you want to collect data. The [PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function returns this handle.

## Return value

If the function succeeds, it returns ERROR_SUCCESS. Otherwise, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The query handle is not valid. |
| **PDH_NO_DATA** | The query does not currently contain any counters. The query may not contain data because the user is not running with an elevated token (see [Limited User Access Support](https://learn.microsoft.com/windows/desktop/PerfCtrs/limited-user-access-support)). |

## Remarks

Call this function when you want to collect counter data for the counters in the query. PDH stores the raw counter values for the current and previous collection.

If you want to retrieve the current raw counter value, call the [PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) function. If you want to compute a displayable value for the counter value, call the [PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue) function. If the counter path contains a wildcard for the instance name, instead call the [PdhGetRawCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcounterarraya) and [PdhGetFormattedCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcounterarraya) functions, respectively.

When
**PdhCollectQueryData** is called for data from one counter instance only and the counter instance does not exist, the function returns PDH_NO_DATA. However, if data from more than one counter is queried,
**PdhCollectQueryData** may return ERROR_SUCCESS even if one of the counter instances does not yet exist. This is because it is not known if the specified counter instance does not exist, or if it will exist but has not yet been created. In this case, call
[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) or
[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue) for each of the counter instances of interest to determine whether they exist.

The following shows the syntax if calling this function from Visual Basic.

``` syntax
PdhCollectQueryData(
  ByVal QueryHandle as Long
)
as Long
```

#### Examples

For an example, see
[Browsing Performance Counters](https://learn.microsoft.com/windows/desktop/PerfCtrs/browsing-performance-counters) or
[Reading Performance Data from a Log File](https://learn.microsoft.com/windows/desktop/PerfCtrs/reading-performance-data-from-a-log-file).

## See also

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)