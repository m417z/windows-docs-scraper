## Description

The **WifiExtensionGetExemptionAction** function retrieves the exemption action information for a packet.

## Parameters

### `Extension`

A pointer to a [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) structure that describes the exemption action information for this packet queue.

### `Index`

The index in the packet ring for the target [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Return value

Returns a pointer to a [**NET_PACKET_WIFI_EXEMPTION_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/exemptionactiontypes/ns-exemptionactiontypes-net_packet_wifi_exemption_action) structure that holds the exemption action information for this packet.

## Remarks

This function is a wrapper function around [**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata).

## See also

[**NET_PACKET_WIFI_EXEMPTION_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/exemptionactiontypes/ns-exemptionactiontypes-net_packet_wifi_exemption_action)

[**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata)