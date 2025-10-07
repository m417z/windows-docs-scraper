# DOT11_PHY_TYPE enumeration

The **DOT11_PHY_TYPE** enumeration defines an 802.11 PHY and media type.

## Constants

**dot11\_phy\_type\_unknown**

Specifies an unknown or uninitialized PHY type.

**dot11\_phy\_type\_any**

Specifies any PHY type.

**dot11\_phy\_type\_fhss**

Specifies a frequency-hopping spread-spectrum (FHSS) PHY. Bluetooth devices can use FHSS or an adaptation of FHSS.

**dot11\_phy\_type\_dsss**

Specifies a direct sequence spread spectrum (DSSS) PHY type.

**dot11\_phy\_type\_irbaseband**

Specifies an infrared (IR) baseband PHY type.

**dot11\_phy\_type\_ofdm**

Specifies an orthogonal frequency division multiplexing (OFDM) PHY type. 802.11a devices can use OFDM.

**dot11\_phy\_type\_hrdsss**

Specifies a high-rate DSSS (HRDSSS) PHY type. 802.11b devices can use HRDSS.

**dot11\_phy\_type\_erp**

Specifies an extended rate PHY type (ERP). 802.11g devices can use ERP.

**dot11\_phy\_type\_ht**

Specifies a High Throughput PHY type (HT). 802.11n devices can use HT.

**dot11\_phy\_type\_vht**

Specifies the 802.11ac PHY type. This is the very high throughput PHY type specified in IEEE 802.11ac.
This value is supported on Windows 8.1, Windows Server 2012 R2, and later.

**dot11\_phy\_type\_dmg**

Specifies a Directional Multi-Gigabit PHY type (DMG). 802.11ad devices can use HT.

**dot11\_phy\_type\_he**

Specifies a High Efficiency PHY type (HE). 802.11ax (Wi-Fi 6) devices can use HT.

**dot11\_phy\_type\_eht**

Specifies an Extremely High Throughput PHY type (EHT). 802.11be (Wi-Fi 7) devices can use HT.

**dot11\_phy\_type\_IHV\_start**

Specifies the start of the range that is used to define PHY types that are developed by an independent hardware vendor (IHV).

**dot11\_phy\_type\_IHV\_end**

Specifies the start of the range that is used to define PHY types that are developed by an independent hardware vendor (IHV).

## Remarks

An IHV can assign a value for its proprietary PHY types from **dot11\_phy\_type\_IHV\_start** through **dot11\_phy\_type\_IHV\_end**. The IHV must assign a unique number from this range for each of its proprietary PHY types.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows XP with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Redistributable<br> | Wireless LAN API for Windows XP with SP2<br> |
| Header<br> | Windot11.h |

## See also

[**WLAN_ASSOCIATION_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_association_attributes)

[**WLAN_INTERFACE_CAPABILITY**](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_interface_capability)