## Description

A PSHED plug-in's *SetErrorSourceInfo* callback function configures an error source.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `ErrorSource` [in]

A pointer to a [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that describes the error source that is being configured.

## Return value

A PSHED plug-in's *SetErrorSourceInfo* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The error source was successfully configured. |
| **STATUS_NOT_SUPPORTED** | The PSHED plug-in does not support configuration of the specified error source. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error source control sets the **Callbacks.SetErrorSourceInfo**, **Callbacks.EnableErrorSource**, and **Callbacks.DisableErrorSource** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its *SetErrorSourceInfo*, [EnableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_enable_error_source), and [DisableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_disable_error_source) callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorSourceControl** flag in the **FunctionalAreaMask** member of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET structure.

The Windows kernel calls into the PSHED to configure an error source in response to an error source configuration request by a WHEA management application. If a PSHED plug-in is registered to participate in error source control, the PSHED calls the PSHED plug-in's *SetErrorSourceInfo* callback function to give the PSHED plug-in an opportunity to perform the error source configuration operation. The error source configuration data is included in the [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that is pointed to by the *ErrorSource* parameter.

If the PSHED plug-in does not support configuration of the specified error source, the *SetErrorSourceInfo* callback function returns STATUS_NOT_SUPPORTED. In this situation, the PSHED performs the requested error source configuration operation.

If the PSHED plug-in's supports configuration of the specified error source, the *SetErrorSourceInfo* callback function should save the error source's configuration data in the registry, in the system's BIOS tables, or in some other form of nonvolatile data storage that is available to the error source. The specific form of nonvolatile data storage that is used by an error source for storing the error source's configuration data is implementation-specific. The *SetErrorSourceInfo* callback function should apply the configuration data to the error source in such a way that the configuration changes become effective the next time that the system is restarted. When the system is restarted, the PSHED plug-in should report the new error source configuration data for the error source to the operating system during error source discovery.

## See also

[DisableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_disable_error_source)

[EnableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_enable_error_source)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)