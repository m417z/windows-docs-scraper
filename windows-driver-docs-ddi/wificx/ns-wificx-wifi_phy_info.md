## Description

The **WIFI_PHY_INFO** structure contains PHY information.

## Members

### `PhyType`

An [**WDI_PHY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_phy_type) enum that specifies the PHY type.

### `NumberDataRateEntries`

The number of data rate entries.

### `DataRateList`

An array of [**WDI_DATA_RATE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ns-dot11wificxtypes-wdi_data_rate_entry) structures.

## Remarks

**WIFI_PHY_INFO** is a member of the [**WIFI_PHY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_phy_capabilities) structure.

## See also

[**WDI_PHY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_phy_type)

[**WIFI_PHY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_phy_capabilities)

[**WDI_DATA_RATE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ns-dot11wificxtypes-wdi_data_rate_entry)