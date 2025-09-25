# GetNumaAvailableMemoryNode function

## Description

Retrieves the amount of memory available in the specified node.

Use the [GetNumaAvailableMemoryNodeEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaavailablememorynodeex) function to specify the node as a **USHORT** value.

## Parameters

### `Node` [in]

The number of the node.

### `AvailableBytes` [out]

The amount of available memory for the node, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetNumaAvailableMemoryNode** function returns the amount of memory consumed by free and zeroed pages on the specified node. On systems with more than one node, this memory does not include standby pages. Therefore, the sum of the available memory values for all nodes in the system is equal to the value of the Free & Zero Page List Bytes memory performance counter. On systems with only one node, the value returned by **GetNumaAvailableMemoryNode** includes standby pages and is equal to the value of the Available Bytes memory performance counter. For more information about performance counters, see [Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85)).

## See also

[GetNumaAvailableMemoryNodeEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaavailablememorynodeex)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)