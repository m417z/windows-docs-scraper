# IsWow64Message function

## Description

Determines whether the last message read from the current thread's queue originated from a [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications) process.

## Return value

The function returns TRUE if the last message read from the current thread's queue originated from a WOW64 process, and FALSE otherwise.

## Remarks

This function is useful to helping you develop 64-bit native applications that can receive private messages sent from 32-bit client applications, if the messages are associated with data structures that contain pointer-dependent data. In these situations, you can call this function in your 64-bit native application to determine if the message originated from a WOW64 process and then thunk the message appropriately.

#### Examples

For compatibility with operating systems that do not support this function, call
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to detect whether
**IsWow64Message** is implemented in User32.dll. If **GetProcAddress** succeeds, it is safe to call this function. Otherwise, WOW64 is not present. Note that this technique is not a reliable way to detect whether the operating system is a 64-bit version of Windows because the User32.dll in current versions of 32-bit Windows also contains this function.

```cpp
#include <windows.h>
#include <tchar.h>

typedef BOOL (WINAPI *LPFN_ISWOW64MESSAGE) (void);

LPFN_ISWOW64MESSAGE fnIsWow64Message;

BOOL IsWow64Msg()
{
    // IsWow64Message is not available on all supported versions of Windows
    // Use LoadLibrary to ensure that the DLL containing the function is loaded
    // and GetProcAddress to get a pointer to the function if available.

    fnIsWow64Message = (LPFN_ISWOW64MESSAGE) GetProcAddress(
        LoadLibrary(TEXT("user32")), "IsWow64Message");

    if (NULL != fnIsWow64Message)
    {
        return (fnIsWow64Message());
    }
    else return FALSE;
}

int main( void )
{
    if(IsWow64Msg())
    {
        _tprintf(TEXT("The last message was from a 32-bit process.\n"));
    }
    else if (NULL == fnIsWow64Message )
    {
        _tprintf(TEXT("The IsWow64Message function is not available (%d).\n"), GetLastError());
    }
    else
    {
        _tprintf(TEXT("The last message was from a 64-bit process.\n"));
    }
    return 0;
}

```

## See also

[GetNativeSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo)

[IsWow64Process](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process)

[WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications)