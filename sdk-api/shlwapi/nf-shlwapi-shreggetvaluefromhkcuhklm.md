# SHRegGetValueFromHKCUHKLM function

## Description

[This function is no longer supported.]

Obtains specified information from the registry. This function will check HKEY_CURRENT_USER for the requested information in the specified subkey. If the information does not exist under the HKEY_CURRENT_USER subtree, the function checks the HKEY_LOCAL_MACHINE subtree for the same information.

## Parameters

### `pwszKey` [in]

Type: **PCWSTR**

A pointer to a **null**-terminated Unicode string that specifies the path to the registry key.

### `pwszValue` [in]

Type: **PCWSTR**

A pointer to a **null**-terminated Unicode string that specifies the key value. This value can be **NULL**, in which case data is retrieved from the Default value.

### `srrfFlags` [in]

Type: **[SRRF](https://learn.microsoft.com/windows/desktop/shell/srrf)**

The [SRRF](https://learn.microsoft.com/windows/desktop/shell/srrf) flag constants. If more than one flag is used they can be combined using a bitwise OR. These flags are used to restrict the type of data returned. This value cannot be 0.

### `pdwType` [out]

Type: **DWORD***

When this function returns, contains a pointer to a **DWORD** which receives a code that indicates the type of data stored in the specified value. This can be set to **NULL** if no type information is wanted. If this value is not **NULL**, and the SRRF_NOEXPAND flag has not been set, data types of REG_EXPAND_SZ will be returned as REG_SZ since they are automatically expanded in this method.

### `pvData` [in]

Type: **LPCVOID**

A pointer to a buffer that contains the value's data. This parameter can be **NULL** if the data is not needed. This value must contain the size of the *pvData* buffer on entry. If *pvData* is **NULL** (or if *pvData* is not **NULL**, but too small of a buffer to hold the registry data), then on exit it will contain the size required to hold the registry data.

### `pcbData` [in, out]

Type: **DWORD***

When this function returns, contains a pointer to the size of the data, in bytes.

## Return value

Type: **LONG**

If successful, this function returns ERROR_SUCCESS and all out parameters requested. Returns ERROR_MORE_DATA if the function fails due to insufficient space in a provided non-**NULL** pvData. In this case only *pdwType* and *pcbData* may contain valid data, *pvData* will be undefined. Otherwise, returns a nonzero error code defined in Winerror.h . You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.