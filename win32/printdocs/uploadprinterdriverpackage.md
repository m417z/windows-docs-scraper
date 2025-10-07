# UploadPrinterDriverPackage function

Uploads a printer driver to the print server's driver store so that it can be installed by calling [**InstallPrinterDriverFromPackage**](https://learn.microsoft.com/windows/win32/printdocs/installprinterdriverfrompackage).

## Parameters

*pszServer* \[in\]

A pointer to a constant, null-terminated string that specifies the name of the print server. Use **NULL** if the server is the local computer.

*pszInfPath* \[in\]

A pointer to a constant ,null-terminated string that specifies the source path to the driver's .inf file.

*pszEnvironment* \[in\]

A pointer to a constant, null-terminated string that specifies the server's processor architecture (for example, Windows NT x86). This can be **NULL**.

*dwFlags* \[in\]

This can be any of the following values:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **UPDP_SILENT_UPLOAD** | The UI will not be shown during the upload.<br> |
| **UPDP_UPLOAD_ALWAYS** | The files will be uploaded even if the package is already in the server's driver store.<br> |
| **UPDP_CHECK_DRIVERSTORE** | The server's driver store will be checked before upload to see if the package is already there. This setting is ignored if UPDP_UPLOAD_ALWAYS is set.<br> |

*hwnd* \[in\]

A handle to the copying user interface.

*pszDestInfPath* \[out\]

A pointer to the destination path, in the driver store, to which the driver's .inf file was copied.

*pcchDestInfPath* \[in, out\]

On input, specifies the size, in characters, of the *pszDestInfPath* buffer. On output, receives the size, in characters, of the path string, including the terminating null character.

## Return value

If the operation succeeds, the return value is S_OK, otherwise the **HRESULT** will contain an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The driver store is typically either %windir%\\inf or %windir%\\System32\\DriverStore\\FileRepository.

Only one package at a time can be uploaded. If a package is dependent on others, they must be uploaded separately.

Only signed driver packages can be uploaded.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **UploadPrinterDriverPackageW** (Unicode) and **UploadPrinterDriverPackageA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

