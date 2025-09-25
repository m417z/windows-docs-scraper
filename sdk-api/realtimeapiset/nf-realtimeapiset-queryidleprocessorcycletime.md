# QueryIdleProcessorCycleTime function

## Description

Retrieves the cycle time for the idle thread of each processor in the system.

On a system with more than 64 processors, this function retrieves the cycle time for the idle thread of each processor in the [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to which the calling thread is assigned. Use the [QueryIdleProcessorCycleTimeEx](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryidleprocessorcycletimeex) function to retrieve the cycle time for the idle thread on each logical processor for a specific processor group.

## Parameters

### `BufferLength` [in, out]

On input, specifies the size of the *ProcessorIdleCycleTime* buffer, in bytes. This buffer is expected to be 8 times the number of processors in the group.

On output, specifies the number of elements written to the buffer. If the buffer size is not sufficient, the function fails and this parameter receives the required length of the buffer.

### `ProcessorIdleCycleTime` [out]

The number of CPU clock cycles used by each idle thread. This buffer must be 8 times the number of processors in the system in size.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later.

## See also

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)

[QueryIdleProcessorCycleTimeEx](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryidleprocessorcycletimeex)

[QueryProcessCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryprocesscycletime)

[QueryThreadCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-querythreadcycletime)