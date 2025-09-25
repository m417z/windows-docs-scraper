# _WDI_PHY_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_PHY_TYPE enumeration defines the PHY types.

## Constants

### `WDI_PHY_TYPE_UNKNOWN:0`

Specifies an unknown or uninitialized PHY type.

### `WDI_PHY_TYPE_ANY:0`

Specifies an unknown or uninitialized PHY type.

### `WDI_PHY_TYPE_FHSS:1`

Specifies a frequency-hopping spread-spectrum (FHSS) PHY.

### `WDI_PHY_TYPE_DSSS:2`

Specifies a direct sequence spread spectrum (DSSS) PHY.

### `WDI_PHY_TYPE_IRBASEBAND:3`

Specifies an infrared (IR) baseband PHY.

### `WDI_PHY_TYPE_OFDM:4`

Specifies an orthogonal frequency division multiplexing (OFDM) 802.11a PHY.

### `WDI_PHY_TYPE_HRDSSS:5`

Specifies a high-rate DSSS (HRDSSS) 802.11b PHY.

### `WDI_PHY_TYPE_ERP:6`

Specifies an extended-rate 802.11g PHY (ERP).

### `WDI_PHY_TYPE_HT:7`

Specifies a high-throughput (HT) 802.11n PHY. Each 802.11n PHY, whether dual-band or not, is specified as this PHY type.

### `WDI_PHY_TYPE_VHT:8`

Specifies a very high-throughput (VHT) 802.11ac PHY.

### `WDI_PHY_TYPE_DMG:9`

Added in Windows 10, version 1607, WDI version 1.0.21.

Specifies a Directional Multi-Gigabit (DMG) 802.11ad PHY.

### `WDI_PHY_TYPE_HE:10`

Added in Windows 10, version 1809. WDI version 1.1.7.

Specifies a High-Efficiency (HE) 802.11ax PHY.

### `WDI_PHY_TYPE_EHT:11`

Specifies an extremely high-throughput (EHT) 802.11be PHY.

### `WDI_PHY_TYPE_IHV_START:0x80000000`

Specifies the start of the range that is used to define proprietary PHY types that are developed by an independent hardware vendor (IHV).

### `WDI_PHY_TYPE_IHV_END:0xffffffff`

Specifies the end of the range that is used to define proprietary PHY types that are developed by an IHV.