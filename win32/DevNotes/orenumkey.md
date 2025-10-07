# OREnumKey function

Enumerates the subkeys of the specified open registry key in an offline registry hive. The function retrieves information about one subkey each time it is called.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*dwIndex* \[in\]

The index of the subkey to retrieve. This parameter should be zero for the first call to the function and then incremented for subsequent calls.

Because subkeys are not ordered, any new subkey will have an arbitrary index. This means that the function may return subkeys in any order.

*lpName* \[out\]

A pointer to a buffer that receives the name of the subkey, including the terminating null character. The function copies only the name of the subkey, not the full key hierarchy, to the buffer. If the function fails, no information is copied to this buffer.

For more information, see [Registry Element Size Limits](https://learn.microsoft.com/windows/win32/sysinfo/registry-element-size-limits).

*lpcName* \[in, out\]

A pointer to a variable that specifies the size of the buffer specified by the *lpName* parameter, in **WCHARs**. This size should include the terminating null character. If the function succeeds, the variable pointed to by *lpcName* contains the number of characters stored in the buffer, not including the terminating null character.

*lpClass* \[out, optional\]

A pointer to a buffer that receives the null-terminated class string of the enumerated subkey. This parameter can be **NULL**.

*lpcClass* \[in, out, optional\]

A pointer to a variable that specifies the size of the buffer specified by the *lpClass* parameter, in **WCHARs**. The size should include the terminating null character. If the function succeeds, *lpcClass* contains the number of characters stored in the buffer, not including the terminating null character. This parameter can be **NULL** only if *lpClass* is **NULL**.

*lpftLastWriteTime* \[out, optional\]

A pointer to [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that receives the time at which the enumerated subkey was last written. This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error. Possible error codes include the following:

- If the *lpName* buffer is too small to receive the name of the key, the function returns ERROR\_MORE\_DATA.
- If there are no more subkeys available, the function returns ERROR\_NO\_MORE\_ITEMS.

## Remarks

To enumerate subkeys, an application should initially call the **OREnumKey** function with the *dwIndex* parameter set to zero. The application should then increment the *dwIndex* parameter and call **OREnumKey** until there are no more subkeys (meaning the function returns ERROR\_NO\_MORE\_ITEMS).

The application can also set *dwIndex* to the index of the last subkey on the first call to the function and decrement the index until the subkey with the index 0 is enumerated. To retrieve the index of the last subkey, use the [**ORQueryInfoKey**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regqueryinfokeya) function.

While an application is using the **OREnumKey** function, it should not make calls to any offline registry functions that might change the key being enumerated.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**ORDeleteKey**](https://learn.microsoft.com/windows/win32/devnotes/ordeletekey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

[**ORQueryInfoKey**](https://learn.microsoft.com/windows/win32/devnotes/orqueryinfokey)

