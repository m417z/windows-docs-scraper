# GetThreadIdealProcessorEx function

## Description

Retrieves the processor number of the ideal processor for the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread for which to retrieve the ideal processor. This handle must have been created with the THREAD_QUERY_LIMITED_INFORMATION access right. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `lpIdealProcessor` [out]

Points to [PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number) structure to receive the number of the ideal processor.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, it returns zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[SetThreadIdealProcessorEx](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadidealprocessorex)