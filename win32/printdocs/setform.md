# SetForm function

The **SetForm** function sets the form information for the specified printer.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the form information is set. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pFormName* \[in\]

A pointer to a null-terminated string that specifies the form name for which the form information is set.

*Level* \[in\]

The version of the structure to which *pForm* points. This value must be 1 or 2.

*pForm* \[in\]

A pointer to a [**FORM\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/form-info-1) or [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2) structure.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

**SetForm** can be called multiple times for an existing [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2), each call adding additional pairs of **pDisplayName** and **wLangId** values. All languages versions of the form will get the **Size** and **ImageableArea** values of the **FORM\_INFO\_2** in the most recent call to **SetForm**.

If the caller is remote and the *Level* is 2, the **StringType** value of the [**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2) cannot be STRING\_MUIDLL.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **SetFormW** (Unicode) and **SetFormA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**GetForm**](https://learn.microsoft.com/windows/win32/printdocs/getform)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**FORM\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/form-info-1)

[**FORM\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/form-info-2)

