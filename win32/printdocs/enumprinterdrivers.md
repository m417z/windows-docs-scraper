# EnumPrinterDrivers function

The **EnumPrinterDrivers** function enumerates the printer drivers installed on a specified printer server.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the printer drivers are enumerated.

If *pName* is **NULL**, the function enumerates the local printer drivers.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment (for example, Windows x86, Windows IA64, Windows x64, or Windows NT R4000). If this parameter is **NULL**, the function uses the current environment of the caller/client (not of the destination/server).

If the *pEnvironment* string specifies "all", **EnumPrinterDrivers** enumerates printer drivers for all platforms installed on the specified server.

*Level* \[in\]

The type of information structure returned in the *pDriverInfo* buffer. It can be one of the following.

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

A pointer to a buffer that receives an array of DRIVER\_INFO\_\* structures, as specified by *Level*. Each structure contains data that describes an available printer driver. The buffer must be large enough to receive the array of structures and any strings or other data to which the structure members point.

To determine the required buffer size, call **EnumPrinterDrivers** with *cbBuf* set to zero. **EnumPrinterDrivers** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INSUFFICIENT\_BUFFER, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

*cbBuf* \[in\]

The size, in bytes, of the buffer pointed to by *pDriverInfo*

*pcbNeeded* \[out\]

A pointer to a variable that receives the number of bytes copied to the *pDriverInfo* buffer if the function succeeds. If the buffer is too small, the function fails and the variable receives the number of bytes required.

*pcReturned* \[out\]

A pointer to a variable that receives the number of structures returned in the *pDriverInfo* buffer. This is the number of printer drivers installed on the specified print server.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **EnumPrinterDriversW** (Unicode) and **EnumPrinterDriversA** (ANSI)<br> |

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

[**GetPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver)

