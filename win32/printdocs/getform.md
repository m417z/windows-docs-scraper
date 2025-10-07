# GetForm function

The **GetForm** function retrieves information about a specified form.

## Parameters

*hPrinter* \[in\]

A handle to the printer. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pFormName* \[in\]

A pointer to a null-terminated string that specifies the name of the form. To get the names of the forms supported by the printer, call the [**EnumForms**](https://learn.microsoft.com/windows/win32/printdocs/enumforms) function.

*Level* \[in\]

The version of the structure to which *pForm* points. This value must be 1 or 2.

*pForm* \[out\]

A pointer to an array of bytes that receives the initialized [**FORM\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/form-info-1) or [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2) structure.

*cbBuf* \[in\]

The size, in bytes, of the *pForm* array.

*pcbNeeded* \[out\]

A pointer to a value that specifies the number of bytes copied if the function succeeds or the number of bytes required if *cbBuf* is too small.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

If the caller is remote, and the *Level* is 2, the **StringType** value of the returned [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2) will always be STRING\_LANGPAIR.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **GetFormW** (Unicode) and **GetFormA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddForm**](https://learn.microsoft.com/windows/win32/printdocs/addform)

[**DeleteForm**](https://learn.microsoft.com/windows/win32/printdocs/deleteform)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetForm**](https://learn.microsoft.com/windows/win32/printdocs/setform)

