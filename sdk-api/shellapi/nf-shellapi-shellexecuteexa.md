# ShellExecuteExA function

## Description

Performs an operation on a specified file.

## Parameters

### `pExecInfo` [in, out]

Type: **SHELLEXECUTEINFO***

A pointer to a [SHELLEXECUTEINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shellexecuteinfoa) structure that contains and receives information about the application being executed.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

Because **ShellExecuteEx** can delegate execution to Shell extensions (data sources, context menu handlers, verb implementations) that are activated using Component Object Model (COM), COM should be initialized before **ShellExecuteEx** is called. Some Shell extensions require the COM single-threaded apartment (STA) type. In that case, COM should be initialized as shown here:

``` syntax
CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE)
```

There are instances where **ShellExecuteEx** does not use one of these types of Shell extension and those instances would not require COM to be initialized at all. Nonetheless, it is good practice to always initialize COM before using this function.

When DLLs are loaded into your process, you acquire a lock known as a [loader lock](https://learn.microsoft.com/windows/win32/win7appqual/preventing-hangs-in-windows-applications). The [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function always executes under the loader lock. It is important that you do not call **ShellExecuteEx** while you hold a loader lock. Because **ShellExecuteEx** is extensible, you could load code that does not function properly in the presence of a loader lock, risking a deadlock and therefore an unresponsive thread.

With multiple monitors, if you specify an **HWND** and set the **lpVerb** member of the [SHELLEXECUTEINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shellexecuteinfoa) structure pointed to by *lpExecInfo* to "Properties", any windows created by **ShellExecuteEx** might not appear in the correct position.

If the function succeeds, it sets the **hInstApp** member of the [SHELLEXECUTEINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shellexecuteinfoa) structure to a value greater than 32. If the function fails, **hInstApp** is set to the [SE_ERR_XXX](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) error value that best indicates the cause of the failure. Although **hInstApp** is declared as an HINSTANCE for compatibility with 16-bit Windows applications, it is not a true HINSTANCE. It can be cast only to an **int** and can be compared only to either the value 32 or the SE_ERR_XXX error codes.

The SE_ERR_XXX error values are provided for compatibility with [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea). To retrieve more accurate error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). It may return one of the following values.

| Error | Description |
| --- | --- |
| ERROR_FILE_NOT_FOUND | The specified file was not found. |
| ERROR_PATH_NOT_FOUND | The specified path was not found. |
| ERROR_DDE_FAIL | The Dynamic Data Exchange (DDE) transaction failed. |
| ERROR_NO_ASSOCIATION | There is no application associated with the specified file name extension. |
| ERROR_ACCESS_DENIED | Access to the specified file is denied. |
| ERROR_DLL_NOT_FOUND | One of the library files necessary to run the application can't be found. |
| ERROR_CANCELLED | The function prompted the user for additional information, but the user canceled the request. |
| ERROR_NOT_ENOUGH_MEMORY | There is not enough memory to perform the specified action. |
| ERROR_SHARING_VIOLATION | A sharing violation occurred. |

**Opening items from a URL** You can register your application to activate when passed URLs. You can also specify which protocols your application supports. See [Application Registration](https://learn.microsoft.com/windows/desktop/shell/app-registration) for more info.

**Site chain support** As of Windows 8, you can provide a site chain pointer to the **ShellExecuteEx** function to support item activation with services from that site. See [Launching Applications (ShellExecute, ShellExecuteEx, SHELLEXECUTEINFO)](https://learn.microsoft.com/windows/desktop/shell/launch) for more information.

> [!NOTE]
> The shellapi.h header defines ShellExecuteEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[IShellExecuteHook](https://learn.microsoft.com/windows/desktop/shell/how-to-register-and-implement-a-property-sheet-handler-for-a-control-panel-application)

[Launching Applications (ShellExecute, ShellExecuteEx, SHELLEXECUTEINFO)](https://learn.microsoft.com/windows/desktop/shell/launch)

[ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea)