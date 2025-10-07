# GetDefaultPrinter function

The **GetDefaultPrinter** function retrieves the printer name of the default printer for the current user on the local computer.

## Parameters

*pszBuffer* \[in\]

A pointer to a buffer that receives a null-terminated character string containing the default printer name. If this parameter is **NULL**, the function fails and the variable pointed to by *pcchBuffer* returns the required buffer size, in characters.

*pcchBuffer* \[in, out\]

On input, specifies the size, in characters, of the *pszBuffer* buffer. On output, receives the size, in characters, of the printer name string, including the terminating null character.

## Return value

If the function succeeds, the return value is a nonzero value and the variable pointed to by *pcchBuffer* contains the number of characters copied to the *pszBuffer* buffer, including the terminating null character.

If the function fails, the return value is zero.

| Value | Meaning |
|-----------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| ERROR\_INSUFFICIENT\_BUFFER | The *pszBuffer* buffer is too small. The variable pointed to by *pcchBuffer* contains the required buffer size, in characters. |
| ERROR\_FILE\_NOT\_FOUND | There is no default printer. |

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
| Unicode and ANSI names<br> | **GetDefaultPrinterW** (Unicode) and **GetDefaultPrinterA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**SetDefaultPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setdefaultprinter)

