# NtOpenDirectoryObject function

\[This function may be altered or unavailable in the future.\]

Opens an existing directory object.

## Parameters

*DirectoryHandle* \[out\]

A handle to the newly opened directory object.

*DesiredAccess* \[in\]

An [**ACCESS\_MASK**](https://learn.microsoft.com/windows/win32/secauthz/access-mask) that specifies the requested access to the directory object. This parameter can be one or more of the following values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| **DIRECTORY\_QUERY**<br>0x0001 | Query access to the directory object.<br> |
| **DIRECTORY\_TRAVERSE**<br>0x0002 | Name-lookup access to the directory object.<br> |
| **DIRECTORY\_CREATE\_OBJECT**<br>0x0004 | Name-creation access to the directory object.<br> |
| **DIRECTORY\_CREATE\_SUBDIRECTORY**<br>0x0008 | Subdirectory-creation access to the directory object.<br> |
| **DIRECTORY\_ALL\_ACCESS**<br>STANDARD\_RIGHTS\_REQUIRED \| 0xF | All of the preceding rights plus **STANDARD\_RIGHTS\_REQUIRED**.<br> |

*ObjectAttributes* \[in\]

The attributes for the directory object. To initialize the **OBJECT\_ATTRIBUTES** structure, use the **InitializeObjectAttributes** macro. For more information, see the documentation for these items in the documentation for the WDK.

## Return value

The function returns STATUS\_SUCCESS or an error status. The possible status codes include the following.

| Return code | Description |
|-------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **STATUS\_INSUFFICIENT\_RESOURCES** | A temporary buffer required by this function could not be allocated.<br> |
| **STATUS\_INVALID\_PARAMETER** | The specified ObjectAttributes parameter was a **NULL** pointer, not a valid pointer to an **OBJECT\_ATTRIBUTES** structure, or some of the members specified in the **OBJECT\_ATTRIBUTES** structure were not valid.<br> |
| **STATUS\_OBJECT\_NAME\_INVALID** | The *ObjectAttributes* parameter contained an **ObjectName** member in the **OBJECT\_ATTRIBUTES** structure that was not valid because an empty string was found after the **OBJECT\_NAME\_PATH\_SEPARATOR** character.<br> |
| **STATUS\_OBJECT\_NAME\_NOT\_FOUND** | The *ObjectAttributes* parameter contained an **ObjectName** member in the **OBJECT\_ATTRIBUTES** structure that could not be found.<br> |
| **STATUS\_OBJECT\_PATH\_NOT\_FOUND** | The *ObjectAttributes* parameter contained an **ObjectName** member in the **OBJECT\_ATTRIBUTES** structure with an object path that could not be found. <br> |
| **STATUS\_OBJECT\_PATH\_SYNTAX\_BAD** | The *ObjectAttributes* parameter did not contain a **RootDirectory** member, but the **ObjectName** member in the **OBJECT\_ATTRIBUTES** structure was an empty string or did not contain an **OBJECT\_NAME\_PATH\_SEPARATOR** character. This indicates incorrect syntax for the object path.<br> |

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

## See also

[**NtQueryDirectoryObject**](https://learn.microsoft.com/windows/win32/devnotes/ntquerydirectoryobject)

