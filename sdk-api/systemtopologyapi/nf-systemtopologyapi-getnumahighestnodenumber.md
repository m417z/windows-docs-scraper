# GetNumaHighestNodeNumber function

## Description

Retrieves the node that currently has the highest number.

## Parameters

### `HighestNodeNumber` [out]

The number of the highest node.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The number of the highest node is not guaranteed to be the total number of nodes.

To retrieve a list of all processors in a node, use the
[GetNumaNodeProcessorMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumanodeprocessormask) function.

#### Examples

For an example, see [Allocating Memory from a NUMA Node](https://learn.microsoft.com/windows/desktop/Memory/allocating-memory-from-a-numa-node).

## See also

[GetNumaNodeProcessorMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumanodeprocessormask)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)