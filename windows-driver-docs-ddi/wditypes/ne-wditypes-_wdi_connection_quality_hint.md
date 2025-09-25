# _WDI_CONNECTION_QUALITY_HINT enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_CONNECTION_QUALITY_HINT enumeration defines the Wi-Fi connection quality hints.

## Constants

### `WDI_CONNECTION_QUALITY_AUTO_POWER_SAVE`

This hint indicates that the host has no specific preference for the usage of this port. The port should use power saving mechanisms when possible, as well as when other ports require a larger share of bandwidth/radio time. It can be enabled simultaneously on more than one port. This is the default Connection Quality setting for a port.

### `WDI_CONNECTION_QUALITY_LOW_LATENCY`

This hint indicates that the host wants to use this port for low latency operations. The adapter should provide service to this port at a regular interval.

The WLAN schedule should be such that one-way latency is no more than 30ms, packet loss is \<=0.5%, and no more than 3 consecutive packets are lost. It should also honor the off-channel latency requirements specified.

This can be set simultaneously on two ports. If the ports are on different channels, the max latency is relaxed to 50ms. This is based on Windows Certification Program requirements.

When in this mode, the port can (optionally) use power saving as long as it can meet the above latency requirements. Additionally, when a port is in this mode, the adapter should avoid unnecessary scans. If the adapter needs to perform scans that are not triggered by Microsoft components, it should optimize the scan to meet the requirements of the off-channel time. For this, it can limit the scan to a single off channel at a time.

When a port is in this mode, during roaming the adapter should optimize the AP selection (for example, using different link quality thresholds to not scan or roam too often), the association process (for example, by using cached TSF for synchronization), and security exchange (for example, being more aggressive about using PMKIDs).

### `WDI_CONNECTION_QUALITY_HIGH_THROUGHPUT`

This hint indicates that the host is performing an operation on the port which is not tolerant to packet loss. The adapter should not power save and should remain on the given port’s operational channel for as long as possible without losing link connectivity on other ports, until this connection quality hint is unset.

This may be set due to L2 protocol (EAP/4-way handshake exchanges/etc), L3 protocol (DHCP/etc.), or other scenarios where high channel availability is important to the overall experience.

This can only be set on one port.

### `WDI_CONNECTION_QUALITY_NO_POWER_SAVE`

This hint indicates that the host does not want the adapter to perform any power saving. There are not specific requirements for data path performance.