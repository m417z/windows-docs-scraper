# EnumForms function

The **EnumForms** function enumerates the forms supported by the specified printer.

## Parameters

*hPrinter* \[in\]

Handle to the printer for which the forms should be enumerated. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*Level* \[in\]

Specifies the version of the structure to which *pForm* points. This value must be 1 or 2.

*pForm* \[out\]

Pointer to one or more [**FORM\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/form-info-1) structures or to one or more [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2) structures. All the structures will have the same level.

*cbBuf* \[in\]

Specifies the size, in bytes, of the buffer to which *pForm* points.

*pcbNeeded* \[out\]

Pointer to a variable that receives the number of bytes copied to the array to which *pForm* points (if the operation succeeds) or the number of bytes required (if it fails because *cbBuf* is too small).

*pcReturned* \[out\]

Pointer to a variable that receives the number of structures copied into the array to which *pForm* points.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

If the caller is remote, and the *Level* is 2, the **StringType** value of the returned [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2) structures will always be **STRING\_LANGPAIR**.

In Windows Vista, the form data returned by **EnumForms** is retrieved from a local cache when *hPrinter* refers to a remote print server or a printer hosted by a print server and there is at least one open connection to a printer on the remote print server. In all other configurations, the form data is queried from the remote print server.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **EnumFormsW** (Unicode) and **EnumFormsA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter)

[**FORM\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/form-info-1)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

