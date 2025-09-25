# RegOpenKeyExA function

## Description

Opens the specified registry key. Note that key names are not case sensitive.

To perform transacted registry operations on a key, call the [RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function.

## Parameters

### `hKey` [in]

A handle to an open registry key. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
**RegOpenKeyEx** function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**
**HKEY_CURRENT_CONFIG**
**HKEY_CURRENT_USER**
**HKEY_LOCAL_MACHINE**
**HKEY_USERS**

### `lpSubKey` [in, optional]

The name of the registry subkey to be opened.

Key names are not case sensitive.

If the *lpSubKey* parameter is **NULL** or a pointer to an empty string,
and if *hKey* is a predefined key,
then the system refreshes the predefined key,
and *phkResult* receives the same *hKey* handle passed into the function.
Otherwise, *phkResult* receives a new handle to the opened key.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `ulOptions` [in]

Specifies the option to apply when opening the key. Set this parameter to zero or the following:

| Value | Meaning |
| --- | --- |
| **REG_OPTION_OPEN_LINK** | The key is a symbolic link. Registry symbolic links should only be used when absolutely necessary. |

### `samDesired` [in]

A mask that specifies the desired access rights to the key to be opened. The function fails if the security descriptor of the key does not permit the requested access for the calling process. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

### `phkResult` [out]

A pointer to a variable that receives a handle to the opened key. If the key is not one of the predefined registry keys, call the
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function after you have finished using the handle.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

> [!NOTE]
> On legacy versions of Windows, this API is also exposed by kernel32.dll.

## Remarks

Unlike the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) function, the
**RegOpenKeyEx** function does not create the specified key if the key does not exist in the registry.

Certain registry operations perform access checks against the security descriptor of the key, not the access mask specified when the handle to the key was obtained. For example, even if a key is opened with a *samDesired* of KEY_READ, it can be used to create registry keys if the key's security descriptor permits. In contrast, the [RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) function specifically requires that the key be opened with the KEY_SET_VALUE access right.

If your service or application impersonates different users, do not use this function with **HKEY_CURRENT_USER**. Instead, call the [RegOpenCurrentUser](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopencurrentuser) function.

Note that operations that access certain registry keys are redirected. For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/desktop/SysInfo/registry-virtualization) and [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

#### Examples

```cpp
lResult = RegOpenKeyEx (hKeyRoot, lpSubKey, 0, KEY_READ, &hKey);

if (lResult != ERROR_SUCCESS)
{
    if (lResult == ERROR_FILE_NOT_FOUND) {
        printf("Key not found.\n");
        return TRUE;
    }
    else {
        printf("Error opening key.\n");
        return FALSE;
    }
}
```

To see this example in context, see
[Deleting a Key with Subkeys](https://learn.microsoft.com/windows/desktop/SysInfo/deleting-a-key-with-subkeys).

> [!NOTE]
> The winreg.h header defines RegOpenKeyEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)