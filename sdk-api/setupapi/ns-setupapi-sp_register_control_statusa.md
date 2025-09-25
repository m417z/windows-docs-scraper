# SP_REGISTER_CONTROL_STATUSA structure

## Description

The
**SP_REGISTER_CONTROL_STATUS** structure contains information about a file being registered or unregistered using the **RegisterDlls** INF directive to self-register DLLs on Windows 2000.

When
[SetupInstallFromInfSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfrominfsectiona) sends a
[SPFILENOTIFY_STARTREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-startregistration) or
[SPFILENOTIFY_ENDREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-endregistration) notification to the callback routine, the caller must provide a pointer to a **SP_REGISTER_CONTROL_STATUS** structure in the *MsgHandler* parameter.

## Members

### `cbSize`

### `FileName`

Fully qualified path of the file being registered or unregistered.

### `Win32Error`

For an SPFILENOTIFY_STARTREGISTRATION notification, this member is not used and should be set to NO_ERROR. For a SPFILENOTIFY_ENDREGISTRATION notification, set to a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

### `FailureCode`

For a SPFILENOTIFY_STARTREGISTRATION notification, this member is not used and should be set to SPREG_SUCCESS. For a SPFILENOTIFY_ENDREGISTRATION notification, set to one of the following failure codes that indicate the result of registration.

| Value | Meaning |
| --- | --- |
| **SPREG_SUCCESS** | The file was successfully registered or unregistered. **WinError** not used. |
| **SPREG_LOADLIBRARY** | **LoadLibrary** failed for the file. **WinError** contains an extended error code from the component. |
| **SPREG_GETPROCADDR** | **GetProcAddress** failed for the file. **WinError** contains an extended error code from the component. |
| **SPREG_REGSVR** | **DLLRegisterServer** entry point returned failure. **WinError** contains an extended error code from the component. |
| **SPREG_DLLINSTALL** | **DLLInstall** entry point returned failure. **WinError** contains an extended error code from the component. |
| **SPREG_TIMEOUT** | The file registration or unregistration exceeded the specified timeout. **WinError** is set to ERROR_TIMEOUT. |
| **SPREG_UNKNOWN** | File registration or unregistration failed for an unknown reason. **WinError** indicates an extended error code from the component. |

### `cbsize`

Size of the structure, in bytes.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SPFILENOTIFY_ENDREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-endregistration)

[SPFILENOTIFY_STARTREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-startregistration)

[SetupInstallFromInfSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfrominfsectiona)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)

## Remarks

> [!NOTE]
> The setupapi.h header defines SP_REGISTER_CONTROL_STATUS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).