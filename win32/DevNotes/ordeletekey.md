# ORDeleteKey function

Deletes a subkey and its values from an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive. This handle is returned by the [**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey) or [**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey) function.

*lpSubKey* \[in, optional\]

The name of the key to be deleted. It must be a subkey of the key that *Handle* identifies, but it cannot have subkeys.

If the subkey does not exist, the function returns ERROR\_NOT\_FOUND.

If this parameter is **NULL**, the function deletes the key specified by the *Handle* parameter. If the key specified by the *Handle* parameter is the root key of the hive, the function returns ERROR\_INVALID\_PARAMETER.

Key names are not case sensitive.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error. Possible error codes include the following:

- If the specified subkey does not exist, the function returns ERROR\_FILE\_NOT\_FOUND.
- If the specified subkey is the root key of the registry hive, the function returns ERROR\_INVALID\_PARAMETER.
- If the specified subkey has subkeys, the function returns ERROR\_KEY\_HAS\_CHILDREN.

## Remarks

If the specified registry key exists, it is marked as deleted. A deleted key is not removed until the last handle to it is closed.

The key to be deleted must not have subkeys. To delete a key and all its subkeys, use the [**OREnumKey**](https://learn.microsoft.com/windows/win32/devnotes/orenumkey) function to enumerate the subkeys and delete them individually.

Only the [**ORCloseKey**](https://learn.microsoft.com/windows/win32/devnotes/orclosekey) function may be called on a deleted key; all other offline registry operations fail. If the deleted key was explicitly created by calling [**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey), resources associated with the key are released when the last handle to the deleted key is closed.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCloseKey**](https://learn.microsoft.com/windows/win32/devnotes/orclosekey)

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**OREnumKey**](https://learn.microsoft.com/windows/win32/devnotes/orenumkey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

