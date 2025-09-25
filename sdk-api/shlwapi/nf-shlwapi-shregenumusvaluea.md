# SHRegEnumUSValueA function

## Description

Enumerates the values of the specified registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `hUSkey` [in]

Type: **HUSKEY**

A handle to a currently open registry subkey. The subkey must have been opened with the KEY_SET_VALUE access right. For more information, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle can be obtained through the [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya) function.

### `dwIndex` [in]

Type: **DWORD**

The index of the value to retrieve. This parameter should be zero for the first call and incremented for subsequent calls.

### `pszValueName` [out]

Type: **LPTSTR**

A pointer to a character buffer that receives the enumerated value name. The size of this buffer is specified in *pcchValueNameLen*.

### `pcchValueName` [in, out]

Type: **LPDWORD**

A pointer to a **DWORD** that, on entry, contains the size of the buffer at *pszValueName*, in characters. On exit, this contains the number of characters that were copied to *pszValueName*.

### `pdwType` [out, optional]

Type: **LPDWORD**

A pointer to a **DWORD** that receives the data type of the value. These are the same values as those described under the *lpType* parameter of [RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea).

### `pvData` [out, optional]

Type: **void***

A pointer to a buffer that receives the data for the value entry. The size of this buffer is specified in *pcbData*. This parameter can be **NULL** if the data is not required.

### `pcbData` [in, out, optional]

Type: **LPDWORD**

A pointer to a **DWORD** that, on entry, contains the size of the buffer at *pvData*. On exit, this contains the number of bytes that were copied to *pvData*.

### `enumRegFlags` [in]

Type: **[SHREGENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-shregenum_flags)**

One of the [SHREGENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-shregenum_flags) that specifies the base key in which the enumeration should take place.

## Return value

Type: **LSTATUS**

Returns **ERROR_SUCCESS** if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to retrieve a textual description of the error.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHRegEnumUSValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).