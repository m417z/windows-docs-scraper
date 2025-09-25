# IsWow64Process function

## Description

Determines whether the specified process is running under
[WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications) or an Intel64 of x64 processor.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the PROCESS_QUERY_INFORMATION access right.

### `Wow64Process` [out]

A pointer to a value that is set to TRUE if the process is running under WOW64 on an Intel64, x64, or ARM64 processor. If the process is running under 32-bit Windows, the value is set to FALSE. If the process is a 32-bit application running under 64-bit Windows 10 on ARM, the value is set to FALSE. If the process is a 64-bit application running under 64-bit Windows, the value is also set to FALSE.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications should use [IsWow64Process2](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-iswow64process2) instead of **IsWow64Process** to determine if a process is running under WOW. **IsWow64Process2** removes the ambiguity inherent to multiple WOW environments by explicitly returning both the architecture of the host and guest for a given process. Applications can use this information to reliably identify situations such as running under emulation on ARM64. To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## Examples

For compatibility with operating systems that do not support this function, call
[GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) to detect whether
**IsWow64Process** is implemented in Kernel32.dll. If **GetProcAddress** succeeds, it is safe to call this function. Otherwise, WOW64 is not present. Note that this technique is not a reliable way to detect whether the operating system is a 64-bit version of Windows because the Kernel32.dll in current versions of 32-bit Windows also contains this function.

```cpp
#include <windows.h>
#include <tchar.h>

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

BOOL IsWow64()
{
    BOOL bIsWow64 = FALSE;

    //IsWow64Process is not available on all supported versions of Windows.
    //Use GetModuleHandle to get a handle to the DLL that contains the function
    //and GetProcAddress to get a pointer to the function if available.

    fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
        GetModuleHandle(TEXT("kernel32")),"IsWow64Process");

    if(NULL != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
        {
            //handle error
        }
    }
    return bIsWow64;
}

int main( void )
{
    if(IsWow64())
        _tprintf(TEXT("The process is running under WOW64.\n"));
    else
        _tprintf(TEXT("The process is not running under WOW64.\n"));

    return 0;
}
```

## See also

[GetNativeSystemInfo](https://learn.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo)

[IsWow64Message](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-iswow64message)

[WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications)