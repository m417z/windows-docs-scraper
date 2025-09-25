# IGetAppTrackerData::GetApplicationProcessDetails

## Description

Retrieves detailed information about a single process hosting COM+ applications.

## Parameters

### `ApplicationInstanceId` [in]

The application instance GUID that uniquely identifies the tracked process to select, or GUID_NULL if the *ProcessId* parameter will be used for selection instead.

### `ProcessId` [in]

The process ID that identifies the process to select, or 0 if the *ApplicationInstanceId* parameter will be used for selection instead.

### `Flags` [in]

A combination of flags from the [GetAppTrackerDataFlags](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-getapptrackerdataflags) enumeration that specify which data is to be returned. The following flags are supported: GATD_INCLUDE_PROCESS_EXE_NAME (if retrieving a summary).

### `Summary` [out, optional]

On return, a [ApplicationProcessSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-applicationprocesssummary) structure with summary information for the process. This parameter can be **NULL**.

### `Statistics` [out, optional]

On return, a [ApplicationProcessStatistics](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-applicationprocessstatistics) structure with statistics for the process. This parameter can be **NULL**.

### `RecycleInfo` [out, optional]

On return, a [ApplicationProcessRecycleInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-applicationprocessrecycleinfo) structure with recycling details for the process. This parameter can be **NULL**.

### `AnyComponentsHangMonitored` [out, optional]

On return, indicates whether any components in the process are configured for hang monitoring. This parameter can be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_APP_NOT_RUNNING** | The specified process does not exist, or is not hosting any tracked COM+ applications. |

## Remarks

A process may be selected by its application instance ID or its process ID, but not both. Selection by application instance ID is generally preferred, because process IDs may be reused after a process terminates. However, selection by process ID may be useful if you obtain the process ID from some other source, such as a command line argument to your program.

You may request any or all of the information available for the process by passing non-**NULL** values for *Summary*, *Statistics*, *RecycleInfo*, or *AnyComponentsHangMonitored*. At least one of these parameters must be non-**NULL**.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)