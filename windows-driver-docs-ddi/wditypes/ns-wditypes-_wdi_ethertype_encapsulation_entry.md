# _WDI_ETHERTYPE_ENCAPSULATION_ENTRY structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
WDI_ETHERTYPE_ENCAPSULATION_ENTRY structure defines an EtherType encapsulation entry.

## Members

### `EtherType`

The value of the IEEE EtherType in big-endian byte order.

### `EncapsulationType`

The type of encapsulation to be performed on the specified EtherType.