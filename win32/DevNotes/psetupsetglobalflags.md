# pSetupSetGlobalFlags function

\[This function is not available in Windows Vista or Windows Server 2008.\]

Disables features.

## Parameters

*Value* \[in\]

The flags used to disable user interface or automatic backup.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------|
| **PSPGF\_NONINTERACTIVE**<br>0x004 | Set to disable user interface.<br> |
| **PSPGF\_NO\_BACKUP**<br>0x002 | Set to disable automatic backup.<br> |

## Return value

This function does not return a value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Setupapi.dll |

