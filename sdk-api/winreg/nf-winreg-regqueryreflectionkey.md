# RegQueryReflectionKey function

## Description

Determines whether reflection has been disabled or enabled for the specified key.

## Parameters

### `hBase` [in]

A handle to the registry key.
This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function; it cannot specify a key on a remote computer.

### `bIsReflectionDisabled` [out]

A value that indicates whether reflection has been disabled through [RegDisableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdisablereflectionkey) or enabled through [RegEnableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenablereflectionkey).

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the
FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

On WOW64, 32-bit applications view a registry tree that is separate from the registry tree that 64-bit
applications view. Registry reflection copies specific registry keys and values between the two views.

To disable registry reflection, use the
[RegDisableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdisablereflectionkey) function. To restore
reflection for a disabled key, use the
[RegEnableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenablereflectionkey) function.

## See also

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDisableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdisablereflectionkey)

[RegEnableReflectionKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenablereflectionkey)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/registry-redirector)