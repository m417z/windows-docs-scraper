# ExSetFirmwareEnvironmentVariable function

## Description

The **ExSetFirmwareEnvironmentVariable** routine sets the value of the specified system firmware environment variable.

## Parameters

### `VariableName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the specified environment variable.

### `VendorGuid` [in]

A pointer to a GUID that identifies the vendor associated with the specified environment variable. Environment variables are grouped into namespaces based on their vendor GUIDs. Some hardware platforms might not support vendor GUIDs. On these platforms, all variables are grouped into one, common namespace, and the *VendorGuid* parameter is ignored.

### `Value` [in]

A pointer to a caller-allocated buffer that contains the data value to write to the specified environment variable.

### `ValueLength` [in]

The size, in bytes, of the data value contained in the *Value* buffer.

### `Attributes` [in]

The attributes to assign to the specified environment variable. The VARIABLE_ATTRIBUTE_NON_VOLATILE attribute bit must be set or this call will fail. For more information about the attribute bits that are defined for this parameter, see Remarks in [ExGetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetfirmwareenvironmentvariable).

## Return value

**ExSetFirmwareEnvironmentVariable** returns STATUS_SUCCESS if it is successful. Possible return values include the following error status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Available system resources are insufficient to complete the requested operation. |
| **STATUS_INVALID_PARAMETER** | One of the parameters is not valid. |
| **STATUS_NOT_IMPLEMENTED** | This routine is not supported on this platform. |
| **STATUS_UNSUCCESSFUL** | The firmware returned an unrecognized error. |

## Remarks

The caller requires the system environment privilege (SE_SYSTEM_ENVIRONMENT_PRIVILEGE) to use this routine.

System firmware environment variables contain data values that are passed between the boot firmware environment implemented in the hardware platform and the operating-system loaders and other software that runs in the firmware environment. For more information, see Remarks in [ExGetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetfirmwareenvironmentvariable).

If you create a backup datastore, you can use the [ExGetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetfirmwareenvironmentvariable) routine to save all the boot settings for the platform. Later, you can use **ExSetFirmwareEnvironmentVariable** to restore these settings if needed.

**ExSetFirmwareEnvironmentVariable** is the kernel-mode equivalent of the Win32 [SetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setfirmwareenvironmentvariablea) function.

## See also

[ExGetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetfirmwareenvironmentvariable)

[SetFirmwareEnvironmentVariable](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setfirmwareenvironmentvariablea)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)