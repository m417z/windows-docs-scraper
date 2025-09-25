## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_SERVICE_DISCOVERY_TYPE** enumeration defines the types of service discovery.

## Constants

### `WDI_P2P_SERVICE_DISCOVERY_TYPE_NO_SERVICE_DISCOVERY:1`

The adapter should only do a WFD discovery for WFD devices. It should not encode service hashes in the P2P IEs.

### `WDI_P2P_SERVICE_DISCOVERY_TYPE_SERVICE_NAME_ONLY:2`

The adapter encodes service hashes in the P2P IEs during probe requests and indicates probe responses. It does not perform any GAS queries for service information.

### `WDI_P2P_SERVICE_DISCOVERY_TYPE_SERVICE_INFORMATION:3`

The adapter encodes the service hashes in the IEs, tracks the service names from the probe responses, and does GAS queries to get service information for each responding device. This is only applicable if the adapter supports the P2P Service Information Discovery capability.

### `WDI_P2P_SERVICE_DISCOVERY_TYPE_MAX_VALUE:0xFFFFFFFF`

The maximum value for this type.

## Remarks

The **WDI_P2P_SERVICE_DISCOVERY_TYPE** enumeration is a value in the [**WDI_TLV_P2P_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-discover-mode) and [**WDI_TLV_P2P_BACKGROUND_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-background-discover-mode) TLVs.

## See also

[**WDI_TLV_P2P_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-discover-mode)

[**WDI_TLV_P2P_BACKGROUND_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-background-discover-mode)