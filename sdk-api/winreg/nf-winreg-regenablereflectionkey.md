# RegEnableReflectionKey function

## Description

Restores registry reflection for the specified disabled key. Restoring reflection for a key does not affect reflection of any subkeys.

## Parameters

### `hBase` [in]

A handle to the registry key that was previously disabled using the [RegDisableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdisablereflectionkey) function. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function; it cannot specify a key on a remote computer.

If the key is not on the reflection list, this function succeeds but has no effect. For more information, see [Registry Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/registry-redirector) and [Registry Reflection](https://learn.microsoft.com/windows/desktop/WinProg64/registry-reflection).

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

On WOW64, 32-bit applications view a registry tree that is separate from the registry tree that 64-bit applications view. Registry reflection copies specific registry keys and values between the two views.

## See also

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDisableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdisablereflectionkey)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryreflectionkey)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/registry-redirector)