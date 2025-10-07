# SdbGetFileAttributes function

Retrieves the attribute data for the specified file.

## Parameters

*lpwszFileName* \[in\]

The path to the file.

*ppAttrInfo* \[out\]

An array of [**ATTRINFO**](https://learn.microsoft.com/windows/win32/devnotes/attrinfo) structures that contain the attribute data.

*lpdwAttrCount* \[out\]

The number of attributes.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Remarks

When you have finished with the data, free it using the [**SdbFreeFileAttributes**](https://learn.microsoft.com/windows/win32/devnotes/sdbfreefileattributes) function.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbFormatAttribute**](https://learn.microsoft.com/windows/win32/devnotes/sdbformatattribute)

[**SdbFreeFileAttributes**](https://learn.microsoft.com/windows/win32/devnotes/sdbfreefileattributes)

