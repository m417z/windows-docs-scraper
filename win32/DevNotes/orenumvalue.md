# OREnumValue function

Enumerates the values for the specified open registry key in an offline registry hive. The function retrieves information for one value under the specified key each time the function is called.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*dwIndex* \[in\]

The index of the value to be retrieved. This parameter should be zero for the first call to the function and then be incremented for subsequent calls.

Because values are not ordered, any new value will have an arbitrary index. This means that the function may return values in any order.

*lpValueName* \[out\]

A pointer to a buffer that receives the name of the value as a null-terminated string. This buffer must be large enough to include the terminating null character.

For more information, see [Registry Element Size Limits](https://learn.microsoft.com/windows/win32/sysinfo/registry-element-size-limits).

*lpcValueName* \[in, out\]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpValueName* parameter, in characters. When the function returns, the variable receives the number of characters stored in the buffer, not including the terminating null character.

*lpType* \[out, optional\]

A pointer to a variable that receives a code indicating the type of data stored in the specified value. For a list of the possible type codes, see [Registry Value Types](https://learn.microsoft.com/windows/win32/sysinfo/registry-value-types). The *lpType* parameter can be **NULL** if the type code is not required.

*lpData* \[out, optional\]

A pointer to a buffer that receives the data for the value entry. This parameter can be **NULL** if the data is not required.

If *lpData* is **NULL** and *lpcbData* is non-**NULL**, the function stores the size of the data, in bytes, in the variable pointed to by *lpcbData*. This enables an application to determine the best way to allocate a buffer for the data.

*lpcbData* \[in, out, optional\]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpData* parameter, in bytes. When the function returns, the variable receives the number of bytes stored in the buffer.

This parameter can be **NULL** only if *lpData* is **NULL**.

If the data has the REG\_SZ, REG\_MULTI\_SZ or REG\_EXPAND\_SZ type, this size includes any terminating null character or characters. For more information, see Remarks.

If the buffer specified by *lpData* is not large enough to hold the data, the function returns ERROR\_MORE\_DATA and stores the required buffer size in the variable pointed to by *lpcbData*. In this case, the contents of *lpData* are undefined.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

If the *lpData* buffer is too small to receive the value, the function returns ERROR\_MORE\_DATA.

## Remarks

To enumerate values, an application should initially call the **OREnumValue** function with the *dwIndex* parameter set to zero. The application should then increment *dwIndex* and call the **OREnumValue** function until there are no more values (until the function returns ERROR\_NO\_MORE\_ITEMS).

The application can also set *dwIndex* to the index of the last value on the first call to the function and decrement the index until the value with index 0 is enumerated. To retrieve the index of the last value, use the [**ORQueryInfoKey**](https://learn.microsoft.com/windows/win32/devnotes/orqueryinfokey) function.

While using **OREnumValue**, an application should not call any offline registry functions that might change the key being queried.

If the data has the REG\_SZ, REG\_MULTI\_SZ or REG\_EXPAND\_SZ type, the string may not have been stored with the proper null-terminating characters. Therefore, even if the function returns ERROR\_SUCCESS, the application should ensure that the string is properly terminated before using it; otherwise, it may overwrite a buffer. (Note that REG\_MULTI\_SZ strings should have two null-terminating characters.)

To determine the maximum size of the name and data buffers, use the [**ORQueryInfoKey**](https://learn.microsoft.com/windows/win32/devnotes/orqueryinfokey) function.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**OREnumKey**](https://learn.microsoft.com/windows/win32/devnotes/orenumkey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

[**ORQueryInfoKey**](https://learn.microsoft.com/windows/win32/devnotes/orqueryinfokey)

