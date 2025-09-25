# PROCESSOR_RELATIONSHIP structure

## Description

Represents information about affinity within a processor group. This structure is used with the [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) function.

## Members

### `Flags`

If the **Relationship** member of the [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structure is **RelationProcessorCore**, this member is LTP_PC_SMT if the core has more than one logical processor, or 0 if the core has one logical processor.

If the **Relationship** member of the [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structure is **RelationProcessorPackage**, this member is always 0.

### `EfficiencyClass`

 If the **Relationship** member of the [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structure is **RelationProcessorCore**, **EfficiencyClass** specifies the intrinsic tradeoff between performance and power for the applicable core. A core with a higher value for the efficiency class has intrinsically greater performance and less efficiency than a core with a lower value for the efficiency class. **EfficiencyClass** is only nonzero on systems with a heterogeneous set of cores.

If the **Relationship** member of the [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structure is **RelationProcessorPackage**, **EfficiencyClass** is always 0.

The minimum operating system version that supports this member is Windows 10.

### `Reserved`

This member is reserved.

### `GroupCount`

This member specifies the number of entries in the **GroupMask** array. For more information, see Remarks.

### `GroupMask`

An array of [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structures. The **GroupCount** member specifies the number of structures in the array. Each structure in the array specifies a group number and processor affinity within the group.

## Remarks

The **PROCESSOR_RELATIONSHIP** structure describes the logical processors associated with either a processor core or a processor package.

If the **PROCESSOR_RELATIONSHIP** structure represents a processor core, the **GroupCount** member is always 1.

If the **PROCESSOR_RELATIONSHIP** structure represents a processor package, the **GroupCount** member is 1 only if all processors are in the same processor group. If the package contains more than one NUMA node, the system might assign different NUMA nodes to different processor groups. In this case, the **GroupCount** member is the number of groups to which NUMA nodes in the package are assigned.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity)

[GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)