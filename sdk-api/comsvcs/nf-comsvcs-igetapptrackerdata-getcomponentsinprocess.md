# IGetAppTrackerData::GetComponentsInProcess

## Description

Retrieves summary information for all COM+ components hosted in a single process, or for a specified subset of these components.

## Parameters

### `ApplicationInstanceId` [in]

The application instance GUID that uniquely identifies the tracked process to select, or GUID_NULL if the *ProcessId* parameter will be used for selection instead.

### `ProcessId` [in]

The process ID that identifies the process to select, or 0 if the *ApplicationInstanceId* parameter will be used for selection instead.

### `PartitionId` [in]

A partition ID to filter results, or GUID_NULL for all partitions.

### `ApplicationId` [in]

An application ID to filter results, or GUID_NULL for all applications.

### `Flags` [in]

A combination of flags from the [GetAppTrackerDataFlags](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-getapptrackerdataflags) enumeration to filter results and to select which data is returned. The following flags are supported: GATD_INCLUDE_LIBRARY_APPS, GATD_INCLUDE_SWC, GATD_INCLUDE_CLASS_NAME, GATD_INCLUDE_APPLICATION_NAME. See Remarks below for more information.

### `NumComponentsInProcess` [out]

On return, the number of components in the process that match the filter criteria specified by *PartitionId*, *ApplicationId*, and *Flags*.

### `Components` [out]

On return, an array of [ComponentSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-componentsummary) structures for the matching components.

## Return value

This method can return the standard return values E_INVALIDARG and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully and the results are in the *Components* parameter. |
| **S_FALSE** | The method completed successfully, but there were no components the matched the filter criteria. |
| **COMADMIN_E_APP_NOT_RUNNING** | The specified process does not exist, or is not hosting any tracked COM+ applications. |

## Remarks

A process may be selected by its application instance ID or its process ID, but not both. Selection by application instance ID is generally preferred, because process IDs may be reused after a process terminates. However, selection by process ID may be useful if you obtain the process ID from some other source, such as a command line argument to your program.

If neither GATD_INCLUDE_LIBRARY_APPS nor GATD_INCLUDE_SWC are set in *Flags*, only components from the COM+ server application are included in the results. If GATD_INCLUDE_LIBRARY_APPS is set, components from COM+ library applications in the process, if any, are also included. If GATD_INCLUDE_SWC is set, the results will also include entries for Services Without Components contexts.

If *ApplicationId* is used to specify an application (it is not set to GUID_NULL), the GATD_INCLUDE_LIBRARY_APPS and GATD_INCLUDE_SWC flags are not meaningful, and it is not valid to use them. Components from the specified application will be returned, regardless of the type of that application.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)