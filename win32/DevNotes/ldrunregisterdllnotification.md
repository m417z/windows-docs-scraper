# LdrUnregisterDllNotification function

\[This function may be changed or removed from Windows without further notice.\]

Cancels DLL load notification previously registered by calling the [**LdrRegisterDllNotification**](https://learn.microsoft.com/windows/win32/devnotes/ldrregisterdllnotification) function.

## Parameters

*Cookie* \[in\]

A pointer to the callback identifier received from the [**LdrRegisterDllNotification**](https://learn.microsoft.com/windows/win32/devnotes/ldrregisterdllnotification) call that registered for notification.

## Return value

Returns an **NTSTATUS** or error code.

If the function succeeds, it returns **STATUS\_SUCCESS**.

If the callback function is not found, the function returns **STATUS\_DLL\_NOT\_FOUND**.

The forms and significance of **NTSTATUS** error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Remarks

This function has no associated header file. The associated import library, Ntdll.lib, is available in the WDK. You can also use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Ntdll.dll |

## See also

[**LdrRegisterDllNotification**](https://learn.microsoft.com/windows/win32/devnotes/ldrregisterdllnotification)

