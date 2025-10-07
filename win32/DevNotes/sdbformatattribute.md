# SdbFormatAttribute function

Converts the specified attribute data to XML format.

## Parameters

*pAttrInfo* \[in\]

An [**ATTRINFO**](https://learn.microsoft.com/windows/win32/devnotes/attrinfo) structure.

*pchBuffer* \[out\]

The output buffer.

*dwBufferSize* \[in\]

The size of the *pchBuffer* buffer, in characters.

## Return value

The function returns **TRUE** on success or **FALSE** if the buffer is too small or the attribute is not found.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetFileAttributes**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetfileattributes)

