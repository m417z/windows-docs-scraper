# GetNumaAvailableMemoryNodeEx function

## Description

Retrieves the amount of memory that is available in a node specified as a **USHORT** value.

## Parameters

### `Node` [in]

The number of the node.

### `AvailableBytes` [out]

The amount of available memory for the node, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetNumaAvailableMemoryNodeEx** function returns the amount of memory consumed by free and zeroed pages on the specified node. On systems with more than one node, this memory does not include standby pages. Therefore, the sum of the available memory values for all nodes in the system is equal to the value of the Free & Zero Page List Bytes memory performance counter. On systems with only one node, the value returned by [GetNumaAvailableMemoryNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaavailablememorynode) includes standby pages and is equal to the value of the Available Bytes memory performance counter. For more information about performance counters, see [Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85)).

The only difference between the **GetNumaAvailableMemoryNodeEx** function and the [GetNumaAvailableMemoryNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaavailablememorynode) function is the data type of the *Node* parameter.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[GetNumaAvailableMemoryNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaavailablememorynode)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)