# SdbMakeIndexKeyFromString function

Creates a key from a string.

## Parameters

*pwszKey* \[in\]

The string.

## Return value

The function returns the key or 0 if there is an error.

## Remarks

The standard index key is the first eight characters of the string, converted to upper case, then cast to a **ULONGLONG** value.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

