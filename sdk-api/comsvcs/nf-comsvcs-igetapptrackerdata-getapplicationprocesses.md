# IGetAppTrackerData::GetApplicationProcesses

## Description

Retrieves summary information for all processes that are hosting COM+ applications, or for a specified subset of these processes.

## Parameters

### `PartitionId` [in]

A partition ID to filter results, or GUID_NULL for all partitions.

### `ApplicationId` [in]

An application ID to filter results, or GUID_NULL for all applications.

### `Flags` [in]

A combination of flags from the [GetAppTrackerDataFlags](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-getapptrackerdataflags) enumeration to filter results and to select which data is returned. The following flags are supported: GATD_INCLUDE_PROCESS_EXE_NAME, GATD_INCLUDE_LIBRARY_APPS, GATD_INCLUDE_SWC. See remarks below for more information.

### `NumApplicationProcesses` [out]

On return, the number of processes that match the filter criteria specified by *PartitionId*, *ApplicationId*, and *Flags*.

### `ApplicationProcesses` [out]

On return, an array of [ApplicationProcessSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-applicationprocesssummary) structures for the matching processes.

## Return value

This method can return the standard return values E_INVALIDARG and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully and the results are in the *ApplicationProcesses* parameter. |
| **S_FALSE** | The method completed successfully, but there were no processes the matched the filter criteria. |

## Remarks

The *PartitionId*, *ApplicationId*, and *Flags* parameters can be used to specify filter criteria if the caller only wants information on a subset of tracked processes.

If neither GATD_INCLUDE_LIBRARY_APPS nor GATD_INCLUDE_SWC are set in *Flags*, the results include COM+ server application instances only. The *ApplicationId* parameter can be used to select instances of a specific COM+ server application, and the *PartitionId* parameter for COM+ server applications from a specific partition.

If either GATD_INCLUDE_LIBRARY_APPS or GATD_INCLUDE_SWC are set, the results also include processes that are hosting COM+ library applications or Services Without Components contexts, respectively. In these cases, *ApplicationId* and *PartitionId* filter processes based on all applications (of the requested types) that the process is hosting. If a process includes at least one application that matches the criteria, it will be included in the results.

For example, imagine the following COM+ applications are installed:

* AppX is a server application in PartitionA.
* AppY is a library application in PartitionA.
* AppZ is a server application in PartitionB.

If *PartitionId* specifies PartitionA, and GATD_INCLUDE_LIBRARY_APPS is set:

* An instance of AppX will be included.
* A client process that has created components from AppY will be included.
* An instance of AppZ containing no other COM+ components will not be included because AppZ is not in the partition specified by *PartitionId*.
* However, if there is another instance of AppZ, but which has also created components from AppY, this process will be included even though the server application is not in the partition specified by *PartitionId*. This process would not be included if GATD_INCLUDE_LIBRARY_APPS was not set.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)