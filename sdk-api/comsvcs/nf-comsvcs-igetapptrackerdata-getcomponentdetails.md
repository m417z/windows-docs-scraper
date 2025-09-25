# IGetAppTrackerData::GetComponentDetails

## Description

Retrieves detailed information about a single COM+ component hosted in a process.

## Parameters

### `ApplicationInstanceId` [in]

The application instance GUID that uniquely identifies the tracked process to select, or GUID_NULL if the *ProcessId* parameter will be used for selection instead.

### `ProcessId` [in]

The process ID that identifies the process to select, or 0 if *ApplicationInstanceId* will be used for selection instead.

### `Clsid` [in]

The CLSID of the component.

### `Flags` [in]

A combination of flags from the [GetAppTrackerDataFlags](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-getapptrackerdataflags) enumeration to select which data is returned. The following flags are supported: GATD_INCLUDE_CLASS_NAME (if retrieving a summary), GATD_INCLUDE_APPLICATION_NAME (if retrieving a summary).

### `Summary` [out]

On return, a [ComponentSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-componentsummary) structure with summary information for the component. This parameter can be **NULL**.

### `Statistics` [out]

On return, a [ComponentStatistics](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-componentstatistics) structure with statistics for the component. This parameter can be **NULL**.

### `HangMonitorInfo` [out]

On return, a [ComponentHangMonitorInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-componenthangmonitorinfo) structure with hang monitoring configuration for the component. This parameter can be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_APP_NOT_RUNNING** | The specified process does not exist, or is not hosting any tracked COM+ applications. |
| **COMADMIN_E_OBJECT_DOES_NOT_EXIST** | The specified component does not exist in the specified process. |

## Remarks

A process may be selected by its application instance ID or its process ID, but not both. Selection by application instance ID is generally preferred, because process IDs may be reused after a process terminates. However, selection by process ID may be useful if you obtain the process ID from some other source, such as a command line argument to your program.

You may request any or all of the information available for the component by passing non-**NULL** values for *Summary*, *Statistics*, or *HangMonitorInfo*. At least one of these parameters must be non-**NULL**.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)