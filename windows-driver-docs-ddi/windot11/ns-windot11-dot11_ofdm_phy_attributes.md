# DOT11_OFDM_PHY_ATTRIBUTES structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_OFDM_PHY_ATTRIBUTES structure defines the attributes specific to an orthogonal frequency
division multiplexing (OFDM) PHY type.

## Members

### `uFrequencyBandsSupported`

The frequency bands in which the PHY is capable of operating. Frequency bands are defined for:

* Unlicensed national information infrastructure (U-NII) bands.
* Conference of European Post and Telecommunication (CEPT) bands.
* Japan 5 GHz bands.

The frequency bands supported by the PHY are defined through the following bitmask:

| Bit | Description |
| --- | --- |
| 0 | Can operate in the lower (5.15-5.25 GHz) U-NII band. |
| 1 | Can operate in the middle (5.25-5.35 GHz) U-NII band. |
| 2 | Can operate in the upper (5.725-5.825 GHz) U-NII band. |
| 3 | Can operate in CEPT B (5.47-5.7253 GHz) band. |
| 4 | Can operate in the lower Japan (5.15-5 5.25 GHz) band. |
| 5 | Can operate in the Japan 5.0 (5.03-8 5.091 GHz) band. |
| 6 | Can operate in the Japan 4.9 (4.9-5.0GHz) band. |

## Syntax

```cpp
typedef struct DOT11_OFDM_PHY_ATTRIBUTES {
  ULONG uFrequencyBandsSupported;
} DOT11_OFDM_PHY_ATTRIBUTES, *PDOT11_OFDM_PHY_ATTRIBUTES;
```

## Remarks

The miniport driver defines the attributes of a PHY on the 802.11 station through the
[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes) structure, and
formats the
**OFDMAttributes** member as a DOT11_OFDM_PHY_ATTRIBUTES structure. The miniport driver must only do this
if the PHY defined by the DOT11_PHY_ATTRIBUTES structure is an OFDM PHY type.

## See also

[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes)