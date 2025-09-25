# NUMA_NODE_RELATIONSHIP structure

## Description

Represents information about a NUMA node in a processor group. This structure is used with the [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) function.

## Members

### `NodeNumber`

The number of the NUMA node.

### `Reserved`

This member is reserved.

### `GroupCount`

The number of groups included in the *GroupMasks* array. This field was introduced in Windows 20H2. On earlier versions, this value is always 0.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.GroupMask`

A [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structure that specifies a group number and processor affinity within the group.

### `DUMMYUNIONNAME.GroupMasks`

An array of [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structure that specifies a group number and processor affinity within the group.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity)

[GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)