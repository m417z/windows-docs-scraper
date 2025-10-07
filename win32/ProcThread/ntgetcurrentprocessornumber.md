# NtGetCurrentProcessorNumber function

\[**NtGetCurrentProcessorNumber** may be altered or unavailable in future versions of Windows. Applications should use the [**GetCurrentProcessorNumber**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessornumber) function instead.\]

Retrieves the number of the processor the current thread was running on during the call to this function.

## Parameters

This function has no parameters.

## Return value

The function returns the current processor number.

## Remarks

This function is used to provide information for estimating process performance.

This function has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

## See also

[Multiple Processors](https://learn.microsoft.com/windows/win32/procthread/multiple-processors)

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/procthread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/win32/procthread/child-processes)

