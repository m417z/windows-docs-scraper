# IBackgroundCopyCallback1::OnStatus

## Description

[**IBackgroundCopyCallback1** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Implement the **OnStatus** method to receive notification when the group is complete or an error occurs.

## Parameters

### `pGroup` [in]

Interface pointer to the group that generated the event.

### `pJob` [in]

Interface pointer to the job associated with the event or **NULL** if the event is not associated with a job.

### `dwFileIndex` [in]

Index to the file associated with the error or -1. To retrieve the file, call the [IBackgroundCopyJob1::GetFile](https://learn.microsoft.com/windows/desktop/api/qmgr/nf-qmgr-ibackgroundcopyjob1-getfile) method.

### `dwStatus` [in]

The state of the group. The state of the group is either complete (all jobs in the group have been downloaded) or in error. An error occurred if the QM_STATUS_GROUP_ERROR flag is set. Otherwise, the group is complete.

### `dwNumOfRetries` [in]

Number of times QMGR tried to download the group after an error occurs. Valid only if the QM_STATUS_GROUP_ERROR *dwStatus* flag is set.

### `dwWin32Result` [in]

Win32 error code. Valid only if the QM_STATUS_GROUP_ERROR *dwStatus* flag is set.

### `dwTransportResult` [in]

HTTP error code. Valid only if the QM_STATUS_GROUP_ERROR *dwStatus* flag is set.

## Return value

This method should return **S_OK**; otherwise, the service continues to call this method until S_OK is returned. The interval at which the implementation is called is arbitrary.

## See also

[IBackgroundCopyCallback1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopycallback1)