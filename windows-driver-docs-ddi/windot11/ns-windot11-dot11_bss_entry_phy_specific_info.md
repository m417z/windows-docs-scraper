# DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO structure

## Description

> [!IMPORTANT]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO union specifies the attributes of the PHY which received an IEEE 802.11 Beacon or Response Frame during the Native 802.11 miniport driver's last scan operation.

## Members

### `uChCenterFrequency`

The channel center frequency of the band on which the 802.11 Probe-Response or Beacon frame was received. The value of **uChCenterFrequency** is in units of megahertz (MHz).

> [!NOTE]
> This member is only valid for PHY types that are not frequency-hopping spread spectrum (FHSS).

### `FHSS`

The FHSS parameters, as specified by the following members:

### `FHSS.uHopPattern`

The current hopping pattern used by the layer management entity (LME) of the PHY to determine the hopping sequence. For more information about how the hopping sequence is determined, refer to Clause 14.9.2.20 of the IEEE 802.11-2012 standard.

> [!NOTE]
> This member is only valid for FHSS PHY types.

### `FHSS.uHopSet`

The current set of patterns used by the LME of the PHY to determine the hopping sequence. For more information about the hopping pattern sets, refer to Clause 14.9.2.19 of the IEEE 802.11-2012 standard.

> [!NOTE]
> This member is only valid for FHSS PHY types.

### `FHSS.uDwellTime`

The maximum amount of time that the PHY can use when transmitting on a single channel. The value of **uDwellTime** is in units of 802.11 time units (TU). One TU is 1024 microseconds.

> [!NOTE]
> This member is only valid for FHSS PHY types.

## Syntax

```cpp
typedef union DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO {
  ULONG  uChCenterFrequency;
  struct {
    ULONG uHopPattern;
    ULONG uHopSet;
    ULONG uDwellTime;
  } FHSS;
} DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO, *PDOT11_BSS_ENTRY_PHY_SPECIFIC_INFO;
```

## Remarks

The DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO union is a member of the [DOT11_BSS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry) structure.

## See also

[DOT11_BSS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry)