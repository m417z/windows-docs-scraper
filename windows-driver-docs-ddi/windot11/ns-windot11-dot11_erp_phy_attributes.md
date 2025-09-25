# DOT11_ERP_PHY_ATTRIBUTES structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ERP_PHY_ATTRIBUTES structure defines the attributes specific to an extended-rate PHY (ERP)
type.

## Members

### `HRDSSSAttributes`

Since the ERP PHY type is a superset of the high-rate direct-sequence spread spectrum (HRDSS) PHY
type, the start of the DOT11_ERP_PHY_ATTRIBUTES structure is formatted as a
[DOT11_HRDSSS_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_hrdsss_phy_attributes) structure in order to define the HRDSS-specific attributes of the
PHY.

### `bERPPBCCOptionImplemented`

A Boolean value that, if set to **TRUE**, specifies that the PHY supports enabled packet binary
convolutional code (PBCC) modulation.

For more information about PBCC modulation, refer to Clause 18.4.6.6 of the IEEE 802.11b-1999
standard. For more information about the ERP-PBCC option, refer to Clause 19.6 of the IEEE 802.11g-2003
standard.

### `bDSSSOFDMOptionImplemented`

A Boolean value that, if set to **TRUE**, specifies the PHY has enabled the use of the hybrid
DSSS-OFDM modulation. If the 802.11 station supports this option, the PHY is capable of combining the
direct-sequence spread spectrum (DSSS) preamble and header with the orthogonal frequency division
multiplexing (OFDM) payload.

For more information about DSSS-OFDM modulation, refer to Clause 19.7 of the IEEE 802.11g-2003
standard.

### `bShortSlotTimeOptionImplemented`

A Boolean value that, if set to **TRUE**, specifies the PHY supports the 802.11g short slot time
option. For more information about the short slot time, refer to Clause 7.3.1.4 of the IEEE 802.11g-2003
standard.

## Syntax

```cpp
typedef struct DOT11_ERP_PHY_ATTRIBUTES {
  DOT11_HRDSSS_PHY_ATTRIBUTES HRDSSSAttributes;
  BOOLEAN                     bERPPBCCOptionImplemented;
  BOOLEAN                     bDSSSOFDMOptionImplemented;
  BOOLEAN                     bShortSlotTimeOptionImplemented;
} DOT11_ERP_PHY_ATTRIBUTES, *PDOT11_ERP_PHY_ATTRIBUTES;
```

## Remarks

The miniport driver defines the attributes of a PHY on the 802.11 station through the
[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes) structure, and
formats the
**ERPAttributes** member as a DOT11_ERP_PHY_ATTRIBUTES structure. The driver must only do this if the
PHY defined by the DOT11_PHY_ATTRIBUTES structure is an ERP PHY type.

## See also

[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes)

[DOT11_HRDSSS_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_hrdsss_phy_attributes)