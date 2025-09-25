# PSAPI_WORKING_SET_EX_INFORMATION structure

## Description

Contains extended working set information for a process.

## Members

### `VirtualAddress`

The virtual address.

### `VirtualAttributes`

A [PSAPI_WORKING_SET_EX_BLOCK](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_ex_block) union that indicates the attributes of the page at **VirtualAddress**.

## See also

[PSAPI_WORKING_SET_EX_BLOCK](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_ex_block)

[QueryWorkingSetEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingsetex)