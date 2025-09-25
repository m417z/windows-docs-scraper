# SHELLEXECUTEINFOW structure

## Description

Contains information used by [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa).

## Members

### `cbSize`

Type: **DWORD**

Required. The size of this structure, in bytes.

### `fMask`

Type: **ULONG**

A combination of one or more of the following values that indicate the content and validity of the other structure members:

| SEE_MASK_DEFAULT (0x00000000) | Use default values. |
| SEE_MASK_CLASSNAME (0x00000001) | Use the class name given by the **lpClass** member. If both SEE_MASK_CLASSKEY and SEE_MASK_CLASSNAME are set, the class key is used. |
| SEE_MASK_CLASSKEY (0x00000003) | Use the class key given by the **hkeyClass** member. If both SEE_MASK_CLASSKEY and SEE_MASK_CLASSNAME are set, the class key is used. |
| SEE_MASK_IDLIST (0x00000004) | Use the item identifier list given by the **lpIDList** member. The **lpIDList** member must point to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. |
| SEE_MASK_INVOKEIDLIST (0x0000000C) | Use the [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) interface of the selected item's [shortcut menu handler](https://learn.microsoft.com/windows/desktop/shell/context-menu-handlers). Use either **lpFile** to identify the item by its file system path or **lpIDList** to identify the item by its PIDL. This flag allows applications to use [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) to invoke verbs from shortcut menu extensions instead of the static verbs listed in the registry.<br><br>**Note:** SEE_MASK_INVOKEIDLIST overrides and implies SEE_MASK_IDLIST. |
| SEE_MASK_ICON (0x00000010) | Use the icon given by the **hIcon** member. This flag cannot be combined with SEE_MASK_HMONITOR.<br><br>**Note:** This flag is used only in Windows XP and earlier. It is ignored as of Windows Vista. |
| SEE_MASK_HOTKEY (0x00000020) | Use the keyboard shortcut given by the **dwHotKey** member. |
| SEE_MASK_NOCLOSEPROCESS (0x00000040) | Use to indicate that the **hProcess** member receives the process handle. This handle is typically used to allow an application to find out when a process created with [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) terminates. In some cases, such as when execution is satisfied through a DDE conversation, no handle will be returned. The calling application is responsible for closing the handle when it is no longer needed. |
| SEE_MASK_CONNECTNETDRV (0x00000080) | Validate the share and connect to a drive letter. This enables reconnection of disconnected network drives. The **lpFile** member is a UNC path of a file on a network. |
| SEE_MASK_NOASYNC (0x00000100) | Only respected when launching files, does not apply to uris or shell namespace items (e.g. "This PC"). Wait for the async part of the execute operation, (e.g. DDE) to complete before returning. When this applies it ensures the launching operation finishes before returning. Applications that exit immediately after calling **ShellExecuteEx** should specify this flag. Note, **ShellExecuteEx** moves its work to a background thread if the caller's threading model is not Apartment. Forcing the call to be synchronous disables that behavior and uses the callers COM apartment. Specifing SEE_MASK_FLAG_HINST_IS_SITE forces synchronous behavior always.<br><br>If the execute operation is performed on a background thread and the caller did not specify the SEE_MASK_ASYNCOK flag, then the calling thread waits until the new process has started before returning. This typically means that either [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) has been called, the DDE communication has completed, or that the custom execution delegate has notified [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) that it is done. If the SEE_MASK_WAITFORINPUTIDLE flag is specified, then **ShellExecuteEx** calls [WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle) and waits for the new process to idle before returning, with a maximum timeout of 1 minute.<br><br>For further discussion on when this flag is necessary, see the Remarks section. |
| SEE_MASK_FLAG_DDEWAIT (0x00000100) | The same as SEE_MASK_NOASYNC, use of that option is preferred. |
| SEE_MASK_DOENVSUBST (0x00000200) | Expand any environment variables specified in the string given by the **lpDirectory** or **lpFile** member. |
| SEE_MASK_FLAG_NO_UI (0x00000400) | Do not display user interface (UI) error dialogs that would normally be presented without this option. Security prompts are exempted and will still be shown. |
| SEE_MASK_UNICODE (0x00004000) | Use this flag to indicate a Unicode application. |
| SEE_MASK_NO_CONSOLE (0x00008000) | Use to inherit the parent's console for the new process instead of having it create a new console. It is the opposite of using a CREATE_NEW_CONSOLE flag with [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa). |
| SEE_MASK_ASYNCOK (0x00100000) | The execution can be performed on a background thread and the call should return immediately without waiting for the background thread to finish. Note that in certain cases [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) ignores this flag and waits for the process to finish before returning. |
| SEE_MASK_NOQUERYCLASSSTORE (0x01000000) | Not used. |
| SEE_MASK_HMONITOR (0x00200000) | Use this flag when specifying a monitor on multi-monitor systems. The monitor is specified in the **hMonitor** member. This flag cannot be combined with SEE_MASK_ICON. |
| SEE_MASK_NOZONECHECKS (0x00800000) | Do not perform a zone check. This flag allows [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) to bypass zone checking put into place by [IAttachmentExecute](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iattachmentexecute). |
| SEE_MASK_WAITFORINPUTIDLE (0x02000000) | After the new process is created, wait for the process to become idle before returning, with a one minute timeout. See [WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle) for more details. |
| SEE_MASK_FLAG_LOG_USAGE (0x04000000) | Indicates a user initiated launch that enables tracking of frequently used programs and other behaviors. |
| SEE_MASK_FLAG_HINST_IS_SITE` (0x08000000) | The **hInstApp** member is used to specify the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of an object that implements [IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85)). This object will be used as a site pointer. The site pointer is used to provide services to the [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) function, the handler binding process, and invoked verb handlers. [ICreatingProcess](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-icreatingprocess) can be provided to allow the caller to alter some parameters of the process being created.<br><br>This flag is supported in Windows 8 and later.<br><br>When this option is specified the call runs synchronously on the calling thread. |

### `hwnd`

Type: **HWND**

Optional. A handle to the owner window, used to display and position any UI that the system might produce while executing this function.

### `lpVerb`

Type: **LPCTSTR**

A string, referred to as a *verb*, that specifies the action to be performed. The set of available verbs depends on the particular file or folder. Generally, the actions available from an object's shortcut menu are available verbs. This parameter can be **NULL**, in which case the default verb is used if available. If not, the ":::no-loc text="open"::" verb is used. If neither verb is available, the system uses the first verb listed in the registry. The following verbs are commonly used:

- **:::no-loc text="edit":::**: Launches an editor and opens the document for editing. If **lpFile** is not a document file, the function will fail.
- **:::no-loc text="explore":::**: Explores the folder specified by **lpFile**.
- **:::no-loc text="find":::**: Initiates a search starting from the specified directory.
- **:::no-loc text="open":::**: Opens the file specified by the **lpFile** parameter. The file can be an executable file, a document file, or a folder.
- **:::no-loc text="openas":::**: Launches a picker UI allowing the user to select an app with which to open the file specified by the **lpFile** parameter.
- **:::no-loc text="print":::**: Prints the document file specified by **lpFile**. If **lpFile** is not a document file, the function will fail.
- **:::no-loc text="properties":::**: Displays the file or folder's properties.
- **runas**: Launches an application as Administrator. User Account Control (UAC) will prompt the user for consent to run the application elevated or enter the credentials of an administrator account used to run the application.

### `lpFile`

Type: **LPCTSTR**

The address of a null-terminated string that specifies the name of the file or object on which [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) will perform the action specified by the **lpVerb** parameter. The system registry verbs that are supported by the **ShellExecuteEx** function include ":::no-loc text="open"::" for executable files and document files and ":::no-loc text="print"::" for document files for which a print handler has been registered. Other applications might have added Shell verbs through the system registry, such as ":::no-loc text="play"::" for .avi and .wav files. To specify a Shell namespace object, pass the fully qualified parse name and set the **SEE_MASK_INVOKEIDLIST** flag in the **fMask** parameter.

**Note:** If the **SEE_MASK_INVOKEIDLIST** flag is set, you can use either **lpFile** or **lpIDList** to identify the item by its file system path or its PIDL respectively. One of the two values—**lpFile** or **lpIDList**—must be set.

**Note:** If the path is not included with the name, the current directory is assumed.

### `lpParameters`

Type: **LPCTSTR**

Optional. The address of a null-terminated string that contains the application parameters. The parameters must be separated by spaces. If the **lpFile** member specifies a document file, **lpParameters** should be **NULL**.

### `lpDirectory`

Type: **LPCTSTR**

Optional. The address of a null-terminated string that specifies the name of the working directory. If this member is **NULL**, the current directory is used as the working directory.

### `nShow`

Type: **int**

Required. Flags that specify how an application is to be shown when it is opened; one of the SW_ values listed for the [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) function. If **lpFile** specifies a document file, the flag is simply passed to the associated application. It is up to the application to decide how to handle it.

### `hInstApp`

Type: **HINSTANCE**

[out] If SEE_MASK_NOCLOSEPROCESS is set and the [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) call succeeds, it sets this member to a value greater than 32. If the function fails, it is set to an SE_ERR_XXX error value that indicates the cause of the failure. Although **hInstApp** is declared as an HINSTANCE for compatibility with 16-bit Windows applications, it is not a true HINSTANCE. It can be cast only to an **int** and compared to either 32 or the following SE_ERR_XXX error codes.

\

| Error Code | Reason |
| ---------- | ------ |
| SE_ERR_FNF (2) | File not found. |
| SE_ERR_PNF (3) | Path not found. |
| SE_ERR_ACCESSDENIED (5) | Access denied. |
| SE_ERR_OOM (8) | Out of memory. |
| SE_ERR_DLLNOTFOUND (32) | Dynamic-link library not found. |
| SE_ERR_SHARE (26) | Cannot share an open file. |
| SE_ERR_ASSOCINCOMPLETE (27) | File association information not complete. |
| SE_ERR_DDETIMEOUT (28) | DDE operation timed out. |
| SE_ERR_DDEFAIL (29) | DDE operation failed. |
| SE_ERR_DDEBUSY (30) | DDE operation is busy. |
| SE_ERR_NOASSOC (31) | File association not available. |

### `lpIDList`

Type: **LPVOID**

The address of an absolute [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure (PCIDLIST_ABSOLUTE) to contain an item identifier list that uniquely identifies the file to execute. This member is ignored if the **fMask** member does not include **SEE_MASK_IDLIST** or **SEE_MASK_INVOKEIDLIST**.

### `lpClass`

Type: **LPCTSTR**

The address of a null-terminated string that specifies one of the following:

- A ProgId. For example, "Paint.Picture".
- A URI protocol scheme. For example, "http".
- A file extension. For example, ".txt".
- A registry path under HKEY_CLASSES_ROOT that names a subkey that contains one or more Shell verbs. This key will have a subkey that conforms to the Shell verb registry schema, such as **shell**\*verb name*.

This member is ignored if **fMask** does not include **SEE_MASK_CLASSNAME**.

### `hkeyClass`

Type: **HKEY**

A handle to the registry key for the file type. The access rights for this registry key should be set to KEY_READ. This member is ignored if **fMask** does not include **SEE_MASK_CLASSKEY**.

### `dwHotKey`

Type: **DWORD**

A keyboard shortcut to associate with the application. The low-order word is the virtual key code, and the high-order word is a modifier flag (HOTKEYF_). For a list of modifier flags, see the description of the [WM_SETHOTKEY](https://learn.microsoft.com/windows/desktop/inputdev/wm-sethotkey) message. This member is ignored if **fMask** does not include **SEE_MASK_HOTKEY**.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hIcon`

