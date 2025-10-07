# SdbWriteBinaryTagFromFile function

Writes binary data from the specified file to the specified database.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tTag* \[in\]

The TAG for the entry. This TAG must be of type **TAG\_TYPE\_BINARY**.

*pwszPath* \[in\]

The path to the file that contains the data. This parameter cannot be **NULL**.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbWriteBinaryTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbwritebinarytag)

