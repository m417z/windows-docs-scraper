# RegEnumValueA function

## Description

Enumerates the values for the specified open registry key. The function copies one indexed value name and data block for the key each time it is called.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_QUERY_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_PERFORMANCE_DATA**

**HKEY_USERS**

### `dwIndex` [in]

The index of the value to be retrieved. This parameter should be zero for the first call to the
**RegEnumValue** function and then be incremented for subsequent calls.

Because values are not ordered, any new value will have an arbitrary index. This means that the function may return values in any order.

### `lpValueName` [out]

A pointer to a buffer that receives the name of the value as a **null**-terminated string.

This buffer must be large enough to include the terminating **null** character.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `lpcchValueName` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpValueName* parameter, in characters. When the function returns, the variable receives the number of characters stored in the buffer, not including the terminating **null** character.

If the buffer specified by *lpValueName* is not large enough to hold the data, the function returns ERROR_MORE_DATA and the buffer size in the variable pointed to by *lpValueName* is not changed. In this case, the contents of *lpcchValueName* are undefined.

Registry value names are limited to 32,767 bytes. The ANSI version of this function treats this parameter as a **SHORT** value. Therefore, if you specify a value greater than 32,767 bytes, there is an overflow and the function may return ERROR_MORE_DATA.

### `lpReserved`

This parameter is reserved and must be **NULL**.

### `lpType` [out, optional]

A pointer to a variable that receives a code indicating the type of data stored in the specified value. For a list of the possible type codes, see
[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types). The *lpType* parameter can be **NULL** if the type code is not required.

### `lpData` [out, optional]

A pointer to a buffer that receives the data for the value entry. This parameter can be **NULL** if the data is not required.

If *lpData* is **NULL** and *lpcbData* is non-**NULL**, the function stores the size of the data, in bytes, in the variable pointed to by *lpcbData*. This enables an application to determine the best way to allocate a buffer for the data.

### `lpcbData` [in, out, optional]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpData* parameter, in bytes. When the function returns, the variable receives the number of bytes stored in the buffer.

This parameter can be **NULL** only if *lpData* is **NULL**.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, this size includes any terminating **null** character or characters. For more information, see Remarks.

If the buffer specified by *lpData* is not large enough to hold the data, the function returns ERROR_MORE_DATA and stores the required buffer size in the variable pointed to by *lpcbData*. In this case, the contents of *lpData* are undefined.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). If there are no more values available, the function returns ERROR_NO_MORE_ITEMS.

If the buffer specified by *lpValueName* or *lpData* is too small to receive the value, the function returns ERROR_MORE_DATA.

## Remarks

To enumerate values, an application should initially call the
**RegEnumValue** function with the *dwIndex* parameter set to zero. The application should then increment *dwIndex* and call the
**RegEnumValue** function until there are no more values (until the function returns ERROR_NO_MORE_ITEMS).

The application can also set *dwIndex* to the index of the last value on the first call to the function and decrement the index until the value with index 0 is enumerated. To retrieve the index of the last value, use the
[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya) function.

While using
**RegEnumValue**, an application should not call any registry functions that might change the key being queried.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, the string may not have been stored with the proper **null**-terminating characters. Therefore, even if the function returns ERROR_SUCCESS, the application should ensure that the string is properly terminated before using it; otherwise, it may overwrite a buffer. (Note that REG_MULTI_SZ strings should have two **null**-terminating characters.)

To determine the maximum size of the name and data buffers, use the
[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya) function.

> [!NOTE]
> On legacy versions of Windows, this API is also exposed by kernel32.dll.

#### Examples

For an example, see
[Enumerating Registry Subkeys](https://learn.microsoft.com/windows/desktop/SysInfo/enumerating-registry-subkeys).

> [!NOTE]
> The winreg.h header defines RegEnumValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)