# GetPrinterDriver2 function

The **GetPrinterDriver2** function retrieves driver data for the specified printer. If the driver is not installed on the local computer, **GetPrinterDriver2** installs it and displays any user interface to the specified window.

## Parameters

*hWnd* \[in, optional\]

A handle of the window that will be used as the parent window of any user interface, such as a dialog box, that the driver displays during installation. If the value of this parameter is **NULL**, the driver's user interface will still be displayed to the user during installation, but it will not have a parent window.

*hPrinter* \[in\]

A handle to the printer for which the driver data should be retrieved. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pEnvironment* \[in, optional\]

A pointer to a null-terminated string that specifies the environment (for example, Windows x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the current environment of the calling application and client machine (not of the destination application and print server) is used.

*Level* \[in\]

The printer driver structure returned in the *pDriverInfo* buffer. This parameter can be one of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------|-----------------------------------------------------|
| **1** | [**DRIVER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-1)<br> |
| **2** | [**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2)<br> |
| **3** | [**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3)<br> |
| **4** | [**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4)<br> |
| **5** | [**DRIVER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-5)<br> |
| **6** | [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6)<br> |
| **8** | [**DRIVER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-8)<br> |

*pDriverInfo* \[out\]

A pointer to a buffer that receives a structure containing information about the driver, as specified by *Level*. The buffer must be large enough to store the strings pointed to by the structure members.

To determine the required buffer size, call **GetPrinterDriver2** with *cbBuf* set to zero. **GetPrinterDriver2** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR\_INSUFFICIENT\_BUFFER**, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

*cbBuf* \[in\]

The size, in bytes, of the array at which *pDriverInfo* points.

*pcbNeeded* \[out\]

A pointer to a value that receives the number of bytes copied if the function succeeds or the number of bytes required if *cbBuf* is too small.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get the return status, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2), [**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3), [**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4), [**DRIVER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-5), [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6), and [**DRIVER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-8) structures contain the file name or the full path and file name of the printer driver in the **pDriverPath** member. An application can use the path and file name to load a printer driver by calling the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function and supplying the path and file name as the single argument.

The ANSI version of this function, **GetPrinterDriver2A** is not supported and returns **ERROR\_NOT\_SUPPORTED**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **GetPrinterDriver2W** (Unicode)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver)

[**DRIVER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-1)

[**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2)

[**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3)

[**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4)

[**DRIVER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-5)

[**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6)

[**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers)

[**GetPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

