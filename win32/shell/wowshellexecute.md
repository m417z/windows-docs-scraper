# WOWShellExecute function

\[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.\]

Performs an operation on a specified file. **WOWShellExecute** exists only for use with the Microsoft Windows NT Virtual DOS Machine (Ntvdm.exe), which allows disk operating system (DOS) and 16-bit software to run on a Windows system, and should not be used by anyone else. Use [**ShellExecute**](https://learn.microsoft.com/windows/desktop/api/Shellapi/nf-shellapi-shellexecutea) instead.

## Parameters

*hwnd* \[in\]

Type: **HWND**

A handle to the owner window used for displaying a UI or error messages. This value can be **NULL** if the operation is not associated with a window.

*lpOperation* \[in\]

Type: **LPCTSTR**

A pointer to a **null**-terminated string, referred to in this case as a *verb*, that specifies the action to be performed. The set of available verbs depends on the particular file or folder. Generally, the actions available from an object's shortcut menu are available verbs. For more information about verbs and their availability, see the *Object Verbs* section of [Launching Applications](https://learn.microsoft.com/windows/win32/shell/launch). See [Extending Shortcut Menus](https://learn.microsoft.com/windows/win32/shell/context) for further discussion of shortcut menus. The following verbs are commonly used.

**edit**

Launches an editor and opens the document for editing. If *lpFile* is not a document file, the function will fail.

**explore**

Explores the folder specified by *lpFile*.

**find**

Initiates a search starting from the specified directory.

**open**

Opens the file specified by the *lpFile* parameter. The file can be an executable file, a document file, or a folder.

**print**

Prints the document file specified by *lpFile*. If *lpFile* is not a document file, the function will fail.

**NULL**

For systems prior to Windows 2000, the default verb is used if it is valid and available in the registry. If not, the "open" verb is used.

For Windows 2000 and later systems, the default verb is used if available. If not, the "open" verb is used. If neither verb is available, the system uses the first verb listed in the registry.

*lpFile* \[in\]

Type: **LPCTSTR**

A pointer to a **null**-terminated string that specifies the file or object on which to execute the specified verb. To specify a Shell namespace object, pass the fully qualified parse name. Note that not all verbs are supported on all objects. For example, not all document types support the "print" verb.

*lpParameters* \[in\]

Type: **LPCTSTR**

If the *lpFile* parameter specifies an executable file, *lpParameters* is a pointer to a **null**-terminated string that specifies the parameters to be passed to the application. The format of this string is determined by the verb that is to be invoked. If *lpFile* specifies a document file, *lpParameters* should be **NULL**.

*lpDirectory* \[in\]

Type: **LPCTSTR**

A pointer to a **null**-terminated string that specifies the default directory.

*nShowCmd* \[in\]

Type: **INT**

The flags that specify how an application is to be displayed when it is opened. If *lpFile* specifies a document file, the flag is simply passed to the associated application. It is up to the application to decide how to handle it. It can be any of the values that can be specified in the *nCmdShow* parameter for the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function.

*lpfnCBWinExec*

Type: **void\***

Callback function used to call [**CreateProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa) in the 16-bit kernel.

## Return value

Type: **HINSTANCE**

Returns a value greater than 32 if successful, or an error value that is less than or equal to 32 otherwise. The following table lists the error values. The return value is cast as an HINSTANCE for backward compatibility with 16-bit Windows applications. It is not a true HINSTANCE, however. The only thing that can be done with the returned HINSTANCE is to cast it to an **int** and compare it with the value 32 or one of the error codes below.

| Return code | Description |
|---------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **0** | The operating system is out of memory or resources.<br> |
| **ERROR\_FILE\_NOT\_FOUND** | The specified file was not found.<br> |
| **ERROR\_PATH\_NOT\_FOUND** | The specified path was not found.<br> |
| **ERROR\_BAD\_FORMAT** | The .exe file is invalid (non-Win32 .exe or error in .exe image).<br> |
| **SE\_ERR\_ACCESSDENIED** | The operating system denied access to the specified file.<br> |
| **SE\_ERR\_ASSOCINCOMPLETE** | The file name association is incomplete or invalid.<br> |
| **SE\_ERR\_DDEBUSY** | The DDE transaction could not be completed because other DDE transactions were being processed.<br> |
| **SE\_ERR\_DDEFAIL** | The DDE transaction failed.<br> |
| **SE\_ERR\_DDETIMEOUT** | The DDE transaction could not be completed because the request timed out.<br> |
| **SE\_ERR\_DLLNOTFOUND** | The specified DLL was not found.<br> |
| **SE\_ERR\_FNF** | The specified file was not found.<br> |
| **SE\_ERR\_NOASSOC** | There is no application associated with the given file name extension. This error will also be returned if you attempt to print a file that is not printable.<br> |
| **SE\_ERR\_OOM** | There was not enough memory to complete the operation.<br> |
| **SE\_ERR\_PNF** | The specified path was not found.<br> |
| **SE\_ERR\_SHARE** | A sharing violation occurred.<br> |

## Remarks

**WOWShellExecute** is not included in a header or .lib file. It is exported from Shell32.dll by name.

This method allows you to execute any commands in a folder's shortcut menu or stored in the registry.

If *lpOperation* is **NULL**, the function opens the file specified by *lpFile*. If *lpOperation* is "open" or "explore", the function attempts to open or explore the folder.

To obtain information about the application that is launched as a result of calling **WOWShellExecute**, use [**ShellExecuteEx**](https://learn.microsoft.com/windows/desktop/api/Shellapi/nf-shellapi-shellexecuteexa).

> [!Note]
> The **Launch folder windows in a separate process** setting in Folder Options affects **WOWShellExecute**. If that option is disabled (the default setting), **WOWShellExecute** uses an open Explorer window rather than launch a new one. If no Explorer window is open, **WOWShellExecute** launches a new one.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Shell32.dll |

## See also

[**ShellExecute**](https://learn.microsoft.com/windows/desktop/api/Shellapi/nf-shellapi-shellexecutea)

