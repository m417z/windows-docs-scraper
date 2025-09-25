# GROUP_RELATIONSHIP structure

## Description

Represents information about processor groups. This structure is used with the [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) function.

## Members

### `MaximumGroupCount`

The maximum number of processor groups on the system.

### `ActiveGroupCount`

The number of active groups on the system. This member indicates the number of [PROCESSOR_GROUP_INFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_group_info) structures in the **GroupInfo** array.

### `Reserved`

This member is reserved.

### `GroupInfo`

An array of [PROCESSOR_GROUP_INFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_group_info) structures. Each structure represents the number and affinity of processors in an active group on the system.

## See also

[GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex)

[PROCESSOR_GROUP_INFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_group_info)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)