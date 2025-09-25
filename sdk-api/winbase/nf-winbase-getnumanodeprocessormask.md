# GetNumaNodeProcessorMask function

## Description

Retrieves the processor mask for the specified node.

## Parameters

### `Node` [in]

The number of the node.

### `ProcessorMask` [out]

The processor mask for the node. A processor mask is a bit vector in which each bit represents a processor and whether it is in the node.

If the node has no processors configured, the processor mask is zero.

On systems with more than 64 processors, this parameter is set to the processor mask for the node only if the node is in the same [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) as the calling thread. Otherwise, the parameter is set to zero.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To retrieve the highest numbered node in the system, use the
[GetNumaHighestNodeNumber](https://learn.microsoft.com/windows/desktop/api/systemtopologyapi/nf-systemtopologyapi-getnumahighestnodenumber) function. Note that this number is not guaranteed to equal the total number of nodes in the system.

To ensure that all threads for your process run on the same node, use the
[SetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessaffinitymask) function with a process affinity mask that specifies processors in the same node.

Use the [GetNumaNodeProcessorMaskEx](https://learn.microsoft.com/windows/desktop/api/systemtopologyapi/nf-systemtopologyapi-getnumanodeprocessormaskex) function to retrieve the processor mask for a node in any processor group.

> [!NOTE]
> Starting with *TBD Release Iron*, the behavior of this and other NUMA functions has been modified to better support systems with nodes containing more that 64 processors. For more information about this change, including information about enabling the old behavior of this API, see [NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support).

### Behavior starting with TBD Release Iron

Each node is assigned a primary group by the system. The mask returned by **GetNumaNodeProcessorMask** is for the node's primary group and is only returned if the calling thread belongs to that group.

### Behavior in previous versions

The mask for the specified node is returned.

## See also

[GetNumaNodeProcessorMaskEx](https://learn.microsoft.com/windows/desktop/api/systemtopologyapi/nf-systemtopologyapi-getnumanodeprocessormaskex)

[GetNumaProcessorNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaprocessornode)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessaffinitymask)