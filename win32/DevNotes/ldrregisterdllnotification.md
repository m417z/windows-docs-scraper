# LdrRegisterDllNotification function

\[This function may be changed or removed from Windows without further notice.\]

Registers for notification when a DLL is first loaded. This notification occurs before dynamic linking takes place.

## Parameters

*Flags* \[in\]

This parameter must be zero.

*NotificationFunction* \[in\]

A pointer to an [*LdrDllNotification*](https://learn.microsoft.com/windows/win32/devnotes/ldrdllnotification) notification callback function to call when the DLL is loaded.

*Context* \[in, optional\]

A pointer to context data for the callback function.

*Cookie* \[out\]

A pointer to a variable to receive an identifier for the callback function. This identifier is used to unregister the notification callback function.

## Return value

If the function succeeds, it returns **STATUS\_SUCCESS**.

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

[*LdrDllNotification*](https://learn.microsoft.com/windows/win32/devnotes/ldrdllnotification)

[**LdrUnregisterDllNotification**](https://learn.microsoft.com/windows/win32/devnotes/ldrunregisterdllnotification)

