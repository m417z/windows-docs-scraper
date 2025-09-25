# RegLoadAppKeyW function

## Description

Loads the specified registry hive as an application hive.

## Parameters

### `lpFile` [in]

The name of the hive file. This hive must have been created with the
[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) or [RegSaveKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeyexa) function. If the file does not exist, an empty hive file is created with the specified name.

### `phkResult` [out]

Pointer to the handle for the root key of the loaded hive.

The only way to access keys in the hive is through this handle. The registry will prevent an application from accessing keys in this hive using an absolute path to the key. As a result, it is not possible to navigate to this hive through the registry's namespace.

### `samDesired` [in]

A mask that specifies the access rights requested for the returned root key. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

### `dwOptions` [in]

If this parameter is REG_PROCESS_APPKEY, the hive cannot be loaded again while it is loaded by the caller. This prevents access to this registry hive by another caller.

### `Reserved`

This parameter is reserved.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

Unlike [RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya), **RegLoadAppKey** does not load the hive under HKEY_LOCAL_MACHINE or HKEY_USERS. Instead, the hive is loaded under a special root that cannot be enumerated. As a result, there is no way to enumerate hives currently loaded by **RegLoadAppKey**. All operations on hives loaded by **RegLoadAppKey** have to be performed relative to the handle returned in *phkResult.*

If two processes are required to perform operations on the same hive, each process must call **RegLoadAppKey** to retrieve a handle. During the **RegLoadAppKey** operation, the registry will verify if the file has already been loaded. If it has been loaded, the registry will return a handle to the previously loaded hive rather than re-loading the hive.

All keys inside the hive must have the same security descriptor, otherwise the function will fail. This security descriptor must grant the caller the access specified by the *samDesired* parameter or the function will fail. You cannot use the [RegSetKeySecurity](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetkeysecurity) function on any key inside the hive.

In Windows 8 and later, each process can call **RegLoadAppKey** to load multiple hives. In Windows 7 and earlier, each process can load only one hive using **RegLoadAppKey** at a time.

Any hive loaded using **RegLoadAppKey** is automatically unloaded when all handles to the keys inside the hive are closed using [RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winreg.h header defines RegLoadAppKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Hive](https://learn.microsoft.com/windows/desktop/SysInfo/registry-hives)