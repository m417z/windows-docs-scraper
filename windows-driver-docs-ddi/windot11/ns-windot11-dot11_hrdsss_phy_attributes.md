# DOT11_HRDSSS_PHY_ATTRIBUTES structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_HRDSSS_PHY_ATTRIBUTES structure defines the attributes specific to a high-rate
direct-sequence spread spectrum (HRDSS) PHY type.

## Members

### `bShortPreambleOptionImplemented`

A Boolean value that, if set to **TRUE**, specifies that the PHY supports the option to enable the
short Physical Layer Convergence Procedure (PLCP) preamble and header. For more information about the
short PLCP preamble and header, refer to Clause 18.2.2.2 of the IEEE 802.11b-1999 standard

### `bPBCCOptionImplemented`

A Boolean value that, if set to **TRUE**, specifies that the PHY supports enabled packet binary
convolutional code (PBCC) modulation. For more information about PBCC modulation, refer to Clause
18.4.6.6 of the IEEE 802.11b-1999 standard.

### `bChannelAgilityPresent`

A Boolean value that, if set to **TRUE**, specifies that the PHY supports channel agility. For more
information about channel agility, refer to Clause 18 of the IEEE 802.11b-1999 standard and Clause 19 of
the IEEE 802.11g-2003 standard.

### `uHRCCAModeSupported`

The type of clear channel assessment (CCA) mode supported by the current PHY type. For more
information about CCA, refer to Clause 16.4.8.5 of the IEEE 802.11-2012 standard and Clause 18.4.8.4 of
the IEEE 802.11b-1999 standard.

The CCA modes supported by the PHY are defined through the following bitmask:

#### DOT11_CCA_MODE_ED_ONLY (0x00000001)

CCA mode using the energy detect (ED) signal. For more information about the ED signal, refer to
Clause 15.4.6.1 of the IEEE 802.11-2012 standard.

#### DOT11_CCA_MODE_CS_ONLY (0x00000002)

CCA mode using the carrier sense (CS) signal. For more information about the CS signal, refer to
Clause 15.4.6.2 of the IEEE 802.11-2012 standard.

#### DOT11_CCA_MODE_ED_and_CS (0x00000004)

Both ED and CS modes.

#### DOT11_HR_CCA_MODE_CS_WITH_TIMER (0x00000008)

CCA mode using the CS signal with a timer. For more information about this CCA mode, refer to
Clause 18.4.8.4 of the IEEE 802.11b-1999 standard.

#### DOT11_HR_CCA_MODE_HRCS_AND_ED (0x00000010)

Both ED and CS modes on high-rate (HR) PHYs. For more information about this CCA mode, refer to
Clause 18.4.8.4 of the IEEE 802.11b-1999 standard.

## Syntax

```cpp
typedef struct DOT11_HRDSSS_PHY_ATTRIBUTES {
  BOOLEAN bShortPreambleOptionImplemented;
  BOOLEAN bPBCCOptionImplemented;
  BOOLEAN bChannelAgilityPresent;
  ULONG   uHRCCAModeSupported;
} DOT11_HRDSSS_PHY_ATTRIBUTES, *PDOT11_HRDSSS_PHY_ATTRIBUTES;
```

## Remarks

The miniport driver defines the attributes of a PHY on the 802.11 station through the
[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes) structure, and
formats the
**HRDSSSAttributes** member as a DOT11_HRDSSS_PHY_ATTRIBUTES structure. The driver must only do this if
the PHY defined by the DOT11_PHY_ATTRIBUTES structure is an HRDSSS PHY type.

## See also

[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes)