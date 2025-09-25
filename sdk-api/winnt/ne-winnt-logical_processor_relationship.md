# LOGICAL_PROCESSOR_RELATIONSHIP enumeration

## Description

Represents the relationship between the processor set identified in the corresponding [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structure.

## Constants

### `RelationProcessorCore`

The specified logical processors share a single processor core.

### `RelationNumaNode`

The specified logical processors are part of the same NUMA node.

### `RelationCache`

The specified logical processors share a cache.

**Windows Server 2003:** This value is not supported until Windows Server 2003 with SP1 and Windows XP Professional x64 Edition.

### `RelationProcessorPackage`

The specified logical processors share a physical package (a single package socketed or soldered onto a motherboard may contain multiple processor cores or threads, each of which is treated as a separate processor by the operating system).

**Windows Server 2003:** This value is not supported until Windows Server 2003 with SP1 and Windows XP Professional x64 Edition.

### `RelationGroup`

The specified logical processors share a single [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP Professional x64 Edition:** This value is not supported until Windows Server 2008 R2.

### `RelationProcessorDie`

The specified logical processors share a single processor die.

### `RelationNumaNodeEx`

**Introduced in Windows Server 2022 (21H2, build 20348).** Requests that the full affinity be returned. Unlike the other relation types, **RelationNumaNodeEx** is not used on input. It is simply a request for **RelationNumaNode** with full group information.

### `RelationModule`

**Introduced in Windows 11 (21H2, build 22000).** The specified logical processors share a single processor module.

### `RelationAll:0xffff`

On input, retrieves information about all possible relationship types. This value is not used on output.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP Professional x64 Edition:** This value is not supported until Windows Server 2008 R2.

## Remarks

The value specified by this enumeration indicates the relationship represented in the corresponding [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structure.

#### Examples

For an example, see [GetLogicalProcessorInformation](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation).

## See also

[GetLogicalProcessorInformation](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation)

[GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)