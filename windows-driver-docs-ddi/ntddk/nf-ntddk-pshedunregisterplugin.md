# PshedUnregisterPlugin function

## Description

When registering a V2 plugin (**WHEA_PLUGIN_REGISTRATION_PACKET_V2**) this interface allows the plugin to unregister from the system so the driver can be stopped.

## Parameters

### `PluginHandle`

Specifies the plugin to unload. Use the [PluginHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_pshed_plugin_registration_packet_v2) that the packet contains after registering a V2 plugin.

## Return value

This function returns NTPSHEDAPI VOID.

## Remarks

## See also