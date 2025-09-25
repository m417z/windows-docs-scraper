# RegOpenKeyA function

## Description

Opens the specified registry key.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function.

## Parameters

### `hKey` [in]

A handle to an open registry key. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

* **HKEY_CLASSES_ROOT**
* **HKEY_CURRENT_CONFIG**
* **HKEY_CURRENT_USER**
* **HKEY_LOCAL_MACHINE**
* **HKEY_USERS**

### `lpSubKey` [in, optional]

The name of the registry key to be opened. This key must be a subkey of the key identified by the *hKey* parameter.

Key names are not case sensitive.

If this parameter is **NULL** or a pointer to an empty string, the function returns the same handle that was passed in.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `phkResult` [out]

A pointer to a variable that receives a handle to the opened key. If the key is not one of the predefined registry keys, call the
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function after you have finished using the handle.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

The
**RegOpenKey** function uses the default security access mask to open a key. If opening the key requires a different access right, the function fails, returning ERROR_ACCESS_DENIED. An application should use the
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function to specify an access mask in this situation.

**RegOpenKey** does not create the specified key if the key does not exist in the database.

If your service or application impersonates different users, do not use this function with **HKEY_CURRENT_USER**. Instead, call the [RegOpenCurrentUser](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopencurrentuser) function.

> [!NOTE]
> The winreg.h header defines RegOpenKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)