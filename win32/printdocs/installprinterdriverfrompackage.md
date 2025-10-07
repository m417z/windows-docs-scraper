# InstallPrinterDriverFromPackage function

Installs a printer driver from a driver package that is in the print server's driver store.

## Parameters

*pszServer* \[in\]

A pointer to a constant, null-terminated string that specifies the name of the print server. **NULL** means the local computer.

*pszInfPath* \[in\]

A pointer to a constant, null-terminated string that specifies the driver store path to the print driver's .inf file. **NULL** means the driver is in an inf file that shipped with Windows.

*pszDriverName* \[in\]

A pointer to a constant, null-terminated string that specifies the name of the driver.

*pszEnvironment* \[in\]

A pointer to a constant, null-terminated string that specifies the processor architecture (for example, Windows NT x86). This can be **NULL**.

*dwFlags* \[in\]

This can only be 0 or IPDFP\_COPY\_ALL\_FILES. A value of 0 means that the printer driver must be added and any files in the printer driver directory that are newer than corresponding files currently in use must be copied. A value of IPDFP\_COPY\_ALL\_FILES means the printer driver and all the files in the printer driver directory must be added. The file time stamps are ignored when *dwFlags* has a value of IPDFP\_COPY\_ALL\_FILES.

## Return value

If the operation succeeds, the return value is S\_OK, otherwise the **HRESULT** will contain an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The driver store is typically either %windir%\\inf or %windir%\\System32\\DriverStore\\FileRepository.

**InstallPrinterDriverFromPackage** also installs other files in the package, such as color profiles and print processors.

Users must have printer administration rights to install either on a remote computer or on the local computer when the user is logged in with Terminal Services.

Only signed packages can be installed on a remote computer.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **InstallPrinterDriverFromPackageW** (Unicode) and **InstallPrinterDriverFromPackageA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

