# SHRegWriteUSValueW function

## Description

Writes a value to a registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `hUSKey` [in]

Type: **HUSKEY**

A handle to a currently open registry subkey. The subkey must have been opened with the KEY_SET_VALUE access right. For more information, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle can be obtained through the [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya) function.

### `pwzValue`

TBD

### `dwType` [in]

Type: **DWORD**

The type of the data to be stored in the value specified by *pszValue*. One of the following registry value types defined in Winnt.h and Wdm.h.

#### REG_NONE (0x00000000)

#### REG_SZ (0x00000001)

#### REG_EXPAND_SZ (0x00000002)

#### REG_BINARY (0x00000003)

#### REG_DWORD (0x00000004)

#### REG_DWORD_LITTLE_ENDIAN (0x00000004)

#### REG_DWORD_BIG_ENDIAN (0x00000005)

#### REG_LINK (0x00000006)

#### REG_MULTI_SZ (0x00000007)

#### REG_RESOURCE_LIST (0x00000008)

#### REG_FULL_RESOURCE_DESCRIPTOR (0x00000009)

#### REG_RESOURCE_REQUIREMENTS_LIST (0x0000000A)

#### REG_QWORD (0x0000000B)

#### REG_QWORD_LITTLE_ENDIAN (0x0000000B)

### `pvData` [in]

Type: **const void***

A pointer to the data to be set for the value specified by *pszValue*. For string-based types, such as REG_SZ, the string must be null-terminated. With the REG_MULTI_SZ data type, the string must be terminated with two null characters. A backslash in a path must be preceded by another backslash as an escape character. For example, specify "C:\\mydir\\myfile" to store the string "C:\mydir\myfile".

### `cbData` [in]

Type: **DWORD**

The size, in bytes, of the data pointed to by the *pvData* parameter. If the data is of type REG_SZ, REG_EXPAND_SZ, or REG_MULTI_SZ, *cbData* must include the size of the terminating null character or characters.

### `dwFlags` [in]

Type: **DWORD**

Flags that indicate the subtree to which the data should be written. One or more of the following values:

#### SHREGSET_HKCU (0x00000001)

Write to **HKEY_CURRENT_USER** only if a value of the name specified in *pszValue* does not currently exist under the specified subkey.

#### SHREGSET_FORCE_HKCU (0x00000002)

Write to **HKEY_CURRENT_USER**. If a value of the name specified in *pszValue* already exists, it will be overwritten.

#### SHREGSET_HKLM (0x00000004)

Write to **HKEY_LOCAL_MACHINE** only if a value of the name specified in *pszValue* does not currently exist under the specified subkey..

#### SHREGSET_FORCE_HKLM (0x00000008)

Write to **HKEY_LOCAL_MACHINE**. If a value of the name specified in *pszValue* already exists, it will be overwritten.

#### SHREGSET_DEFAULT (0x00000006)

Equivalent to (**SHREGSET_FORCE_HKCU** | **SHREGSET_HKLM**).

### `dwFlags.SHREGSET_DEFAULT` (0x00000006)

Equivalent to (**SHREGSET_FORCE_HKCU** | **SHREGSET_HKLM**).

### `dwFlags.SHREGSET_FORCE_HKCU` (0x00000002)

Write to **HKEY_CURRENT_USER**. If a value of the name specified in *pszValue* already exists, it will be overwritten.

### `dwFlags.SHREGSET_FORCE_HKLM` (0x00000008)

Write to **HKEY_LOCAL_MACHINE**. If a value of the name specified in *pszValue* already exists, it will be overwritten.

### `dwFlags.SHREGSET_HKCU` (0x00000001)

Write to **HKEY_CURRENT_USER** only if a value of the name specified in *pszValue* does not currently exist under the specified subkey.

### `dwFlags.SHREGSET_HKLM` (0x00000004)

Write to **HKEY_LOCAL_MACHINE** only if a value of the name specified in *pszValue* does not currently exist under the specified subkey..

### `dwType.REG_BINARY` (0x00000003)

### `dwType.REG_DWORD` (0x00000004)

### `dwType.REG_DWORD_BIG_ENDIAN` (0x00000005)

### `dwType.REG_DWORD_LITTLE_ENDIAN` (0x00000004)

### `dwType.REG_EXPAND_SZ` (0x00000002)

### `dwType.REG_FULL_RESOURCE_DESCRIPTOR` (0x00000009)

### `dwType.REG_LINK` (0x00000006)

### `dwType.REG_MULTI_SZ` (0x00000007)

### `dwType.REG_NONE` (0x00000000)

### `dwType.REG_QWORD` (0x0000000B)

### `dwType.REG_QWORD_LITTLE_ENDIAN` (0x0000000B)

### `dwType.REG_RESOURCE_LIST` (0x00000008)

### `dwType.REG_RESOURCE_REQUIREMENTS_LIST` (0x0000000A)

### `dwType.REG_SZ` (0x00000001)

#### - pszValue [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that specifies the name of the value. This value is an entry in the subkey specified by *hUSKey*. If a value with this name is not already present in the subkey, it will be added.

If this parameter is **NULL** or an empty string, the function sets the type and data for the subkey's Default value.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful; otherwise, a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

To use **SHRegWriteUSValue**, you must first open the key with [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya). Once the key is opened, you can use **SHRegWriteUSValue** as many times as necessary.

If you only need to write a single value, you should use [SHRegSetUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregsetusvaluea), which both opens the key and writes the value.

If you need to write more than one value on the same key, multiple calls to **SHRegWriteUSValue** are usually more efficient than [SHRegSetUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregsetusvaluea), because the key is only opened once.

> [!NOTE]
> The shlwapi.h header defines SHRegWriteUSValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types)