# IDataCollectorSet::Start

## Description

Manually starts the data collector set.

## Parameters

### `Synchronous` [in]

Data collection runs in a separate process. This value determines when the method returns.

Set to VARIANT_TRUE to have the method return after the data collection process starts or fails to start. The return value indicates whether the set successfully started or failed to start.

Set to VARIANT_FALSE to return after the set is queued to run. The return value indicates whether the set was successfully queued. For more information, see Remarks.

## Return value

Returns **S_OK** if successful. The following table shows possible error values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The set must be persisted (see the [Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-commit) method) prior to starting collection. |
| **HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND)** | The system cannot find the path specified. This error occurs when the [RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) property specifies a directory that does not exist. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | The subdirectory or log file already exists. Try using a format to uniquely identify the file. |

## Remarks

To determine the status of the collection, access the [IDataCollectorSet::Status](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_status) property.

When the collection process is complete, PLA runs the [data manager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager), if enabled.

To automatically start data collection on a schedule, see [IDataCollectorSet::Schedules](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_schedules).

If you start the set asynchronously, an event is written to the Microsoft-Windows-Diagnosis-PLA/Operational event log to indicate whether the collection process started (event 1003) or failed (event 1004).

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Schedules](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_schedules)

[IDataCollectorSet::Stop](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-stop)