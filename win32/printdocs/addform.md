# AddForm function

The **AddForm** function adds a form to the list of available forms that can be selected for the specified printer.

## Parameters

*hPrinter* \[in\]

A handle to the printer that supports printing with the specified form. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*Level* \[in\]

The level of the structure to which *pForm* points. This value must be 1 or 2.

*pForm* \[in\]

A pointer to a [**FORM\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/form-info-1) or [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2) structure.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

An application can determine which forms are available for a printer by calling the [**EnumForms**](https://learn.microsoft.com/windows/win32/printdocs/enumforms) function.

If *pForm* points to a [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2), then **AddForm** will fail if either a form with the specified name already exists or the structure's *pKeyword* value already exists.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**EnumForms**](https://learn.microsoft.com/windows/win32/printdocs/enumforms)

[**FORM\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/form-info-1)

[**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

