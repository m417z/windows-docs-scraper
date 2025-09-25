## Description

The **KeQueryNodeActiveAffinity** routine gets the current processor affinity of a specified node in a multiprocessor system that has a non-uniform memory access (NUMA) architecture.

## Parameters

### `NodeNumber` [in]

The node number. If a multiprocessor system contains *n* nodes, the nodes are numbered from 0 to *n*-1. To obtain the highest node number (*n*-1) in the system, call the [KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber) routine.

### `Affinity` [out, optional]

A pointer to a caller-allocated buffer into which the routine writes a [**GROUP_AFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) structure. This structure contains the group number of the group that contains the node that is identified by *NodeNumber*, and an affinity mask that indicates which logical processors in the node are active. You can set this parameter to **NULL** if you do not need this information.

Starting in Windows Server 2022, a node can span more than one group. This happens when a node contains more than 64 processors. In this case, the OS assigns a primary group for each NUMA node. The primary group is always the one containing the most processors. In this case, the group affinity structure returned is for the node's primary group. For more info about this change in behavior, see [NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support). If your code runs on systems with more than 64 processors per NUMA node, consider instead using [**KeQueryNodeActiveAffinity2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerynodeactiveaffinity2).

### `Count` [out, optional]

A pointer to a location into which the routine writes the number of active processors that are represented in the node affinity mask that is pointed to by *Affinity*. You can set this parameter to **NULL** if you do not need this information.

Starting in Windows Server 2022, count returned is for the node's primary group. See more info about primary groups above.

## Remarks

The caller-allocated buffer that is pointed to by the *Affinity* parameter must be large enough to contain a **GROUP_AFFINITY** structure. The **Mask** member of this structure contains an affinity mask that indicates which processors are active. If a processor is active, the corresponding bit in the mask is one. All other bits are zero.

In a NUMA multiprocessor architecture, a node is a collection of processors that share fast access to a region of memory. Memory access is non-uniform because a processor can access the memory in its node faster than it can access the memory in other nodes.

The number of processors in a node cannot exceed the number of bits in the affinity mask in the structure that is pointed to by *Affinity*. The affinity mask also determines the maximum number of processors in a group.

In Windows 10, version 2004 and earlier versions, if during system initialization, Windows encounters a NUMA hardware node that contains more logical processors than will fit into a group, Windows splits the node into smaller, logical nodes. Each of these nodes does not exceed the maximum group size. The *NodeNumber* parameter identifies a logical node. To obtain the maximum number of processors per group, call the [KeQueryMaximumProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumprocessorcountex) routine.

## See also

[KeQueryNodeActiveAffinity2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerynodeactiveaffinity2)

[KeQueryLogicalProcessorRelationship](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerylogicalprocessorrelationship)

[**GROUP_AFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)

[KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber)

[KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber)

[KeQueryMaximumProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumprocessorcountex)