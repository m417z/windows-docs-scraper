# RegGetValueW function

## Description

Retrieves the type and data for the specified registry value.

## Parameters

### `hkey` [in]

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

**HKEY_PERFORMANCE_NLSTEXT**

**HKEY_PERFORMANCE_TEXT**

**HKEY_USERS**

### `lpSubKey` [in, optional]

The path of a registry key relative to the key specified by the *hkey* parameter. The registry value will be retrieved from this subkey.

The path is not case sensitive.

If this parameter is **NULL** or an empty string, "", the value will be read from the key specified by *hkey* itself.

### `lpValue` [in, optional]

The name of the registry value.

If this parameter is **NULL** or an empty string, "", the function retrieves the type and data for the key's unnamed or default value, if any.
Keys do not automatically have an unnamed or default value, and unnamed values can be of any type.

For more information, see [Registry Element Size Limits](https://learn.microsoft.com/windows/win32/sysinfo/registry-element-size-limits).

### `dwFlags` [in, optional]

The flags that restrict the data type of value to be queried. If the data type of the value does not meet this criteria, the function fails. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **RRF_RT_ANY**<br><br>0x0000ffff | No type restriction. |
| **RRF_RT_DWORD**<br><br>0x00000018 | Restrict type to 32-bit RRF_RT_REG_BINARY \| RRF_RT_REG_DWORD. |
| **RRF_RT_QWORD**<br><br>0x00000048 | Restrict type to 64-bit RRF_RT_REG_BINARY \| RRF_RT_REG_QWORD. |
| **RRF_RT_REG_BINARY**<br><br>0x00000008 | Restrict type to REG_BINARY. |
| **RRF_RT_REG_DWORD**<br><br>0x00000010 | Restrict type to REG_DWORD. |
| **RRF_RT_REG_EXPAND_SZ**<br><br>0x00000004 | Restrict type to REG_EXPAND_SZ. |
| **RRF_RT_REG_MULTI_SZ**<br><br>0x00000020 | Restrict type to REG_MULTI_SZ. |
| **RRF_RT_REG_NONE**<br><br>0x00000001 | Restrict type to REG_NONE. |
| **RRF_RT_REG_QWORD**<br><br>0x00000040 | Restrict type to REG_QWORD. |
| **RRF_RT_REG_SZ**<br><br>0x00000002 | Restrict type to REG_SZ. |

This parameter can also include one or more of the following values.

| Value | Meaning |
| --- | --- |
| **RRF_NOEXPAND**<br><br>0x10000000 | Do not automatically expand environment strings if the value is of type REG_EXPAND_SZ. |
| **RRF_ZEROONFAILURE**<br><br>0x20000000 | If *pvData* is not **NULL**, set the contents of the buffer to zeroes on failure. |
| **RRF_SUBKEY_WOW6464KEY**<br><br>0x00010000 | If *lpSubKey* is not **NULL**, open the subkey that *lpSubKey* specifies with the KEY_WOW64_64KEY access rights. For information about these access rights, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).<br><br>You cannot specify **RRF_SUBKEY_WOW6464KEY** in combination with **RRF_SUBKEY_WOW6432KEY**. |
| **RRF_SUBKEY_WOW6432KEY**<br><br>0x00020000 | If *lpSubKey* is not **NULL**, open the subkey that *lpSubKey* specifies with the KEY_WOW64_32KEY access rights. For information about these access rights, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).<br><br>You cannot specify **RRF_SUBKEY_WOW6432KEY** in combination with **RRF_SUBKEY_WOW6464KEY**. |

### `pdwType` [out, optional]

A pointer to a variable that receives a code indicating the type of data stored in the specified value. For a list of the possible type codes, see
[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types). This parameter can be **NULL** if the type is not required.

### `pvData` [out, optional]

A pointer to a buffer that receives the value's data. This parameter can be **NULL** if the data is not required.

If the data is a string, the function checks for a terminating **null** character. If one is not found, the string is stored with a **null** terminator if the buffer is large enough to accommodate the extra character. Otherwise, the function fails and returns ERROR_MORE_DATA.

### `pcbData` [in, out, optional]

A pointer to a variable that specifies the size of the buffer pointed to by the *pvData* parameter, in bytes. When the function returns, this variable contains the size of the data copied to *pvData*.

The *pcbData* parameter can be **NULL** only if *pvData* is **NULL**.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, this size includes any terminating **null** character or characters. For more information, see Remarks.

If the buffer specified by *pvData* parameter is not large enough to hold the data, the function returns ERROR_MORE_DATA and stores the required buffer size in the variable pointed to by *pcbData*. In this case, the contents of the *pvData* buffer are zeroes if dwFlags specifies RRF_ZEROONFAILURE and undefined otherwise.

If *pvData* is **NULL**, and *pcbData* is non-**NULL**, the function returns ERROR_SUCCESS and stores the size of the data, in bytes, in the variable pointed to by *pcbData*. This enables an application to determine the best way to allocate a buffer for the value's data.

If *hKey* specifies **HKEY_PERFORMANCE_DATA** and the *pvData* buffer is not large enough to contain all of the returned data,
the function returns ERROR_MORE_DATA and the value returned through the *pcbData* parameter is undefined. This is because the size of the performance data can change from one call to the next. In this case, you must increase the buffer size and call
**RegGetValue** again passing the updated buffer size in the *pcbData* parameter. Repeat this until the function succeeds. You need to maintain a separate variable to keep track of the buffer size, because the value returned by *pcbData* is unpredictable.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

If the *pvData* buffer is too small to receive the value, the function returns ERROR_MORE_DATA.

If the lpValue registry value does not exist, the function returns ERROR_FILE_NOT_FOUND.

If *dwFlags* specifies a combination of both **RRF_SUBKEY_WOW6464KEY** and **RRF_SUBKEY_WOW6432KEY**, the function returns ERROR_INVALID_PARAMETER.

## Remarks

An application typically calls [RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea) to determine the value names and then **RegGetValue** to retrieve the data for the names.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, and the ANSI version of this function is used (either by explicitly calling **RegGetValueA** or by not defining UNICODE before including the Windows.h file), this function converts the stored Unicode string to an ANSI string before copying it to the buffer pointed to by *pvData*.

When calling this function with *hkey* set to the **HKEY_PERFORMANCE_DATA** handle and a value string of a specified object, the returned data structure sometimes has unrequested objects. Do not be surprised; this is normal behavior. You should always expect to walk the returned data structure to look for the requested object.

Note that operations that access certain registry keys are redirected. For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/desktop/SysInfo/registry-virtualization) and [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winreg.h header defines RegGetValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa)

[RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)