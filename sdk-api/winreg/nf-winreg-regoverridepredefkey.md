# RegOverridePredefKey function

## Description

Maps a predefined registry key to the specified registry key.

## Parameters

### `hKey` [in]

A handle to one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

- **HKEY_CLASSES_ROOT**
- **HKEY_CURRENT_CONFIG**
- **HKEY_CURRENT_USER**
- **HKEY_LOCAL_MACHINE**
- **HKEY_PERFORMANCE_DATA**
- **HKEY_USERS**

### `hNewHKey` [in, optional]

A handle to an open registry key. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function. It cannot be one of the predefined keys. The function maps *hKey* to refer to the *hNewHKey* key. This affects only the calling process.

If *hNewHKey* is **NULL**, the function restores the default mapping of the predefined key.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

The
**RegOverridePredefKey** function is intended for software installation programs. It allows them to remap a predefined key, load a DLL component that will be installed on the system, call an entry point in the DLL, and examine the changes to the registry that the component attempted to make. The installation program can then write those changes to the locations intended by the DLL, or make changes to the data before writing it.

For example, consider an installation program that installs an ActiveX control as part of an application installation. The installation program needs to call the control's
[DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) entry point to enable the control to register itself. Before this call, the installation program can call
**RegOverridePredefKey** to remap **HKEY_CLASSES_ROOT** to a temporary key such as **HKEY_CURRENT_USER**\***TemporaryInstall***\***DllRegistration***. It then calls **DllRegisterServer**, which causes the ActiveX control to write its registry entries to the temporary key. The installation program then calls
**RegOverridePredefKey** again to restore the original mapping of **HKEY_CLASSES_ROOT**. The installation program can modify the keys written to the temporary key, if necessary, before copying them to the original **HKEY_CLASSES_ROOT**.

After the call to
**RegOverridePredefKey**, you can safely call
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) to close the *hNewHKey* handle. The system maintains its own reference to *hNewHKey*.

## See also

[DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)