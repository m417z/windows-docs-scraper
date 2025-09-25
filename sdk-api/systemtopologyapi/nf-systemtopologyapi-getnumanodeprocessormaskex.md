# GetNumaNodeProcessorMaskEx function

## Description

Retrieves the processor mask for a node regardless of the processor group the node belongs to.

## Parameters

### `Node` [in]

The node number.

### `ProcessorMask` [out]

A pointer to a [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structure that receives the processor mask for the specified node. A processor mask is a bit vector in which each bit represents a processor and whether it is in the node.

If the specified node has no processors configured, the **Mask** member is zero and the **Group** member is undefined.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **GetNumaNodeProcessorMaskEx** function differs from [GetNumaNodeProcessorMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumanodeprocessormask) in that it can retrieve the processor mask for a node regardless of the group the node belongs to. That is, the node does not have to be in the same group as the calling thread. The **GetNumaNodeProcessorMask** function can retrieve the processor mask only for nodes that are in the same group as the calling thread.

To retrieve the highest numbered node in the system, use the
[GetNumaHighestNodeNumber](https://learn.microsoft.com/windows/desktop/api/systemtopologyapi/nf-systemtopologyapi-getnumahighestnodenumber) function. Note that this number is not guaranteed to equal the total number of nodes in the system.

To ensure that all threads for your process run on the same node, use the
[SetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessaffinitymask) function with a process affinity mask that specifies processors in the same node.

To compile an application that uses this function, set **_WIN32_WINNT** >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> Starting with *TBD Release Iron*, the behavior of this and other NUMA functions has been modified to better support systems with nodes containing more that 64 processors. For more information about this change, including information about enabling the old behavior of this API, see [NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support).

### Behavior starting with TBD Release Iron

Each node is assigned a primary group by the system. The **GROUP_AFFINITY** returned by **GetNumaNodeProcessorMaskEx** is for the node's primary group.

### Behavior in previous versions

The **GROUP_AFFINITY** for the specified node is returned.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity)

[GetNumaNodeProcessorMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumanodeprocessormask)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)