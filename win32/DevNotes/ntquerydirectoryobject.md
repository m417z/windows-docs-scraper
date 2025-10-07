# NtQueryDirectoryObject function

\[This function may be altered or unavailable in the future.\]

Retrieves information about the specified directory object.

## Parameters

*DirectoryHandle* \[in\]

A handle to the directory object.

*Buffer* \[out, optional\]

A pointer to a buffer that receives the directory information. This buffer receives one or more **OBJECT\_DIRECTORY\_INFORMATION** structures, the last one being **NULL**, followed by strings that contain the names of the directory entries. For more information, see Remarks.

*Length* \[in\]

The size of the user-supplied output buffer, in bytes.

*ReturnSingleEntry* \[in\]

Indicates whether the function should return only a single entry.

*RestartScan* \[in\]

Indicates whether to restart the scan or continue the enumeration using the information passed in the *Context* parameter.

*Context* \[in, out\]

The enumeration context.

*ReturnLength* \[out, optional\]

A pointer to a variable that receives the length of the directory information returned in the output buffer, in bytes.

## Return value

The function returns **STATUS\_SUCCESS** or an error status.

## Remarks

The following is the definition of the **OBJECT\_DIRECTORY\_INFORMATION** structure.

``` syntax
typedef struct _OBJECT_DIRECTORY_INFORMATION {
    UNICODE_STRING Name;
    UNICODE_STRING TypeName;
} OBJECT_DIRECTORY_INFORMATION, *POBJECT_DIRECTORY_INFORMATION;
```

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

## See also

[**NtOpenDirectoryObject**](https://learn.microsoft.com/windows/win32/devnotes/ntopendirectoryobject)

