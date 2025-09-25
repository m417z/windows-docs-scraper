# PshedRegisterPlugin function

## Description

The **PshedRegisterPlugin** function registers a PSHED plug-in with the PSHED.

## Parameters

### `Packet` [in, out]

A pointer to an initialized [WHEA_PSHED_PLUGIN_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure that describes the PSHED plug-in's registration information.

## Return value

**PshedRegisterPlugin** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The PSHED plug-in was successfully registered. |
| **STATUS_INVALID_PARAMETER** | The data in the supplied registration packet is invalid. |

## Remarks

A PSHED plug-in calls the **PshedRegisterPlugin** function to register itself with the PSHED. A PSHED plug-in typically calls this function from within either its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function or its [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) function.

Starting in Windows 10, version 1903 (WDK 10 version 18362), a V2 of the PSHED-Plugin interfaces is available that allows a plugin to be removed and updated on a running system by calling the PshedUnregisterPlugin function. Because they can be unregistered, V2 plugins cannot specify the PshedFADiscovery flag (discovery functional area) in the FunctionalAreaMask member of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V2 structure. For info about registering a plug-in, see Registering a PSHED Plug-In. For a V1 plugin, if you try to unregister, a bugcheck may occur. It is recommended that you use a V2 plugin if possible, which is the current default.

To register a V1 vs a V2 plugin, use the correct struct. [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_pshed_plugin_registration_packet_v1) for V1 and [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_pshed_plugin_registration_packet_v2) for V2.

A V2 plugin can still add error sources as described in [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10), or by calling [**WheaAddErrorSource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsource) and [**WheaRemoveErrorSource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-whearemoveerrorsource).

A plugin may continue to use the discovery functional area by specifying **WHEA_PLUGIN_REGISTRATION_PACKET_V1** as the version of its [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_pshed_plugin_registration_packet_v2) structure.

All callbacks, on both V1 and V2 plugins, are called at a minimum IRQL of DISPATCH_LEVEL.

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[WHEA_PSHED_PLUGIN_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)