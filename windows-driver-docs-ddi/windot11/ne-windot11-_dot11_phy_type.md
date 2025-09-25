# _DOT11_PHY_TYPE enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PHY_TYPE enumeration defines an 802.11 PHY and media type.

## Constants

### `dot11_phy_type_unknown:0`

Specifies an unknown or uninitialized PHY type.

### `dot11_phy_type_any:dot11_phy_type_unknown`

Specifies an unknown or uninitialized PHY type.

### `dot11_phy_type_fhss:1`

Specifies a frequency-hopping spread-spectrum (FHSS) PHY.

### `dot11_phy_type_dsss:2`

Specifies a direct sequence spread spectrum (DSSS) PHY.

### `dot11_phy_type_irbaseband:3`

Specifies an infrared (IR) baseband PHY.

### `dot11_phy_type_ofdm:4`

Specifies an orthogonal frequency division multiplexing (OFDM) 802.11a PHY.

### `dot11_phy_type_hrdsss:5`

Specifies a high-rate DSSS (HRDSSS) 802.11b PHY.

### `dot11_phy_type_erp:6`

Specifies an extended-rate 802.11g PHY (ERP).

### `dot11_phy_type_ht:7`

Specifies a high-throughput (HT) 802.11n PHY. Each 802.11n PHY, whether dual-band or not, is
specified as this PHY type.

### `dot11_phy_type_vht:8`

Specifies a very high-throughput (VHT) 802.11ac PHY.

### `dot11_phy_type_dmg:9`

Specifies a Directional Multi-Gigabit (DMG) 802.11ad PHY.

### `dot11_phy_type_he:10`

Specifies a High Efficiency (HE) 802.11ax PHY.

### `dot11_phy_type_eht:11`

Specifies an extremely high-throughput (EHT) 802.11be PHY.

### `dot11_phy_type_IHV_start:0x80000000`

Specifies the start of the range that is used to define proprietary PHY types that are developed
by an independent hardware vendor (IHV).

The **dot11\_phy\_type\_IHV\_start** enumerator value is valid only when the miniport driver is operating in Extensible Station (ExtSTA) mode.

### `dot11_phy_type_IHV_end:0xffffffff`

Specifies the end of the range that is used to define proprietary PHY types that are developed by
an IHV.

The **dot11\_phy\_type\_IHV\_end** enumerator value is valid only when the miniport driver is operating in ExtSTA mode.

## Remarks

An IHV can assign a value for its proprietary PHY types from **dot11\_phy\_type\_IHV\_start** through **dot11\_phy\_type\_IHV\_end**. The IHV must assign a unique number from this range for each of its proprietary PHY types.

## See also

[OID\_DOT11\_RECV\_SENSITIVITY\_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-recv-sensitivity-list)

[OID\_DOT11\_SUPPORTED\_PHY\_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types)

[ DOT11\_ASSOCIATION\_COMPLETION\_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters)

[OID\_DOT11\_SCAN\_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)