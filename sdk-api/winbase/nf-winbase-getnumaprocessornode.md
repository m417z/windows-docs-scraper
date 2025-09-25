# GetNumaProcessorNode function

## Description

Retrieves the node number for the specified processor.

Use the [GetNumaProcessorNodeEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaprocessornodeex) function to specify a processor group and retrieve the node number as a **USHORT** value.

## Parameters

### `Processor` [in]

The processor number.

On a system with more than 64 logical processors, the processor number is relative to the [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) that contains the processor on which the calling thread is running.

### `NodeNumber` [out]

The node number. If the processor does not exist, this parameter is 0xFF.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To retrieve the list of processors on the system, use the
[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask) function.

#### Examples

For an example, see [Allocating Memory from a NUMA Node](https://learn.microsoft.com/windows/desktop/Memory/allocating-memory-from-a-numa-node).

## See also

[GetNumaNodeProcessorMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumanodeprocessormask)

[GetNumaProcessorNodeEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaprocessornodeex)

[GetNumaProximityNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaproximitynode)

[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)