# RegEnumKeyExA function

## Description

Enumerates the subkeys of the specified open registry key. The function retrieves information about one subkey each time it is called.

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

**HKEY_PERFORMANCE_DATA**

**HKEY_USERS**

### `dwIndex` [in]

The index of the subkey to retrieve. This parameter should be zero for the first call to the
**RegEnumKeyEx** function and then incremented for subsequent calls.

Because subkeys are not ordered, any new subkey will have an arbitrary index. This means that the function may return subkeys in any order.

### `lpName` [out]

A pointer to a buffer that receives the name of the subkey, including the terminating **null** character. The function copies only the name of the subkey, not the full key hierarchy, to the buffer.

If the function fails, no information is copied to this buffer.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `lpcchName` [in, out]

A pointer to a variable that specifies the size of the buffer specified by the *lpName* parameter, in characters. This size should include the terminating **null** character. If the function succeeds, the variable pointed to by *lpcchName* contains the number of characters stored in the buffer, not including the terminating **null** character.

To determine the required buffer size, use the
[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya) function to determine the size of the largest subkey for the key identified by the *hKey* parameter.

### `lpReserved`

This parameter is reserved and must be **NULL**.

### `lpClass` [in, out]

A pointer to a buffer that receives the user-defined class of the enumerated subkey. This parameter can be **NULL**.

### `lpcchClass` [in, out, optional]

A pointer to a variable that specifies the size of the buffer specified by the *lpClass* parameter, in characters. The size should include the terminating **null** character. If the function succeeds, *lpcchClass* contains the number of characters stored in the buffer, not including the terminating **null** character. This parameter can be **NULL** only if *lpClass* is **NULL**.

### `lpftLastWriteTime` [out, optional]

A pointer to [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the time at which the enumerated subkey was last written. This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). If there are no more subkeys available, the function returns ERROR_NO_MORE_ITEMS.

If the *lpName* buffer is too small to receive the name of the key, the function returns ERROR_MORE_DATA.

## Remarks

To enumerate subkeys, an application should initially call the
**RegEnumKeyEx** function with the *dwIndex* parameter set to zero. The application should then increment the *dwIndex* parameter and call
**RegEnumKeyEx** until there are no more subkeys (meaning the function returns ERROR_NO_MORE_ITEMS).

The application can also set *dwIndex* to the index of the last subkey on the first call to the function and decrement the index until the subkey with the index 0 is enumerated. To retrieve the index of the last subkey, use the
[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya) function.

While an application is using the
**RegEnumKeyEx** function, it should not make calls to any registration functions that might change the key being enumerated.

Note that operations that access certain registry keys are redirected. For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/desktop/SysInfo/registry-virtualization) and [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

> [!NOTE]
> On legacy versions of Windows, this API is also exposed by kernel32.dll.

#### Examples

For an example, see
[Enumerating Registry Subkeys](https://learn.microsoft.com/windows/desktop/SysInfo/enumerating-registry-subkeys).

> [!NOTE]
> The winreg.h header defines RegEnumKeyEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)