## Description

A PSHED plug-in's *DisableErrorSource* callback function disables an error source.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `ErrorSource` [in]

A pointer to a [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that describes the error source that is being disabled.

## Return value

A PSHED plug-in's *DisableErrorSource* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The error source was successfully disabled. |
| **STATUS_NOT_SUPPORTED** | The PSHED plug-in does not support disabling the specified error source. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error source control sets the **Callbacks.SetErrorSourceInfo**, **Callbacks.EnableErrorSource**, and **Callbacks.DisableErrorSource** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its [SetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_set_error_source_info), [EnableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_enable_error_source), and *DisableErrorSource* callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorSourceControl** flag in the **FunctionalAreaMask** member of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET structure.

The Windows kernel calls into the PSHED to disable an error source in response to an error source disable request by a WHEA management application. If a PSHED plug-in is registered to participate in error source control, the PSHED calls the PSHED plug-in's *DisableErrorSource* callback function to give the PSHED plug-in an opportunity to disable the error source. If the *DisableErrorSource* callback function returns STATUS_NOT_SUPPORTED, the PSHED will disable the error source. Otherwise, the PSHED will just return the return value that is returned by the *DisableErrorSource* callback function.

If the PSHED plug-in successfully disables the error source, the PSHED will update the WHEA_ERROR_SOURCE_DESCRIPTOR structure on behalf of the PSHED plug-in after the call to the PSHED plug-in's *DisableErrorSource* callback function returns. A PSHED plug-in's *DisableErrorSource* callback function should not modify the error source descriptor.

## See also

[EnableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_enable_error_source)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[SetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_set_error_source_info)

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)