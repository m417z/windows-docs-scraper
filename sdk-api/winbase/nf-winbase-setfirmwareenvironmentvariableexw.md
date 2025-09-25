# SetFirmwareEnvironmentVariableExW function

## Description

Sets the value of the specified firmware environment variable and the attributes that indicate how this variable is stored and maintained.

## Parameters

### `lpName` [in]

The name of the firmware environment variable. The pointer must not be **NULL**.

### `lpGuid` [in]

The GUID that represents the namespace of the firmware environment variable. The GUID must be a string in the format "{*xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx*}". If the system does not support GUID-based namespaces, this parameter is ignored. The pointer must not be **NULL**.

### `pValue` [in]

A pointer to the new value for the firmware environment variable.

### `nSize` [in]

The size of the *pValue* buffer, in bytes. Unless the VARIABLE_ATTRIBUTE_APPEND_WRITE,
VARIABLE_ATTRIBUTE_AUTHENTICATED_WRITE_ACCESS, or
VARIABLE_ATTRIBUTE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS variable attribute is set via *dwAttributes*,
setting this value to zero will result in the deletion of this variable.

### `dwAttributes` [in]

Bitmask to set UEFI variable attributes associated with the variable. See also [UEFI Spec 2.3.1, Section 7.2](https://www.uefi.org/specifications).

| Value | Meaning |
| --- | --- |
| **VARIABLE_ATTRIBUTE_NON_VOLATILE**<br><br>0x00000001 | The firmware environment variable is stored in non-volatile memory (e.g. NVRAM). |
| **VARIABLE_ATTRIBUTE_BOOTSERVICE_ACCESS**<br><br>0x00000002 | The firmware environment variable can be accessed during boot service. |
| **VARIABLE_ATTRIBUTE_RUNTIME_ACCESS**<br><br>0x00000004 | The firmware environment variable can be accessed at runtime.<br><br>**Note** Variables with this attribute set, must also have **VARIABLE_ATTRIBUTE_BOOTSERVICE_ACCESS** set. |
| **VARIABLE_ATTRIBUTE_HARDWARE_ERROR_RECORD**<br><br>0x00000008 | Indicates hardware related errors encountered at runtime. |
| **VARIABLE_ATTRIBUTE_AUTHENTICATED_WRITE_ACCESS**<br><br>0x00000010 | Indicates an authentication requirement that must be met before writing to this firmware environment variable. For more information see, [UEFI spec 2.3.1](https://www.uefi.org/specifications). |
| **VARIABLE_ATTRIBUTE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS**<br><br>0x00000020 | Indicates authentication and time stamp requirements that must be met before writing to this firmware environment variable. When this attribute is set, the buffer, represented by *pValue*, will begin with an instance of a complete (and serialized) EFI_VARIABLE_AUTHENTICATION_2 descriptor. For more information see, [UEFI spec 2.3.1](https://www.uefi.org/specifications). |
| **VARIABLE_ATTRIBUTE_APPEND_WRITE**<br><br>0x00000040 | Append an existing environment variable with the value of *pValue*. If the firmware does not support the operation, then **SetFirmwareEnvironmentVariableEx** will return ERROR_INVALID_FUNCTION. |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include ERROR_INVALID_FUNCTION.

## Remarks

Starting with Windows 10, version 1803, Universal Windows apps can read and write UEFI firmware variables. See [Access UEFI firmware variables from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-uefi-firmware-variables-from-a-universal-windows-app) for details.

Starting with Windows 10, version 1803, reading UEFI firmware variables is also supported from User-Mode Driver Framework (UMDF) drivers. Writing UEFI firmware variables from UMDF drivers is not supported.

To write a firmware environment variable, the user account that the app is running under must have the [SE_SYSTEM_ENVIRONMENT_NAME](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants) privilege. A Universal Windows app must be run from an administrator account and follow the requirements outlined in [Access UEFI firmware variables from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-uefi-firmware-variables-from-a-universal-windows-app).

The correct method of changing the attributes of a variable is to delete the
variable and recreate it with different attributes.

The exact set of firmware environment variables is determined by the boot firmware. The location of these environment variables is also specified by the firmware. For example, on a UEFI-based system, NVRAM contains firmware environment variables that specify system boot settings. For information about specific variables used, see the [UEFI specification](https://www.uefi.org/specifications). For more information about UEFI and Windows, see [UEFI and Windows](https://learn.microsoft.com/windows-hardware/drivers/bringup/uefi-in-windows).

Firmware variables are not supported on a legacy BIOS-based system. The **SetFirmwareEnvironmentVariableEx** function will always fail on a legacy BIOS-based system, or if Windows was installed using legacy BIOS on a system that supports both legacy BIOS and UEFI. To identify these conditions, call the function with a dummy firmware environment name such as an empty string ("") for the *lpName* parameter and a dummy GUID such as "{00000000-0000-0000-0000-000000000000}" for the *lpGuid* parameter. On a legacy BIOS-based system, or on a system that supports both legacy BIOS and UEFI where Windows was installed using legacy BIOS, the function will fail with ERROR_INVALID_FUNCTION. On a UEFI-based system, the function will fail with an error specific to the firmware, such as ERROR_NOACCESS, to indicate that the dummy GUID namespace does not exist.

> [!NOTE]
> The winbase.h header defines SetFirmwareEnvironmentVariableEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access UEFI firmware variables from a Universal Windows App](https://learn.microsoft.com/windows/desktop/SysInfo/access-uefi-firmware-variables-from-a-universal-windows-app)

[GetFirmwareEnvironmentVariableEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfirmwareenvironmentvariableexa)

[SetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfirmwareenvironmentvariablea)