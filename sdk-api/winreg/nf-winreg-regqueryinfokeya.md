# RegQueryInfoKeyA function

## Description

Retrieves information about the specified registry key.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_QUERY_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

```
   HKEY_CLASSES_ROOT
   HKEY_CURRENT_CONFIG
   HKEY_CURRENT_USER
   HKEY_LOCAL_MACHINE
   HKEY_PERFORMANCE_DATA
   HKEY_USERS
```

### `lpClass` [out, optional]

A pointer to a buffer that receives the user-defined class of the key. This parameter can be **NULL**.

### `lpcchClass` [in, out, optional]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpClass* parameter, in characters.

The size should include the terminating **null** character. When the function returns, this variable contains the size of the class string that is stored in the buffer. The count returned does not include the terminating **null** character. If the buffer is not big enough, the function returns ERROR_MORE_DATA, and the variable contains the size of the string, in characters, without counting the terminating **null** character.

If *lpClass* is **NULL**, *lpcClass* can be **NULL**.

If the *lpClass* parameter is a valid address, but the *lpcClass* parameter is not, for example, it is **NULL**, then the function returns ERROR_INVALID_PARAMETER.

### `lpReserved`

This parameter is reserved and must be **NULL**.

### `lpcSubKeys` [out, optional]

A pointer to a variable that receives the number of subkeys that are contained by the specified key. This parameter can be **NULL**.

### `lpcbMaxSubKeyLen` [out, optional]

A pointer to a variable that receives the size of the key's subkey with the longest name, in ANSI characters, not including the terminating **null** character. This parameter can be **NULL**.

### `lpcbMaxClassLen` [out, optional]

A pointer to a variable that receives the size of the longest string that specifies a subkey class, in ANSI characters. The count returned does not include the terminating **null** character. This parameter can be **NULL**.

### `lpcValues` [out, optional]

A pointer to a variable that receives the number of values that are associated with the key. This parameter can be **NULL**.

### `lpcbMaxValueNameLen` [out, optional]

A pointer to a variable that receives the size of the key's longest value name, in ANSI characters. The size does not include the terminating **null** character. This parameter can be **NULL**.

### `lpcbMaxValueLen` [out, optional]

A pointer to a variable that receives the size of the longest data component among the key's values, in bytes. This parameter can be **NULL**.

### `lpcbSecurityDescriptor` [out, optional]

A pointer to a variable that receives the size of the key's security descriptor, in bytes. This parameter can be **NULL**.

### `lpftLastWriteTime` [out, optional]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the last write time. This parameter can be **NULL**.

The function sets the members of the
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to indicate the last time that the key or any of its value entries is modified.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

If the *lpClass* buffer is too small to receive the name of the class, the function returns ERROR_MORE_DATA.

## Remarks

> [!NOTE]
> On legacy versions of Windows, this API is also exposed by kernel32.dll.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa)

[RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea)

[RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)