## Description

A PSHED plug-in's *InjectError* callback function injects an error into the hardware platform.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `ErrorType` [in]

The type of error to be injected into the hardware platform. Possible values are:

#### INJECT_ERRTYPE_PROCESSOR_CORRECTABLE

A correctable processor error.

#### INJECT_ERRTYPE_PROCESSOR_UNCORRECTABLENONFATAL

An uncorrectable nonfatal processor error.

#### INJECT_ERRTYPE_PROCESSOR_UNCORRECTABLEFATAL

An uncorrectable fatal processor error.

#### INJECT_ERRTYPE_MEMORY_CORRECTABLE

A correctable memory error.

#### INJECT_ERRTYPE_MEMORY_UNCORRECTABLENONFATAL

An uncorrectable nonfatal memory error.

#### INJECT_ERRTYPE_MEMORY_UNCORRECTABLEFATAL

An uncorrectable fatal memory error.

#### INJECT_ERRTYPE_PCIEXPRESS_CORRECTABLE

A correctable PCI Express error.

#### INJECT_ERRTYPE_PCIEXPRESS_UNCORRECTABLENONFATAL

An uncorrectable nonfatal PCI Express error.

#### INJECT_ERRTYPE_PCIEXPRESS_UNCORRECTABLEFATAL

An uncorrectable fatal PCI Express error.

#### INJECT_ERRTYPE_PLATFORM_CORRECTABLE

A correctable platform error.

#### INJECT_ERRTYPE_PLATFORM_UNCORRECTABLENONFATAL

An uncorrectable nonfatal platform error.

#### INJECT_ERRTYPE_PLATFORM_UNCORRECTABLEFATAL

An uncorrectable fatal platform error.

### `Parameter1` [in]

A generic parameter that contains additional data that is passed by the WHEA management application that is injecting the error.

### `Parameter2` [in]

A generic parameter that contains additional data that is passed by the WHEA management application that is injecting the error.

### `Parameter3` [in]

A generic parameter that contains additional data that is passed by the WHEA management application that is injecting the error.

### `Parameter4` [in]

A generic parameter that contains additional data that is passed by the WHEA management application that is injecting the error.

## Return value

A PSHED plug-in's *InjectError* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The error was successfully injected into the hardware platform. |
| **STATUS_UNSUCCESSFUL** | An error occurred. For injected errors that are fatal or otherwise unrecoverable, this callback function might not return before the operating system generates a bug check in response to the error condition. |

## Remarks

A PSHED plug-in that participates in error injection sets the **Callbacks.GetInjectionCapabilities** and **Callbacks.InjectError** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its [GetInjectionCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_injection_capabilities) and *InjectError* callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorInjection** flag in the **FunctionalAreaMask** member of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET structure.

When a WHEA management application makes a request to inject a hardware error, the Windows kernel calls into the PSHED to inject the error into the hardware platform. If a PSHED plug-in is registered to participate in error injection, the PSHED calls the PSHED plug-in's *InjectError* callback function to perform the error injection operation.

The WHEA management application that is injecting the error can pass additional error-specific data to the PSHED plug-in's *InjectError* callback function by using parameters *Parameter1* through *Parameter4*. For example, on Itanium-based systems, some of the error injection operations require an accompanying address. In this situation, the WHEA management application can pass the address to the PSHED plug-in's *InjectError* callback function using one of these parameters.

## See also

[GetInjectionCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_injection_capabilities)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)