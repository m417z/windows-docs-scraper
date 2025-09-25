# SetThreadIdealProcessorEx function

## Description

Sets the ideal processor for the specified thread and optionally retrieves the previous ideal processor.

## Parameters

### `hThread` [in]

A handle to the thread for which to set the ideal processor. This handle must have been created with the THREAD_SET_INFORMATION access right. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `lpIdealProcessor` [in]

A pointer to a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number) structure that specifies the processor number of the desired ideal processor.

### `lpPreviousIdealProcessor` [out, optional]

A pointer to a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number) structure to receive the previous ideal processor. This parameter can point to the same memory location as the *lpIdealProcessor* parameter. This parameter can be NULL if the previous ideal processor is not required.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, it returns zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Specifying a thread ideal processor provides a hint to the scheduler about the preferred processor for a thread. The scheduler runs the thread on the thread's ideal processor when possible.

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default.
The **SetThreadIdealProcessorEx**, in setting the preferred processor, also sets the thread's primary group to the group of the preferred processor.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetThreadIdealProcessorEx](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadidealprocessorex)

[SetThreadIdealProcessor](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadidealprocessor)