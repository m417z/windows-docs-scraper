## Description

The **WIFI_BAND_INFO** structure contains band information.

## Members

### `BandID`

A [**WDI_BAND_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_band_id) structure that represents this band ID.

### `BandState`

Specifies whether this band is enabled or not.

### `NumValidPhyTypes`

The number of valid PHY types in this band.

### `ValidPhyTypeList`

A pointer to a list of valid PHY types in this band, defined by the [**WDI_PHY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_phy_type) enum.

### `NumValidChannelTypes`

The number of valid channel types in this band.

### `ValidChannelTypes`

A pointer to a list of valid channel numbers in this band formatted as [**WDI_CHANNEL_MAPPING_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ns-dot11wificxtypes-wdi_channel_mapping_entry) structures.

### `NumChannelWidths`

The number of channel widths.

### `ChannelWidthList`

A pointer to a list of channel widths in MHz.

## Remarks

**WIFI_BAND_INFO** is a member of the [**WIFI_BAND_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_capabilities) structure.

## See also

[**WIFI_BAND_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_capabilities)