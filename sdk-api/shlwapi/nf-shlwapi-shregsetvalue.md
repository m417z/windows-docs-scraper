# SHRegSetValue function

## Description

Not supported.

Sets a registry value.

Use [RegSetValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvaluea) in its place.

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

Type: **LPCWSTR**

A pointer to a null-terminated string that specifies the relative path from *hkey* to the subkey from which to retrieve the value. This parameter can be **NULL** or an empty string, in which case the data is retrieved from the *hkey* location.

### `pszValue` [in]

Type: **LPCWSTR**

A pointer to a null-terminated string that contains the name of the value. This parameter can be **NULL** or an empty string, in which case the data is retrieved from the Default value.

### `srrfFlags` [in]

Type: **[SRRF](https://learn.microsoft.com/windows/desktop/shell/srrf)**

One or more of the [SRRF](https://learn.microsoft.com/windows/desktop/shell/srrf) flags that restricts the data to be set. At least one type restriction (SRRF_RT) value must be specified.

### `dwType` [in]

Type: **DWORD**

The **DWORD** that indicates the type of data stored in the value to be set. When using default values, the input *dwType* is the type of the default value. For possible values, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type). If the SRRF_NOEXPAND flag is not set, REG_EXPAND_SZ types are automatically expanded and returned as REG_SZ. If type information is not required, this parameter can be **NULL**.

### `pvData` [in]

Type: **LPCVOID**

A pointer to a buffer that contains the value's data. This parameter can be **NULL** if the data is not needed.

### `cbData` [in]

Type: **DWORD**

The size of the source data buffer *pvData*, in bytes. This value can be **NULL** only if *pvData* is **NULL**.

## Return value

Type: **LONG**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to retrieve a generic description of the error.

## See also

[RegSetKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetkeyvaluea)