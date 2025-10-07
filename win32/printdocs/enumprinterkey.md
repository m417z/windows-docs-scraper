# EnumPrinterKey function

The **EnumPrinterKey** function enumerates the subkeys of a specified key for a specified printer.

Printer data is stored in the registry. While enumerating printer data, do not call registry functions that might change the data.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the function enumerates subkeys. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pKeyName* \[in\]

A pointer to a null-terminated string that specifies the key containing the subkeys to enumerate. Use the backslash '\\' character as a delimiter to specify a path with one or more subkeys. **EnumPrinterKey** enumerates all subkeys of the key, but does not enumerate the subkeys of those subkeys.

If *pKeyName* is an empty string (""), **EnumPrinterKey** enumerates the top-level key for the printer. If *pKeyName* is **NULL**, **EnumPrinterKey** returns ERROR\_INVALID\_PARAMETER.

*pSubkey* \[out\]

A pointer to a buffer that receives an array of null-terminated subkey names. The array is terminated by two null characters.

*cbSubkey* \[in\]

The size, in bytes, of the buffer pointed to by *pSubkey*. If you set *cbSubkey* to zero, the *pcbSubkey* parameter returns the required buffer size.

*pcbSubkey* \[out\]

A pointer to a variable that receives the number of bytes retrieved in the *pSubkey* buffer. If the buffer size specified by *cbSubkey* is too small, the function returns ERROR\_MORE\_DATA and *pcbSubkey* indicates the required buffer size.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a system error code. If *pKeyName* does not exist, the return value is ERROR\_FILE\_NOT\_FOUND.

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
| Unicode and ANSI names<br> | **EnumPrinterKeyW** (Unicode) and **EnumPrinterKeyA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeletePrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdataex)

[**GetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex)

