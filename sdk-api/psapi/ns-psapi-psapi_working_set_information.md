# PSAPI_WORKING_SET_INFORMATION structure

## Description

Contains working set information for a process.

## Members

### `NumberOfEntries`

The number of entries in the **WorkingSetInfo** array.

### `WorkingSetInfo`

An array of [PSAPI_WORKING_SET_BLOCK](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_block) elements, one for each page in the process working set.

## See also

[PSAPI_WORKING_SET_BLOCK](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_block)

[QueryWorkingSet](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingset)