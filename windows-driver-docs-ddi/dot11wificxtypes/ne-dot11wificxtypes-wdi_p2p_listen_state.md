## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_LISTEN_STATE** enumeration defines the Wi-Fi Direct listen states.

## Constants

### `WDI_P2P_LISTEN_STATE_OFF:0`

When this listen state is set:

* The port shall not schedule any time to explicitly listen on social channels for incoming Wi-Fi Direct action frames.
* The port shall not respond to probe requests as a Wi-Fi Direct Adapter.

### `WDI_P2P_LISTEN_STATE_PASSIVE_AVAILABILITY:8`

When this listen state is set:

* The port must enter into listen state periodically as specified by the ListenDuration parameters.
* The port shall respond to probe requests with a "DIRECT-" SSID as a Wi-Fi Direct Adapter when parked on the specified channel.

### `WDI_P2P_LISTEN_STATE_AUTOMATIC_AVAILABILITY:16`

When this listen state is set:

* The port must schedule time to explicitly listen on a social channel for incoming Wi-Fi Direct action frames.
* The port shall respond to probe requests with a "DIRECT-" SSID as a Wi-Fi Direct Adapter when parked on the configured social channel.

> [!NOTE] The optimized duty cycle for automatic availability listen state is outside the scope of this specification. The most aggressive power saving schedule that may be implemented by the port is being available for a contiguous 500ms out of every 5 seconds.

### `WDI_P2P_LISTEN_STATE_HIGH_AVAILABILITY:24`

When this listen state is set:

* The port must schedule time to explicitly listen on a social channel for incoming Wi-Fi Direct action frames.
* The port shall respond to probe requests with a "DIRECT-" SSID as a Wi-Fi Direct Adapter when parked on the configured social channel.
> [!NOTE] The duty cycle for this listen state is 300ms availability every 400ms on the configured social channel.

### `WDI_P2P_LISTEN_STATE_DUMMY_MAX_VALUE:0xFFFFFFFF`

The maximum value for this type.

## Remarks

This enumeration is a value in the [**WDI_TLV_P2P_LISTEN_STATE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-listen-state) TLV.

## See also

[**WDI_TLV_P2P_LISTEN_STATE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-listen-state)