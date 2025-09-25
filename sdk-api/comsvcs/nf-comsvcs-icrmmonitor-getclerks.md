# ICrmMonitor::GetClerks

## Description

Retrieves a clerk collection object, which is a snapshot of the current state of the clerks.

## Parameters

### `pClerks` [out]

An [ICrmMonitorClerks](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitorclerks) pointer to a clerks collection object.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **XACT_E_RECOVERYINPROGRESS** | Recovery of the CRM log file is still in progress. |

## See also

[ICrmMonitor](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitor)