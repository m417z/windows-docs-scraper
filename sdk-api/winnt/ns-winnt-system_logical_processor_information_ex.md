# SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX structure

## Description

Contains information about the relationships of logical processors and related hardware. The [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) function uses this structure.

## Members

### `Relationship`

The type of relationship between the logical processors. This parameter can be one of the [LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-logical_processor_relationship) enumeration values.

### `Size`

The size of the structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Processor`

A [PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_relationship) structure that describes processor affinity. This structure contains valid data only if the **Relationship** member is **RelationProcessorCore**, **RelationProcessorDie**, **RelationProcessorModule** or **RelationProcessorPackage**.

### `DUMMYUNIONNAME.NumaNode`

A [NUMA_NODE_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-numa_node_relationship) structure that describes a NUMA node. This structure contains valid data only if the **Relationship** member is **RelationNumaNode** or **RelationNumaNodeEx**.

### `DUMMYUNIONNAME.Cache`

A [CACHE_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-cache_relationship) structure that describes cache attributes. This structure contains valid data only if the **Relationship** member is **RelationCache**.

### `DUMMYUNIONNAME.Group`

A [GROUP_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_relationship) structure that contains information about the processor groups. This structure contains valid data only if the **Relationship** member is **RelationGroup**.

## See also

[CACHE_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-cache_relationship)

[GROUP_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_relationship)

[NUMA_NODE_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-numa_node_relationship)

[PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_relationship)