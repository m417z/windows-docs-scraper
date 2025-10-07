# EnumPrinterData function

The **EnumPrinterData** function enumerates configuration data for a specified printer.

To retrieve the configuration data in a single call, use the [**EnumPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex) function.

## Parameters

*hPrinter* \[in\]

A handle to the printer whose configuration data is to be obtained. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*dwIndex* \[in\]

An index value that specifies the configuration data value to retrieve.

Set this parameter to zero for the first call to **EnumPrinterData** for a specified printer handle. Then increment the parameter by one for subsequent calls involving the same printer, until the function returns ERROR\_NO\_MORE\_ITEMS. See the following Remarks section for further information.

If you use the technique mentioned in the descriptions of the *cbValueName* and *cbData* parameters to obtain adequate buffer size values, setting both those parameters to zero in a first call to **EnumPrinterData** for a specified printer handle, the value of *dwIndex* does not matter for that call. Set *dwIndex* to zero in the next call to **EnumPrinterData** to start the actual enumeration process.

Configuration data values are not ordered. New values will have an arbitrary index. This means that the **EnumPrinterData** function may return values in any order.

*pValueName* \[out\]

A pointer to a buffer that receives the name of the configuration data value, including a terminating null character.

*cbValueName* \[in\]

The size, in bytes, of the buffer pointed to by *pValueName*.

If you want to have the operating system supply an adequate buffer size, set both this parameter and the *cbData* parameter to zero for the first call to **EnumPrinterData** for a specified printer handle. When the function returns, the variable pointed to by *pcbValueName* will contain a buffer size that is large enough to successfully enumerate all of the printer's configuration data value names.

*pcbValueName* \[out\]

A pointer to a variable that receives the number of bytes stored into the buffer pointed to by *pValueName*.

*pType* \[out\]

A pointer to a variable that receives a code indicating the type of data stored in the specified value. For a list of the possible type codes, see [Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types). The *pType* parameter can be **NULL** if the type code is not required.

*pData* \[out\]

A pointer to a buffer that receives the configuration data value.

This parameter can be **NULL** if the configuration data value is not required.

*cbData* \[in\]

The size, in bytes, of the buffer pointed to by *pData*.

If you want to have the operating system supply an adequate buffer size, set both this parameter and the *cbValueName* parameter to zero for the first call to **EnumPrinterData** for a specified printer handle. When the function returns, the variable pointed to by *pcbData* will contain a buffer size that is large enough to successfully enumerate all of the printer's configuration data value names.

*pcbData* \[out\]

A pointer to a variable that receives the number of bytes stored into the buffer pointed to by *pData*.

This parameter can be **NULL** if *pData* is **NULL**.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a system error code.

The function returns ERROR\_NO\_MORE\_ITEMS when there are no more configuration data values to retrieve for a specified printer handle.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

**EnumPrinterData** retrieves printer configuration data set by the [**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata) function. A printer's configuration data consists of a set of named and typed values. The **EnumPrinterData** function obtains one of these values, and its name and a type code, each time you call it. Call the **EnumPrinterData** function several times in succession to obtain all of a printer's configuration data values.

Printer configuration data is stored in the registry. While enumerating printer configuration data, you should avoid calling registry functions that might change that data.

If you want to have the operating system supply an adequate buffer size, first call **EnumPrinterData** with both the *cbValueName* and *cbData* parameters set to zero, as noted earlier in the Parameters section. The value of *dwIndex* does not matter for this call. When the function returns, \**pcbValueName* and \**pcbData* will contain buffer sizes that are large enough to enumerate all of the printer's configuration data value names and values. On the next call, allocate value name and data buffers, set *cbValueName* and *cbData* to the sizes in bytes of the allocated buffers, and set *dwIndex* to zero. Thereafter, continue to call the **EnumPrinterData** function, incrementing *dwIndex* by one each time, until the function returns ERROR\_NO\_MORE\_ITEMS.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **EnumPrinterDataW** (Unicode) and **EnumPrinterDataA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeletePrinterData**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdata)

[**EnumPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex)

[**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata)

