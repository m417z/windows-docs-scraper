# ORQueryInfoKey function

Retrieves information about the specified registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*lpClass* \[out, optional\]

A pointer to a buffer that receives the key class. This parameter can be **NULL**.

*lpcClass* \[in, out, optional\]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpClass* parameter, in characters.

The size should include the terminating null character. When the function returns, this variable contains the size of the class string that is stored in the buffer. The count returned does not include the terminating null character. If the buffer is not big enough, the function returns ERROR\_MORE\_DATA, and the variable contains the size of the string, in characters, without counting the terminating null character.

If *lpClass* is **NULL**, *lpcClass* can be **NULL**.

If the *lpClass* parameter is a valid address, but the *lpcClass* parameter is not (for example, if the *lpcClass* parameter is **NULL**) then the function returns ERROR\_INVALID\_PARAMETER.

*lpcSubKeys* \[out, optional\]

A pointer to a variable that receives the number of subkeys that are contained by the specified key. This parameter can be **NULL**.

*lpcMaxSubKeyLen* \[out, optional\]

A pointer to a variable that receives the size of the key's subkey with the longest name, in Unicode characters, not including the terminating null character. This parameter can be **NULL**.

*lpcMaxClassLen* \[out, optional\]

A pointer to a variable that receives the size of the longest string that specifies a subkey class, in Unicode characters. The count returned does not include the terminating null character. This parameter can be **NULL**.

*lpcValues* \[out, optional\]

A pointer to a variable that receives the number of values that are associated with the key. This parameter can be **NULL**.

*lpcMaxValueNameLen* \[out, optional\]

A pointer to a variable that receives the size of the key's longest value name, in Unicode characters. The size does not include the terminating null character. This parameter can be **NULL**.

*lpcMaxValueLen* \[out, optional\]

A pointer to a variable that receives the size of the longest data component among the key's values, in bytes. This parameter can be **NULL**.

*lpcbSecurityDescriptor* \[out, optional\]

A pointer to a variable that receives the size of the key's security descriptor, in bytes. This parameter can be **NULL**.

*lpftLastWriteTime* \[out, optional\]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that receives the last write time. This parameter can be **NULL**.

The function sets the members of the [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure to indicate the last time that the key or any of its value entries is modified.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

If the *lpClass* buffer is too small to receive the name of the class, the function returns ERROR\_MORE\_DATA.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime)

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

[**ORDeleteKey**](https://learn.microsoft.com/windows/win32/devnotes/ordeletekey)

