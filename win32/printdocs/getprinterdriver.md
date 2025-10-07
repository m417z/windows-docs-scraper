# GetPrinterDriver function

The **GetPrinterDriver** function retrieves driver data for the specified printer. If the driver is not installed on the local computer, **GetPrinterDriver** installs it.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the driver data should be retrieved. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment (for example, Windows x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the current environment of the calling application and client machine (not of the destination application and print server) is used.

*Level* \[in\]

The printer driver structure returned in the *pDriverInfo* buffer. This parameter can be one of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------|-----------------------------------------------------|
|

**1**

| [**DRIVER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-1)<br> |
|

**2**

| [**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2)<br> |
|

**3**

| [**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3)<br> |
|

**4**

| [**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4)<br> |
|

**5**

| [**DRIVER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-5)<br> |
|

**6**

| [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6)<br> |
|

**8**

| [**DRIVER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-8)<br> |

*pDriverInfo* \[out\]

A pointer to a buffer that receives a structure containing information about the driver, as specified by Level. The buffer must be large enough to store the strings pointed to by the structure members.

To determine the required buffer size, call **GetPrinterDriver** with *cbBuf* set to zero. **GetPrinterDriver** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INSUFFICIENT\_BUFFER, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

*cbBuf* \[in\]

The size, in bytes, of the array at which *pDriverInfo* points.

*pcbNeeded* \[out\]

A pointer to a value that receives the number of bytes copied if the function succeeds or the number of bytes required if *cbBuf* is too small.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

For a non-existent driver, the function returns ERROR\_UNKNOWN\_PRINTER\_DRIVER.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The [**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2), [**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3), [**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4), [**DRIVER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-5), and [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6) structures contain the file name or the full path and file name of the printer driver in the **pDriverPath** member. An application can use the path and file name to load a printer driver by calling the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function and supplying the path and file name as the single argument.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **GetPrinterDriverW** (Unicode) and **GetPrinterDriverA** (ANSI)<br> |

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

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

