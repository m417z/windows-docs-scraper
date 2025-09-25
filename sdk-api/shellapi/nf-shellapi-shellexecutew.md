# ShellExecuteW function

## Description

Performs an operation on a specified file.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the parent window used for displaying a UI or error messages. This value can be **NULL** if the operation is not associated with a window.

### `lpOperation` [in, optional]

Type: **LPCTSTR**

A pointer to a **null**-terminated string, referred to in this case as a *verb*, that specifies the action to be performed. The set of available verbs depends on the particular file or folder. Generally, the actions available from an object's shortcut menu are available verbs. The following verbs are commonly used:

#### :::no-loc text="edit":::

Launches an editor and opens the document for editing. If *lpFile* is not a document file, the function will fail.

#### :::no-loc text="explore":::

Explores a folder specified by *lpFile*.

#### :::no-loc text="find":::

Initiates a search beginning in the directory specified by *lpDirectory*.

#### :::no-loc text="open":::

Opens the item specified by the *lpFile* parameter. The item can be a file or folder.

#### :::no-loc text="print":::

Prints the file specified by *lpFile*. If *lpFile* is not a document file, the function fails.

#### runas

Launches an application as Administrator. User Account Control (UAC) will prompt the user for consent to run the application elevated or enter the credentials of an administrator account used to run the application.

#### NULL

The default verb is used, if available. If not, the ":::no-loc text="open":::" verb is used. If neither verb is available, the system uses the first verb listed in the registry.

### `lpFile` [in]

Type: **LPCTSTR**

A pointer to a **null**-terminated string that specifies the file or object on which to execute the specified verb. To specify a Shell namespace object, pass the fully qualified parse name. Note that not all verbs are supported on all objects. For example, not all document types support the ":::no-loc text="print":::" verb. If a relative path is used for the *lpDirectory* parameter do not use a relative path for *lpFile*.

If *lpFile* specifies an executable file and ":::no-loc text="open":::" or "runas" verbs are used in *lpOperation*, the command line string of the launched process includes a trailing whitespace character.

### `lpParameters` [in, optional]

Type: **LPCTSTR**

If *lpFile* specifies an executable file, this parameter is a pointer to a **null**-terminated string that specifies the parameters to be passed to the application. The command line string for a process launched with ":::no-loc text="open":::" or "runas" verbs in *lpOperation* includes a trailing whitespace character and the parameters are appended to that command line string. The format of this string is determined by the verb that is to be invoked. If *lpFile* specifies a document file, *lpParameters* should be **NULL**.

### `lpDirectory` [in, optional]

Type: **LPCTSTR**

A pointer to a **null**-terminated string that specifies the default (working) directory for the action. If this value is **NULL**, the current working directory is used. If a relative path is provided at *lpFile*, do not use a relative path for *lpDirectory*.

### `nShowCmd` [in]

Type: **INT**

The flags that specify how an application is to be displayed when it is opened. If *lpFile* specifies a document file, the flag is simply passed to the associated application. It is up to the application to decide how to handle it. It can be any of the values that can be specified in the *nCmdShow* parameter for the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function.

## Return value

Type: **HINSTANCE**

If the function succeeds, it returns a value greater than 32. If the function fails, it returns an error value that indicates the cause of the failure. The return value is cast as an HINSTANCE for backward compatibility with 16-bit Windows applications. It is not a true HINSTANCE, however. It can be cast only to an **INT_PTR** and compared to either 32 or the following error codes below.

| Return code | Description |
| --- | --- |
| **0** | The operating system is out of memory or resources. |
| **ERROR_FILE_NOT_FOUND** | The specified file was not found. |
| **ERROR_PATH_NOT_FOUND** | The specified path was not found. |
| **ERROR_BAD_FORMAT** | The .exe file is invalid (non-Win32 .exe or error in .exe image). |
| **SE_ERR_ACCESSDENIED** | The operating system denied access to the specified file. |
| **SE_ERR_ASSOCINCOMPLETE** | The file name association is incomplete or invalid. |
| **SE_ERR_DDEBUSY** | The DDE transaction could not be completed because other DDE transactions were being processed. |
| **SE_ERR_DDEFAIL** | The DDE transaction failed. |
| **SE_ERR_DDETIMEOUT** | The DDE transaction could not be completed because the request timed out. |
| **SE_ERR_DLLNOTFOUND** | The specified DLL was not found. |
| **SE_ERR_FNF** | The specified file was not found. |
| **SE_ERR_NOASSOC** | There is no application associated with the given file name extension. This error will also be returned if you attempt to print a file that is not printable. |
| **SE_ERR_OOM** | There was not enough memory to complete the operation. |
| **SE_ERR_PNF** | The specified path was not found. |
| **SE_ERR_SHARE** | A sharing violation occurred. |

Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

Because **ShellExecute** can delegate execution to Shell extensions (data sources, context menu handlers, verb implementations) that are activated using Component Object Model (COM), COM should be initialized before **ShellExecute** is called. Some Shell extensions require the COM single-threaded apartment (STA) type. In that case, COM should be initialized as shown here:

```
CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE)
```

There are certainly instances where **ShellExecute** does not use one of these types of Shell extension and those instances would not require COM to be initialized at all. Nonetheless, it is good practice to *always* initialize COM before using this function.

This method allows you to execute any commands in a folder's shortcut menu or stored in the registry.

To open a folder, use either of the following calls:

```
ShellExecute(handle, NULL, <fully_qualified_path_to_folder>, NULL, NULL, SW_SHOWNORMAL);
```

or

```
ShellExecute(handle, "open", <fully_qualified_path_to_folder>, NULL, NULL, SW_SHOWNORMAL);
```

To explore a folder, use the following call:

```
ShellExecute(handle, "explore", <fully_qualified_path_to_folder>, NULL, NULL, SW_SHOWNORMAL);
```

To launch the Shell's Find utility for a directory, use the following call.

```
ShellExecute(handle, "find", <fully_qualified_path_to_folder>, NULL, NULL, 0);
```

If *lpOperation* is **NULL**, the function opens the file specified by *lpFile*. If *lpOperation* is ":::no-loc text="open":::" or ":::no-loc text=""::::::no-loc text="explore":::", the function attempts to open or explore the folder.

To obtain information about the application that is launched as a result of calling **ShellExecute**, use [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa).

**Note** The **Launch folder windows in a separate process** setting in Folder Options affects **ShellExecute**. If that option is disabled (the default setting), **ShellExecute** uses an open Explorer window rather than launch a new one. If no Explorer window is open, **ShellExecute** launches a new one.

> [!NOTE]
> The shellapi.h header defines ShellExecute as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[CreateProcessW](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw)

[IShellExecuteHook](https://learn.microsoft.com/windows/desktop/shell/how-to-register-and-implement-a-property-sheet-handler-for-a-control-panel-application)

[Launching Applications (ShellExecute, ShellExecuteEx, SHELLEXECUTEINFO)](https://learn.microsoft.com/windows/desktop/shell/launch)

[ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa)