# EnumPrinterDataEx function

The **EnumPrinterDataEx** function enumerates all value names and data for a specified printer and key.

Printer data is stored in the registry. While enumerating printer data, do not call registry functions that might change the data.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the function retrieves configuration data. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pKeyName* \[in\]

A pointer to a null-terminated string that specifies the key containing the values to enumerate. Use the backslash ( \\ ) character as a delimiter to specify a path with one or more subkeys. **EnumPrinterDataEx** enumerates all values of the key, but does not enumerate values of subkeys of the specified key. Use the [**EnumPrinterKey**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterkey) function to enumerate subkeys.

If *pKeyName* is **NULL** or an empty string, **EnumPrinterDataEx** returns ERROR\_INVALID\_PARAMETER.

*pEnumValues* \[out\]

A pointer to a buffer that receives an array of [**PRINTER\_ENUM\_VALUES**](https://learn.microsoft.com/windows/win32/printdocs/printer-enum-values) structures. Each structure contains the value name, type, data, and sizes of a value under the key.

*cbEnumValues* \[in\]

The size, in bytes, of the buffer pointed to by *pcbEnumValues*. If you set *cbEnumValues* to zero, the *pcbEnumValues* parameter returns the required buffer size.

*pcbEnumValues* \[out\]

A pointer to a variable that receives the size, in bytes, of the retrieved configuration data. If the buffer size specified by *cbEnumValues* is too small, the function returns ERROR\_MORE\_DATA and *pcbEnumValues* indicates the required buffer size.

*pnEnumValues* \[out\]

A pointer to a variable that receives the number of [**PRINTER\_ENUM\_VALUES**](https://learn.microsoft.com/windows/win32/printdocs/printer-enum-values) structures returned in *pEnumValues*.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a system error code.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

**EnumPrinterDataEx** retrieves printer configuration data set by the [**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex) and [**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **EnumPrinterDataExW** (Unicode) and **EnumPrinterDataExA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeletePrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdataex)

[**EnumPrinterKey**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterkey)

[**GetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**PRINTER\_ENUM\_VALUES**](https://learn.microsoft.com/windows/win32/printdocs/printer-enum-values)

[**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata)

[**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex)

