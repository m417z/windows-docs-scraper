# SYSTEM_LOGICAL_PROCESSOR_INFORMATION structure

## Description

Describes the relationship between the specified processor set. This structure is used with the [GetLogicalProcessorInformation](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation) function.

## Members

### `ProcessorMask`

The processor mask identifying the processors described by this structure. A processor mask is a bit vector in which each set bit represents an active processor in the relationship. At least one bit will be set.

On a system with more than 64 processors, the processor mask identifies processors in a single [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups).

### `Relationship`

The relationship between the processors identified by the value of the **ProcessorMask** member. This member can be one of the following [LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-logical_processor_relationship) values.

| Value | Meaning |
| --- | --- |
| **RelationCache**<br><br>2 | The specified logical processors share a cache. The **Cache** member contains additional information.<br><br>**Windows Server 2003:** This value is not supported until Windows Server 2003 with SP1 and Windows XP Professional x64 Edition. |
| **RelationNumaNode**<br><br>1 | The specified logical processors are part of the same NUMA node. The **NumaNode** member contains additional information. |
| **RelationProcessorCore**<br><br>0 | The specified logical processors share a single processor core. The **ProcessorCore** member contains additional information. |
| **RelationProcessorPackage**<br><br>3 | The specified logical processors share a physical package. There is no additional information available.<br><br>**Windows Server 2003 and Windows XP Professional x64 Edition:** This value is not supported until Windows Server 2003 with SP1 and Windows XP with SP3. |

Future versions of Windows may support additional values for the **Relationship** member.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ProcessorCore`

This structure contains valid data only if the **Relationship** member is RelationProcessorCore.

### `DUMMYUNIONNAME.ProcessorCore.Flags`

If the value of this member is 1, the logical processors identified by the value of the **ProcessorMask** member share functional units, as in Hyperthreading or SMT. Otherwise, the identified logical processors do not share functional units.

**Windows Server 2003 and Windows XP Professional x64 Edition:** This member is also 1 for cores that share a physical package. Therefore, to determine whether the processor supports multiple cores or hyperthreading on systems prior to Windows Vista, use the CPUID instruction.

### `DUMMYUNIONNAME.NumaNode`

This structure contains valid data only if the **Relationship** member is RelationNumaNode.

### `DUMMYUNIONNAME.NumaNode.NodeNumber`

Identifies the [NUMA](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support) node. The valid values of this parameter are 0 to the highest NUMA node number inclusive. A non-NUMA multiprocessor system will report that all processors belong to one NUMA node.

### `DUMMYUNIONNAME.Cache`

A [CACHE_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-cache_descriptor) structure that identifies the characteristics of a particular cache. There is one record returned for each cache reported. Some or all caches may not be reported, depending on the mechanism used by the processor to identify its caches. Therefore, do not assume the absence of any particular caches. Caches are not necessarily shared among logical processors.

This structure contains valid data only if the **Relationship** member is RelationCache.

**Windows Server 2003:** This member is not supported until Windows Server 2003 with SP1 and Windows XP Professional x64 Edition.

### `DUMMYUNIONNAME.Reserved`

Reserved. Do not use.

## See also

[CACHE_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-cache_descriptor)

[GetLogicalProcessorInformation](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation)

[GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex)

[LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-logical_processor_relationship)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)