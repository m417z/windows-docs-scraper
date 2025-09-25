# PdhCollectQueryDataWithTime function

## Description

Collects the current raw data value for all counters in the specified query and updates the status code of each counter.

## Parameters

### `hQuery` [in, out]

Handle of the query for which you want to collect data. The [PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function returns this handle.

### `pllTimeStamp` [out]

Time stamp when the first counter value in the query was retrieved. The time is specified as FILETIME.

## Return value

If the function succeeds, it returns ERROR_SUCCESS. Otherwise, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The query handle is not valid. |
| **PDH_NO_DATA** | The query does not currently have any counters. |

## Remarks

Call this function when you want to collect counter data for the counters in the query. PDH stores the raw counter values for the current and previous collection.

If you want to retrieve the current raw counter value, call the [PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) function. If you want to compute a displayable value for the counter value, call the [PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue). If the counter path contains a wildcard for the instance name, instead call the [PdhGetRawCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcounterarraya) and [PdhGetFormattedCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcounterarraya) functions, respectively.

When
[PdhCollectQueryDataEx](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydataex) is called for data from one counter instance only, and the counter instance does not exist, the function returns PDH_NO_DATA. However, if data from more than one counter is queried,
**PdhCollectQueryDataEx** may return ERROR_SUCCESS even if one of the counter instances does not yet exist. This is because it is not known if the specified counter instance does not exist, or if it will exist but has not yet been created. In this case, call
the [PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) or
[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue) function for each of the counter instances of interest to determine whether they exist.

## See also

[PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata)

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)