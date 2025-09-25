# RegLoadMUIStringW function

## Description

Loads the specified string from the specified key and subkey.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_QUERY_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_USERS**

### `pszValue` [in, optional]

The name of the registry value.

### `pszOutBuf` [out, optional]

A pointer to a buffer that receives the string.

Strings of the following form receive special handling:

@[*path*]\*dllname*,-*strID*

The string with identifier *strID* is loaded from *dllname*; the *path* is optional. If the *pszDirectory* parameter is not **NULL**, the directory is prepended to the path specified in the registry data. Note that *dllname* can contain environment variables to be expanded.

### `cbOutBuf` [in]

The size of the *pszOutBuf* buffer, in bytes.

### `pcbData` [out, optional]

A pointer to a variable that receives the size of the data copied to the *pszOutBuf* buffer, in bytes.

If the buffer is not large enough to hold the data, the function returns ERROR_MORE_DATA and stores the required buffer size in the variable pointed to by *pcbData*. In this case, the contents of the buffer are undefined.

### `Flags` [in]

This parameter can be 0 or the following value.

| Value | Meaning |
| --- | --- |
| **REG_MUI_STRING_TRUNCATE**<br><br>0x00000001 | The string is truncated to fit the available size of the *pszOutBuf* buffer. If this flag is specified, *pcbData* must be **NULL**. |

### `pszDirectory` [in, optional]

The directory path.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

If the *pcbData* buffer is too small to receive the string, the function returns ERROR_MORE_DATA.

The ANSI version of this function returns ERROR_CALL_NOT_IMPLEMENTED.

## Remarks

The **RegLoadMUIString** function is supported only for Unicode. Although both Unicode (W) and ANSI (A) versions of this function are declared, the **RegLoadMUIStringA** function returns ERROR_CALL_NOT_IMPLEMENTED. Applications should explicitly call **RegLoadMUIStringW** or specify Unicode as the character set in platform invoke (PInvoke) calls.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winreg.h header defines RegLoadMUIString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)