Type: **HANDLE**

A handle to the icon for the file type. This member is ignored if **fMask** does not include **SEE_MASK_ICON**. This value is used only in Windows XP and earlier. It is ignored as of Windows Vista.

### `DUMMYUNIONNAME.hMonitor`

Type: **HANDLE**

A handle to the monitor upon which the document is to be displayed. This member is ignored if **fMask** does not include **SEE_MASK_HMONITOR**.

### `hProcess`

Type: **HANDLE**

A handle to the newly started application. This member is set on return and is always **NULL** unless **fMask** is set to **SEE_MASK_NOCLOSEPROCESS**. Even if **fMask** is set to **SEE_MASK_NOCLOSEPROCESS**, **hProcess** will be **NULL** if no process was launched. For example, if a document to be launched is a URL and an instance of Internet Explorer is already running, it will display the document. No new process is launched, and **hProcess** will be **NULL**.

**Note:** [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) does not always return an **hProcess**, even if a process is launched as the result of the call. For example, an **hProcess** does not return when you use **SEE_MASK_INVOKEIDLIST** to invoke [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu).

## Remarks

The **SEE_MASK_NOASYNC** flag must be specified if the thread calling [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) does not have a message loop or if the thread or process will terminate soon after **ShellExecuteEx** returns. Under such conditions, the calling thread will not be available to complete the DDE conversation, so it is important that **ShellExecuteEx** complete the conversation before returning control to the calling application. Failure to complete the conversation can result in an unsuccessful launch of the document.

If the calling thread has a message loop and will exist for some time after the call to [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) returns, the **SEE_MASK_NOASYNC** flag is optional. If the flag is omitted, the calling thread's message pump will be used to complete the DDE conversation. The calling application regains control sooner, since the DDE conversation can be completed in the background.

For calls to this API that result from user interaction specify **SEE_MASK_FLAG_LOG_USAGE**.

To include double quotation marks in **lpParameters**, enclose each mark in a pair of quotation marks, as in the following example.

``` cpp
sei.lpParameters = "An example: \"\"\"quoted text\"\"\"";
```

In this case, the application receives three parameters: *An*, *example:*, and *"quoted text"*.

> [!NOTE]
> The shellapi.h header defines SHELLEXECUTEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).