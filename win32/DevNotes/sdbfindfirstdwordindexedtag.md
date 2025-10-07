# SdbFindFirstDWORDIndexedTag function

Finds the first **DWORD** record in the specified index that meets the specified criteria.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tWhich* \[in\]

The index type. See [**TAG**](https://learn.microsoft.com/windows/win32/devnotes/tag) for a list of values.

*tKey* \[in\]

The key type.

*dwName* \[in\]

The name of the data to be found. This value will be converted into a key.

*pFindInfo* \[out\]

A [**FIND\_INFO**](https://learn.microsoft.com/windows/win32/devnotes/find-info) structure that receives the record.

## Return value

The **TAGID** of the first match or **TAG\_NULL** if no match is found.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbFindFirstTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindfirsttag)

