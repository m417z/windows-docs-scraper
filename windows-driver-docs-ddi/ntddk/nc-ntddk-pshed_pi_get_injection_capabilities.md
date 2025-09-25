## Description

A PSHED plug-in's *GetInjectionCapabilities* callback function returns an error injection capabilities union that describes the types of hardware errors that can be injected into the hardware platform.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `Capabilities` [out]

A pointer to a [**WHEA_ERROR_INJECTION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_injection_capabilities) union. This union receives the data that describes the types of hardware errors that can be injected into the hardware platform.

## Return value

A PSHED plug-in's *GetInjectionCapabilities* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The data that describes the types of hardware errors that can be injected into the hardware platform was successfully returned in the **WHEA_ERROR_INJECTION_CAPABILITIES** union pointed to by the *Capabilities* parameter. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error injection sets the **Callbacks.GetInjectionCapabilities** and **Callbacks.InjectError** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its *GetInjectionCapabilities* and [InjectError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_inject_error) callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorInjection** flag in the **FunctionalAreaMask** member of the **WHEA_PSHED_PLUGIN_REGISTRATION_PACKET** structure.

The Windows kernel calls into the PSHED to retrieve information about the types of hardware errors that can be injected into the hardware platform in response to an error injection capabilities inquiry by a WHEA management application. If a PSHED plug-in is registered to participate in error injection, the PSHED calls the PSHED plug-in's *GetInjectionCapabilities* callback function to retrieve information about additional types of hardware errors that can be injected into the hardware platform.

## See also

[InjectError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_inject_error)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[**WHEA_ERROR_INJECTION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_injection_capabilities)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)