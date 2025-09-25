# QueryIdleProcessorCycleTimeEx function

## Description

Retrieves the accumulated cycle time for the idle thread on each logical processor in the specified processor group.

## Parameters

### `Group` [in]

The number of the processor group for which to retrieve the cycle time.

### `BufferLength` [in, out]

On input, specifies the size of the *ProcessorIdleCycleTime* buffer, in bytes. This buffer is expected to be 8 times the number of processors in the group.

On output, specifies the number of elements written to the buffer. If the buffer size is not sufficient, the function fails and this parameter receives the required length of the buffer.

### `ProcessorIdleCycleTime` [out]

The number of CPU clock cycles used by each idle thread. If this parameter is NULL, the function updates the *BufferLength* parameter with the required length.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror).

## Remarks

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)

[QueryIdleProcessorCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryidleprocessorcycletime)