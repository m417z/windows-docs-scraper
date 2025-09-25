# ApplicationProcessSummary structure

## Description

Represents summary information about a process hosting COM+ applications.

## Members

### `PartitionIdPrimaryApplication`

The partition ID of the COM+ server application, for server application processes. For processes that are not hosting a COM+ server application, this is set to the partition ID of the first tracked component instantiated in the process.

### `ApplicationIdPrimaryApplication`

The application ID of the COM+ server application, for server application processes. For processes that are not hosting a COM+ server application, this is set to the application ID of the first tracked component instantiated in the process.

### `ApplicationInstanceId`

The application instance GUID uniquely identifying the tracked process.

### `ProcessId`

The process ID of the tracked process.

### `Type`

The type of application this process is hosting. For COM+ server application processes, this is set to APPTYPE_SERVER. For processes that are not hosting a COM+ server applications, this is set to either APPTYPE_LIBRARY or APPTYPE_SWC, based on the first tracked component instantiated in the process.

### `ProcessExeName`

The name of the process's executable image. Space for this string is allocated by the method called and freed by the caller (for more information, see [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)). This member is not returned by default. To return this member, specify the GATD_INCLUDE_PROCESS_EXE_NAME flag when you call a method that returns an **ApplicationProcessSummary** structure.

### `IsService`

Indicates whether the process is a COM+ server application running as a Windows service.

### `IsPaused`

Indicates whether the process is a COM+ server application instance that is paused.

### `IsRecycled`

Indicates whether the process is a COM+ server application instance that has been recycled.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)