# AddPrinterDriver function

The **AddPrinterDriver** function installs a local or remote printer driver and associates the configuration, data, and driver files.

For more flexibility in installing or upgrading printer drivers, use the [**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex) function because it allows strict upgrade, strict downgrade, copying of newer files only, and copying of all files (regardless of the file time stamps).

> [!Note]
> Installing a printer driver without a driver package is no longer recommended. Use [**InstallPrinterDriverFromPackage**](https://learn.microsoft.com/windows/win32/printdocs/installprinterdriverfrompackage) instead.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the driver should be installed.

If *pName* is **NULL**, the driver will be installed locally.

*Level* \[in\]

The version of the structure to which *pDriverInfo* points.

This value can be 2, 3, 4, 6, or 8.

*pDriverInfo* \[in\]

A pointer to a structure containing printer driver information. This depends on the value of *Level*.

| Value | Printer Drive Structure |
|-------|------------------------------------------|
| 2 | [**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2) |
| 3 | [**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3) |
| 4 | [**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4) |
| 6 | [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6) |
| 8 | [**DRIVER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-8) |

If the **pEnvironment** member of the structure pointed to by *pDriverInfo* is **NULL**, the current environment of the caller/client (not of the destination/server) is used.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The caller must have the [SeLoadDriverPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

Before an application calls the **AddPrinterDriver** function, all files required by the driver must be copied to the system's printer-driver directory. An application can retrieve the name of this directory by calling the [**GetPrinterDriverDirectory**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriverdirectory) function.

An application can determine which printer drivers are currently installed by calling the [**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddPrinterDriverW** (Unicode) and **AddPrinterDriverA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex)

[**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2)

[**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3)

[**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4)

[**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6)

[**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers)

[**GetPrinterDriverDirectory**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriverdirectory)

