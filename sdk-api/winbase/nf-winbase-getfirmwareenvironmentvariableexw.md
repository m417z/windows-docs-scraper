# GetFirmwareEnvironmentVariableExW function

## Description

Retrieves the value of the specified firmware environment variable and its attributes.

## Parameters

### `lpName`

The name of the firmware environment variable. The pointer must not be **NULL**.

### `lpGuid`

The GUID that represents the namespace of the firmware environment variable. The GUID must be a string in the format "{*xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx*}" where 'x' represents a hexadecimal value. The pointer must not be **NULL**.

### `pBuffer`

A pointer to a buffer that receives the value of the specified firmware environment variable.

### `nSize`

The size of the *pValue* buffer, in bytes.

### `pdwAttribubutes`

Bitmask identifying UEFI variable attributes associated with the variable. See [SetFirmwareEnvironmentVariableEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfirmwareenvironmentvariableexa) for the bitmask definition.

## Return value

If the function succeeds, the return value is the number of bytes stored in the *pValue* buffer.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include ERROR_INVALID_FUNCTION.

## Remarks

Starting with Windows 10, version 1803, Universal Windows apps can read and write UEFI firmware variables. See [Access UEFI firmware variables from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-uefi-firmware-variables-from-a-universal-windows-app) for details.

To read a UEFI firmware environment variable, the user account that the app is running under must have the [SE_SYSTEM_ENVIRONMENT_NAME](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants) privilege. A Universal Windows app must be run from an administrator account and follow the requirements outlined in [Access UEFI firmware variables from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-uefi-firmware-variables-from-a-universal-windows-app).

Starting with Windows 10, version 1803, reading Unified Extensible Firmware Interface (UEFI) variables is also supported from User-Mode Driver Framework (UMDF) drivers. Writing UEFI variables from UMDF drivers is not supported.

The exact set of firmware environment variables is determined by the boot firmware. The location of these environment variables is also specified by the firmware. For example, on a UEFI-based system, NVRAM contains firmware environment variables that specify system boot settings. For information about specific variables used, see the [UEFI specification](https://www.uefi.org/specifications). For more information about UEFI and Windows, see [UEFI and Windows](https://learn.microsoft.com/windows-hardware/drivers/bringup/uefi-in-windows).

Firmware variables are not supported on a legacy BIOS-based system. The **GetFirmwareEnvironmentVariableEx** function will always fail on a legacy BIOS-based system, or if Windows was installed using legacy BIOS on a system that supports both legacy BIOS and UEFI. To identify these conditions, call the function with a dummy firmware environment name such as an empty string ("") for the *lpName* parameter and a dummy GUID such as "{00000000-0000-0000-0000-000000000000}" for the *lpGuid* parameter. On a legacy BIOS-based system, or on a system that supports both legacy BIOS and UEFI where Windows was installed using legacy BIOS, the function will fail with ERROR_INVALID_FUNCTION. On a UEFI-based system, the function will fail with an error specific to the firmware, such as ERROR_NOACCESS, to indicate that the dummy GUID namespace does not exist.

If you are creating a backup application, you can use this function to save all the boot settings for the system so they can be restored using the [SetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfirmwareenvironmentvariablea)
function if needed.

> [!NOTE]
> The winbase.h header defines GetFirmwareEnvironmentVariableEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access UEFI firmware variables from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-uefi-firmware-variables-from-a-universal-windows-app)

[GetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfirmwareenvironmentvariablea)

[SetFirmwareEnvironmentVariableEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfirmwareenvironmentvariableexa)