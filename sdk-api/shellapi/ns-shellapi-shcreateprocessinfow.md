# SHCREATEPROCESSINFOW structure

## Description

[[SHCreateProcessAsUserW](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shcreateprocessasuserw) is no longer implemented in Windows XP or later versions.]

Contains the information needed by [SHCreateProcessAsUserW](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shcreateprocessasuserw) to create a process.

## Members

### `cbSize`

Type: **DWORD**

The size, in bytes, of this structure.

### `fMask`

Type: **ULONG**

An array of flags that indicates the content and validity of the other structure members. This can be a combination of the following values.

#### SEE_MASK_CLASSKEY

Use the file's class registry key.

#### SEE_MASK_CLASSNAME

Use the file's class name.

#### SEE_MASK_CONNECTNETDRV

Validate the share and connect to a drive letter. The **pszFile** member is a UNC path of a file on a network.

#### SEE_MASK_DOENVSUBST

Expand any environment variables.

#### SEE_MASK_FLAG_DDEWAIT

Wait for the DDE conversation to terminate before returning.

#### SEE_MASK_FLAG_NO_UI

Do not display an error message box if an error occurs.

#### SEE_MASK_HMONITOR

Use this flag when specifying a monitor on multimonitor systems.

#### SEE_MASK_NOCLOSEPROCESS

The application will close the process. If the **lpProcessInformation** member is a valid [PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) pointer, and **SEE_MASK_NOCLOSEPROCESS** is set, the process will remain open when [SHCreateProcessAsUserW](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shcreateprocessasuserw) returns. The **hProcess** and **hThread** members of the **PROCESS_INFORMATION** structure hold the process and thread handles, respectively. This flag is typically set to allow an application to find out when a process created with **SHCreateProcessAsUserW** terminates. In some cases, such as when execution is satisfied through a DDE conversation, no handle will be returned. The calling application is responsible for closing the handle when it is no longer needed. If this flag is not set, the process will be closed before **SHCreateProcessAsUserW** returns, even if **lpProcessInformation** is a valid pointer.

#### SEE_MASK_NO_CONSOLE

Create a console for the new process instead of having it inherit the parent's console. It is equivalent to using a CREATE_NEW_CONSOLE flag with [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

#### SEE_MASK_UNICODE

Indicates a Unicode application.

### `hwnd`

Type: **HWND**

A parent window handle.

### `pszFile`

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string that specifies the executable file on which [SHCreateProcessAsUserW](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shcreateprocessasuserw) will perform the action specified by the **runas** verb. The **runas** verb must be supported by the file's class.

**Note** If the path is not included with the file name, the current directory is assumed.

### `pszParameters`

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string containing the application parameters. The parameters must be separated by spaces.

### `pszCurrentDirectory`

Type: **LPCWSTR**

A null-terminated Unicode string that contains the current directory.

### `hUserToken`

Type: **HANDLE**

An [Access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) that can be used to represent a particular user. It is needed when there are multiple users for those folders that are treated as belonging to a single user. The calling application must have appropriate security privileges for the particular user, including TOKEN_QUERY and TOKEN_IMPERSONATE, and the user's registry hive must be currently mounted. For further discussion of access control issues, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control).

### `lpProcessAttributes`

Type: **LPSECURITY_ATTRIBUTES**

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure with the security descriptor for the new process. It also specifies whether a child process can be inherited. If this parameter is set to **NULL**, the process will have a default security descriptor and the handle cannot be inherited.

**Security Warning:** Using a security descriptor incorrectly can compromise the security of your application. For more information, see [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes).

### `lpThreadAttributes`

Type: **LPSECURITY_ATTRIBUTES**

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure with the security descriptor for the new thread. It also specifies whether a child process can be inherited. If this parameter is set to **NULL**, the process will have a default security descriptor and the handle cannot be inherited.

**Security Warning:** Using a security descriptor incorrectly can compromise the security of your application. For more information, see [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes).

### `bInheritHandles`

Type: **BOOL**

An indicator for whether the new process inherits handles from the calling process. If set to **TRUE**, each inheritable open handle in the calling process is inherited by the new process. Inherited handles have the same value and access privileges as the original handles.

### `dwCreationFlags`

Type: **DWORD**

Flags that control the creation of the process and the priority class. For a list of the available flags, see [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera).

### `lpStartupInfo`

Type: **LPSTARTUPINFOW**

A pointer to a [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure that specifies how the main window for the new process should appear.

### `lpProcessInformation`

Type: **LPPROCESS_INFORMATION**

A pointer to a [PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure that receives information about the new process. Set this member to a valid structure pointer, and set the SEE_MASK_NOCLOSEPROCESS flag in the **fMask** member, and the process will remain open when the function returns. The **PROCESS_INFORMATION** structure's **hProcess** and **hThread** members will then hold the process and thread handles, respectively. Set this member to **NULL**, and the process will be closed before the function returns.

## Remarks

 To include double quotation marks in **pszParameters**, you must enclose each mark in a pair of quotation marks, as in the following example:

```
sei.lpParameters = "An example: \"\"\"quoted text\"\"\"";
```

In this case, the application receives three parameters: *An, example:, and "quoted text"*.

## See also

[SHELLEXECUTEINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shellexecuteinfoa)