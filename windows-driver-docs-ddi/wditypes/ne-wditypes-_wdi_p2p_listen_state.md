# _WDI_P2P_LISTEN_STATE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_P2P_LISTEN_STATE enumeration defines the Wi-Fi Direct listen states.

## Constants

### `WDI_P2P_LISTEN_STATE_OFF`

When this listen state is set:

* The port shall not schedule any time to explicitly listen on social channels for incoming Wi-Fi Direct action frames.
* The port shall not respond to probe requests as a Wi-Fi Direct Adapter.

### `WDI_P2P_LISTEN_STATE_PASSIVE_AVAILABILITY`

When this listen state is set:

* The port must enter into listen state periodically as specified by the ListenDuration parameters.
* The port shall respond to probe requests with a "DIRECT-" SSID as a Wi-Fi Direct Adapter when parked on the specified channel.

### `WDI_P2P_LISTEN_STATE_AUTOMATIC_AVAILABILITY`

When this listen state is set:

* The port must schedule time to explicitly listen on a social channel for incoming Wi-Fi Direct action frames.
* The port shall respond to probe requests with a "DIRECT-" SSID as a Wi-Fi Direct Adapter when parked on the configured social channel.

**Note** The optimized duty cycle for automatic availability listen state is outside the scope of this specification. The most aggressive power saving schedule that may be implemented by the port is being available for a contiguous 500ms out of every 5 seconds.

### `WDI_P2P_LISTEN_STATE_HIGH_AVAILABILITY`

When this listen state is set:

* The port must schedule time to explicitly listen on a social channel for incoming Wi-Fi Direct action frames.
* The port shall respond to probe requests with a "DIRECT-" SSID as a Wi-Fi Direct Adapter when parked on the configured social channel.

**Note** The duty cycle for this listen state is 300ms availability every 400ms on the configured social channel.

### `WDI_P2P_LISTEN_STATE_DUMMY_MAX_VALUE`

The maximum value for this type.