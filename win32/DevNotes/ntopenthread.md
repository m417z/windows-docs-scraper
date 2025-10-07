# NtOpenThread function

\[This function may be changed or removed from Windows without further notice. Use the [**OpenThread**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openthread) function instead.\]

Opens a handle to a thread object with the access specified.

## Parameters

*ThreadHandle* \[out\]

A pointer to a variable that receives the thread object handle.

*DesiredAccess* \[in\]

An [**ACCESS\_MASK**](https://learn.microsoft.com/windows/win32/secauthz/access-mask-format) data type that provides the desired types of access for the thread object.

*ObjectAttributes* \[in\]

A pointer to an [OBJECT\_ATTRIBUTES](https://msdn.microsoft.com/library/aa491657.aspx) structure. The **ObjectName** member of this structure must be NULL.

**Windows Server 2003 and Windows XP:** The **ObjectName** member of this structure can point to an object name. If **ObjectName** is not NULL, the *ClientId* parameter must be NULL.

*ClientId* \[in\]

A pointer to a **CLIENT\_ID** structure that identifies the thread whose thread is to be opened.

**Windows Server 2003 and Windows XP:** A pointer to a **CLIENT\_ID** structure that identifies the thread whose thread is to be opened. This parameter can be NULL. If this parameter is not NULL, the **ObjectName** member of the structure pointed to by the *ObjectAttributes* parameter must be NULL.

## Return value

Returns an **NTSTATUS** or error code.

The forms and significance of **NTSTATUS** error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Remarks

This function has no associated header file. The associated import library, Ntdll.lib is available in the WDK. You can also use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

