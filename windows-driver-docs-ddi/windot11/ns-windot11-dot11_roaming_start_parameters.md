# DOT11_ROAMING_START_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ROAMING_START_PARAMETERS structure specifies the reason why the Native 802.11 miniport
driver is performing a roaming operation. The driver includes a DOT11_ROAMING_START_PARAMETERS structure
when the driver makes an
[NDIS_STATUS_DOT11_ROAMING_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-roaming-start) status indication.

## Members

### `Header`

The type, revision, and size of the DOT11_ROAMING_START_PARAMETERS structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_ROAMING_START_PARAMETERS_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_ROAMING_START_PARAMETERS).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `AdhocBSSID`

If the IEEE 802.11
**dot11DesiredBSSType** MIB object is set to
**dot11_BSS_type_independent**, the
**AdhocBSSID** member contains the basic service set (BSS) identifier (BSSID) of the independent BSS
(IBSS) network that the 802.11 station is attempting to roam to.

**Note** IBSS (Ad hoc) and SoftAP are deprecated. Starting with Windows 8.1 and Windows Server 2012 R2, use [Wi-Fi Direct](https://learn.microsoft.com/windows-hardware/drivers/partnerapps/wi-fi-direct).

If the
**dot11DesiredBSSType** MIB object is set to
**dot11_BSS_type_infrastructure**, the miniport driver must fill
**AdhocBSSID** with zeros.

For more information about the data type for this member, see
[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address).

### `AdhocSSID`

If the
**dot11DesiredBSSType** MIB object is set to
**dot11_BSS_type_independent**, the
**AdhocSSID** member contains the service set identifier (SSID) of the IBSS network that the 802.11
station is attempting to roam to.

**Note** IBSS (Ad hoc) and SoftAP are deprecated. Starting with Windows 8.1 and Windows Server 2012 R2, use [Wi-Fi Direct](https://learn.microsoft.com/windows-hardware/drivers/partnerapps/wi-fi-direct).

If the
**dot11DesiredBSSType** MIB object is set to
**dot11_BSS_type_infrastructure**, the miniport driver must fill
**AdhocSSID** with zeros.

For more information about the data type for this member, see
[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid).

For more information about the IEEE 802.11
**dot11DesiredBSSType** MIB object, see
[OID_DOT11_DESIRED_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bss-type).

### `uRoamingReason`

The reason that the 802.11 station is roaming, which is formatted as a
[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes) value.

## Syntax

```cpp
typedef struct DOT11_ROAMING_START_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  AdhocBSSID;
  DOT11_SSID         AdhocSSID;
  DOT11_ASSOC_STATUS uRoamingReason;
} DOT11_ROAMING_START_PARAMETERS, *PDOT11_ROAMING_START_PARAMETERS;
```

## Remarks

For more information about the roaming operation, see
[Roaming Operations](https://learn.microsoft.com/windows-hardware/drivers/network/roaming-operations).

## See also

[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes)

[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid)

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address)

[OID_DOT11_DESIRED_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bss-type)

[NDIS_STATUS_DOT11_ROAMING_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-roaming-start)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)