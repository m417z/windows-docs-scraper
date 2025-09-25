# DOT11_VWIFI_ATTRIBUTES structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_VWIFI_ATTRIBUTES structure defines the virtualization attributes of the miniport driver and
802.11 station when operating in Virtual WiFi mode.

## Members

### `Header`

The type, revision, and size of the DOT11_VWIFI_ATTRIBUTES structure. This member is formatted as
an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_VWIFI_ATTRIBUTES_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_VWIFI_ATTRIBUTES).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `Combinations[*]`

The maximum number of entries that the
**Combinations** array can contain.

### `Combinations[1]`

The list of supported combinations of 802.11 MAC entities that an 802.11 miniport driver can
simultaneously support when it is virtualized. Each entry in this list is specified through an array of
[DOT11_VWIFI_COMBINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination), [DOT11_VWIFI_COMBINATION_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination_v2), or [DOT11_VWIFI_COMBINATION_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination_v3) structures.

## See also

[DOT11_VWIFI_COMBINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination)

[DOT11_VWIFI_COMBINATION_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination_v2)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)