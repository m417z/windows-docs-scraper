## Description

A PSHED plug-in's *GetErrorSourceInfo* callback function returns an error source descriptor structure that represents a particular error source that is implemented by the hardware platform.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `ErrorSource` [in, out]

A pointer to a [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that represents a particular error source that is implemented by the hardware platform.

## Return value

A PSHED plug-in's *GetErrorSourceInfo* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The error source information was successfully updated. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error source discovery sets the **Callbacks.GetAllErrorSources** member and, optionally, the **Callbacks.GetErrorSourceInfo** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its [GetAllErrorSources](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_all_error_sources) and *GetErrorSourceInfo* callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFADiscovery** flag in the **FunctionalAreaMask** member of the **WHEA_PSHED_PLUGIN_REGISTRATION_PACKET** structure.

The Windows kernel calls into the PSHED to obtain additional details about a particular error source. This occurs when a new error source is added to the system by a bus driver. For example, when the PCI driver discovers a PCI Express (PCIe) device that is capable of reporting PCIe errors, it reports the error source to the operating system.

If a PSHED plug-in is registered to participate in error source discovery and it has implemented a *GetErrorSourceInfo* callback function, after the PSHED has updated the error source descriptor structure with the information that it has collected about the error source, the PSHED calls the PSHED plug-in's *GetErrorSourceInfo* callback function so that the PSHED plug-in can provide additional details about the error source. The *GetErrorSourceInfo* callback function updates the contents of the error source descriptor structure so that it accurately represents the error source as it is implemented by the hardware platform.

## See also

[GetAllErrorSources](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_all_error_sources)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)