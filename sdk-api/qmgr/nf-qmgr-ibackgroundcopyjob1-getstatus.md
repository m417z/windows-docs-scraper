# IBackgroundCopyJob1::GetStatus

## Description

[[IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetStatus** method to retrieve the state of the job.

## Parameters

### `pdwStatus` [out]

State of the job. The state can be set to one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **QM_STATUS_JOB_FOREGROUND** | Not supported. |
| **QM_STATUS_JOB_INCOMPLETE** | QMGR is still downloading the job. |
| **QM_STATUS_JOB_COMPLETE** | The job is complete. |
| **QM_STATUS_JOB_ERROR** | An error occurred while processing the job. |

### `pdwWin32Result` [out]

Win32 error code. Valid only if the QM_STATUS_JOB_ERROR *dwStatus* flag is set.

### `pdwTransportResult` [out]

HTTP error code. Valid only if the QM_STATUS_JOB_ERROR *dwStatus* flag is set.

### `pdwNumOfRetries` [out]

Number of times QMGR tried to download the job after an error occurs. Valid only if the QM_STATUS_GROUP_ERROR *dwStatus* flag is set.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the state of the job. |

## See also

[IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1)