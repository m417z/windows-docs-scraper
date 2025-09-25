# SHRegGetValueA function

## Description

[**SHRegGetValue** may be altered or unavailable in subsequent versions of the operating system or product. Use [RegGetValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-reggetvaluea) in its place.]

Retrieves a registry value.

## Parameters

### `hkey` [in]

Type: **HKEY**

A handle to the currently open key, or any of the following predefined values.

#### HKEY_CLASSES_ROOT

#### HKEY_CURRENT_CONFIG

#### HKEY_CURRENT_USER

#### HKEY_LOCAL_MACHINE

#### HKEY_PERFORMANCE_DATA

#### HKEY_USERS

### `pszSubKey` [in]

Type: **LPCTSTR**

A pointer to a **null**-terminated string that specifies the relative path from *hkey* to the subkey to retrieve the value from. This parameter can be **NULL** or an empty string, in which case the data is retrieved from the *hkey* location.

### `pszValue` [in]

Type: **LPCTSTR**

A pointer to a **null**-terminated string that contains the name of the value. This parameter can be **NULL** or an empty string, in which case the data is retrieved from the Default value.

### `srrfFlags` [in]

Type: **[SRRF](https://learn.microsoft.com/windows/desktop/shell/srrf)**

One or more of the [SRRF](https://learn.microsoft.com/windows/desktop/shell/srrf) flags that restricts the data to be retrieved. At least one type restriction (SRRF_RT) value must be specified.

### `pdwType` [in, out]

Type: **LPDWORD**

A pointer to a **DWORD** that receives the type of data stored in the retrieved value. When using default values, the input *pdwType* is the type of the default value. For possible values, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type). If the SRRF_NOEXPAND flag is not set, REG_EXPAND_SZ types are automatically expanded and returned as REG_SZ. If type information is not required, this parameter can be **NULL**.

### `pvData` [out]

Type: **LPVOID**

A pointer to a buffer that receives the value's data. This parameter can be **NULL** if the data is not needed. For example, if you were testing only for a value's existence, the specific value data would be superfluous.

### `pcbData` [in, out]

Type: **LPDWORD**

A pointer to a **DWORD** that, on entry, contains the size of the destination data buffer *pvData*, in bytes. This value can be **NULL** only if *pvData* is **NULL**. On exit, *pcbData* points to one of these values.

| pvData | Return Value | pcbData |
| --- | --- | --- |
| **NULL** | ERROR_SUCCESS | Size in bytes sufficient to hold the registry data. Note that this is not guaranteed to be the precise size, but only a sufficient size. |
| Non-**NULL** | ERROR_SUCCESS | Exact number of bytes written to *pvData*. |
| Non-**NULL** | ERROR_MORE_DATA | Size in bytes needed to hold the entire data. Note that this is not guaranteed to be the precise size, but only a sufficient size. |

## Return value

Type: **LSTATUS**

Returns **ERROR_SUCCESS** if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to retrieve a generic description of the error.

## Remarks

**SHRegGetValue** provides data type checking, boot mode checking, auto-expansion of REG_EXPAND_SZ data, and guaranteed **null**-termination of REG_SZ, REG_EXPAND_SZ, and REG_MULTI_SZ data.

The key identified by *hkey* must have been opened with [KEY_QUERY_VALUE](https://learn.microsoft.com/windows/desktop/shell/messages) security access. If *pszSubKey* is not **NULL** or an empty string, that key also must be able to be opened with **KEY_QUERY_VALUE** security access in the current calling context.

If the data's type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ, then any returned data includes or takes into account the string's **null**-termination. For example, if *pvData* is not **NULL**, the data returned in that buffer is **null**-terminated. If *pcbData* is not **NULL**, the buffer size that it points to includes the bytes required to hold the terminating **null** character.

Unless the SRRF_NOEXPAND flag is set, string data of type REG_EXPAND_SZ is automatically expanded before being returned. The expanded string's type is reported in *pdwType* as REG_SZ, the *pcbData* parameter points to the number of bytes written for the expanded string, and the buffer pointed to by *pvData* holds the expanded version of the string.

### Performance Notes

If *pszSubKey* is not **NULL** or an empty string, that key is opened and closed by this function each time it is accessed. If your application must retrieve a series of values from the same subkey, you will see better performance by opening the key using [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) before calling **SHRegGetValue**. Use the key returned in the *phkResult* parameter of **RegOpenKeyEx** as the *hkey* parameter in this function, with *pszSubKey* set to **NULL**.

The potential for an additional call to the registry to read or re-read the data exists when the data type is REG_EXPAND_SZ and the SRRF_NOEXPAND flag has not been set. The following conditions result in that additional call.

* *pvData* is **NULL**, *pcbData* is not **NULL**. Though the data is not retrieved, the registry must be read to get the string and that string expanded to determine the required size of the data buffer.
* *pvData* is not **NULL**, but is too small to hold the data. The data is re-read to get the full string, the string is expanded, and the total required size is determined.

> [!NOTE]
> The shlwapi.h header defines SHRegGetValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa)