# JOBOBJECT_BASIC_PROCESS_ID_LIST structure

## Description

Contains the process identifier list for a job object. If the job is nested, the process identifier list consists of all processes associated with the job and its child jobs.

## Members

### `NumberOfAssignedProcesses`

The number of process identifiers to be stored in **ProcessIdList**.

### `NumberOfProcessIdsInList`

The number of process identifiers returned in the **ProcessIdList** buffer. If this number is less than **NumberOfAssignedProcesses**, increase the size of the buffer to accommodate the complete list.

### `ProcessIdList`

A variable-length array of process identifiers returned by this call. Array elements 0 through **NumberOfProcessIdsInList**– 1 contain valid process identifiers.

## See also

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)