# RegEnumKeyW function

## Description

Enumerates the subkeys of the specified open registry key. The function retrieves the name of one subkey each time it is called.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the
[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa) function.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_ENUMERATE_SUB_KEYS access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_USERS**

### `dwIndex` [in]

The index of the subkey of *hKey* to be retrieved. This value should be zero for the first call to the
**RegEnumKey** function and then incremented for subsequent calls.

Because subkeys are not ordered, any new subkey will have an arbitrary index. This means that the function may return subkeys in any order.

### `lpName` [out]

A pointer to a buffer that receives the name of the subkey, including the terminating null character. This function copies only the name of the subkey, not the full key hierarchy, to the buffer.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `cchName` [in]

The size of the buffer pointed to by the *lpName* parameter, in **TCHARs**. To determine the required buffer size, use the
[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya) function to determine the size of the largest subkey for the key identified by the *hKey* parameter.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). If there are no more subkeys available, the function returns ERROR_NO_MORE_ITEMS.

If the *lpName* buffer is too small to receive the name of the key, the function returns ERROR_MORE_DATA.

## Remarks

To enumerate subkeys, an application should initially call the
**RegEnumKey** function with the *dwIndex* parameter set to zero. The application should then increment the *dwIndex* parameter and call the
**RegEnumKey** function until there are no more subkeys (meaning the function returns ERROR_NO_MORE_ITEMS).

The application can also set *dwIndex* to the index of the last key on the first call to the function and decrement the index until the subkey with index 0 is enumerated. To retrieve the index of the last subkey, use the
[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya).

While an application is using the
**RegEnumKey** function, it should not make calls to any registration functions that might change the key being queried.

> [!NOTE]
> The winreg.h header defines RegEnumKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)