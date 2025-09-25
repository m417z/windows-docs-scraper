# PdhGetRawCounterValue function

## Description

Returns the current raw value of the counter.

## Parameters

### `hCounter` [in]

Handle of the counter from which to retrieve the current raw value. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `lpdwType` [out]

Receives the counter type. For a list of counter types, see the Counter Types section of the [Windows Server 2003 Deployment Kit](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc776490(v=ws.10)). This parameter is optional.

### `pValue` [out]

A
[PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter) structure that receives the counter value.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## Remarks

The data for the counter is locked (protected) for the duration of the call to
**PdhGetRawCounterValue** to prevent any changes during processing of the call.

If
the specified counter instance does not exist, this function will return ERROR_SUCCESS and the **CStatus** member of the
[PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter) structure will contain PDH_CSTATUS_NO_INSTANCE.

## See also

[PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue)

[PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata)

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)