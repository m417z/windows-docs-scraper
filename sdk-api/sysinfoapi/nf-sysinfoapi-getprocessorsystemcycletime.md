# GetProcessorSystemCycleTime function

## Description

Retrieves the cycle time each processor in the specified processor group spent executing deferred procedure calls (DPCs) and interrupt service routines (ISRs) since the processor became active.

## Parameters

### `Group` [in]

The number of the processor group for which to retrieve the cycle time.

### `Buffer` [out]

A pointer to a buffer to receive a SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION structure for each processor in the group. On output, the DWORD64 **CycleTime** member of this structure is set to the cycle time for one processor.

### `ReturnedLength` [in, out]

The size of the buffer, in bytes. When the function returns, this parameter contains the number of bytes written to *Buffer*. If the buffer is too small for the data, the function fails with ERROR_INSUFFICIENT_BUFFER and sets the *ReturnedLength* parameter to the required buffer size.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the error value is ERROR_INSUFFICIENT_BUFFER, the *ReturnedLength* parameter contains the required buffer size.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)