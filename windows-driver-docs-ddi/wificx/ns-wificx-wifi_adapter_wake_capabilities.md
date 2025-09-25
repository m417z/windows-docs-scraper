## Description

The **WIFI_ADAPTER_WAKE_CAPABILITIES** structure describes a WiFiCx network adapter's wake-on-LAN (WoL) capabilities.

## Members

### `Size`

The size of this structure, in bytes.

### `NloDiscovery`

A boolean value indicating if the net adapter can generate wake-up events due to NLO discovery.

### `ApAssociationLost`

A boolean value indicating if the net adapter can generate wake-up events when access point association is lost.

### `GtkHandshakeError`

A boolean value indicating if the net adapter can generate wake-up events when there is a GTK handshake error.

### `FourWayHandshakeRequest`

A boolean value indicating if the net adapter can generate wake-up events when it receives a 4-Way Handshake request.

### `IncomingActionFrame`

A boolean value indicating if the net adapter can generate wake-up events upon receiving action frames.

### `ClientDriverDiagnostic`

A boolean value indicating if the net adapter can generate wake-up events triggered by client driver diagnostic events.

## Remarks

Call [**WIFI_ADAPTER_WAKE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_adapter_wake_capabilities_init) to initialize this structure. An initialized **WIFI_ADAPTER_WAKE_CAPABILITIES** structure is passed as an input method to [**WifiAdapterSetWakeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadaptersetwakecapabilities).

## See also

[**WIFI_ADAPTER_WAKE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_adapter_wake_capabilities_init)

[**WifiAdapterSetWakeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadaptersetwakecapabilities)