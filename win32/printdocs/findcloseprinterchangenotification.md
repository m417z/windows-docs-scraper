# FindClosePrinterChangeNotification function

The **FindClosePrinterChangeNotification** function closes a change notification object created by calling the [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function. The printer or print server associated with the change notification object will no longer be monitored by that object.

## Parameters

*hChange* \[in\]

A handle to the change notification object to be closed. This is a handle created by calling the [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

After calling the **FindClosePrinterChangeNotification** function, you cannot use the *hChange* handle in subsequent calls to either [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) or [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification).

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

[**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification)

[**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification)

