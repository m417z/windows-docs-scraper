# RegCloseKey function

## Description

Closes a handle to the specified registry key.

## Parameters

### `hKey` [in]

A handle to the open key to be closed. The handle must have been opened by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa),
[RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), [RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda), or [RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya) function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

The handle for a specified key should not be used after it has been closed, because it will no longer be valid. Key handles should not be left open any longer than necessary.

The
**RegCloseKey** function does not necessarily write information to the registry before returning; it can take as much as several seconds for the cache to be flushed to the hard disk. If an application must explicitly write registry information to the hard disk, it can use the
[RegFlushKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regflushkey) function.
**RegFlushKey**, however, uses many system resources and should be called only when necessary.

#### Examples

For an example, see
[Deleting a Key with Subkeys](https://learn.microsoft.com/windows/desktop/SysInfo/deleting-a-key-with-subkeys).

## See also

[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegFlushKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regflushkey)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)