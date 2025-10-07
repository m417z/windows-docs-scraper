# NtQueryPerformanceCounter function

\[This function is not supported and should not be used. Use the **QueryPerformanceCounter** and **QueryPerformanceFrequency** functions instead.\]

Returns the current value of a performance counter and, optionally, the frequency of the performance counter.

## Parameters

*PerformanceCounter* \[out\]

The address of a variable to receive the current performance counter value.

*PerformanceFrequency* \[out, optional\]

The address of a variable to receive the performance counter frequency.

## Return value

If the function succeeds, it returns the **NTSTATUS** code **STATUS\_SUCCESS**; otherwise, it returns an error code such as **STATUS\_ACCESS\_VIOLATION**.

## Remarks

No header file is available for **NtQueryPerformanceCounter**. You should use the alternative functions named above, although you can also use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

Performance frequency is the frequency of the performance counter in hertz, specifically in counts per second. This value is implementation dependent. If the implementation does not have hardware to support performance timing, the value returned is 0.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

## See also

[**QueryPerformanceCounter**](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter)

[**QueryPerformanceFrequency**](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency)

