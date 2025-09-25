# _DOT11_PHY_TYPE_INFO structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_PHY_TYPE_INFO structure defines parameters that the 802.11 station uses to configure a PHY when performing an explicit scan operation. The station performs the explicit scan operation following a set request of [OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request).

## Members

### `dot11PhyType`

The type of PHY that the 802.11 station will use for the scan. The PHY type is defined by the [DOT11_PHY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_phy_type) enumeration.

**Note** The miniport driver must ignore this member if it is operating in Extensible Station (ExtSTA) mode.

### `bUseParameters`

If this member is **TRUE**, the 802.11 station uses the other members of this structure to configure
the PHY for the scan operation.

If this member is **FALSE**, the 802.11 station configures the PHY using its own settings for the scan
operation.

**Note** If the miniport driver is operating in ExtSTA mode, the operating system will
always set this member to **FALSE**.

### `uProbeDelay`

The amount of time, in microseconds, that the 802.11 station must wait before transmitting an
802.11 Probe Request frame during active scanning.

### `uMinChannelTime`

The minimum amount of time, in 802.11 time units (TU), that the 802.11 station spends on each
channel when scanning. One TU is 1024 microseconds.

This member must be greater than or equal to
**uProbeDelay** .

### `uMaxChannelTime`

The maximum amount of time, in 802.11 time units (TU), that the 802.11 station spends on each
channel when scanning.

This member must be greater than or equal to
**uProbeDelay** .

### `ChDescriptionType`

This member specifies the method used to interpret the entries in the
**ucChannelListBuffer** array. The data type for this member is the CH_DESCRIPTION_TYPE enumeration,
which declares the following values:

#### ch_description_type_logical

The channel entry is defined by a logical channel number to conform with the IEEE 802.11
standard.

#### ch_description_type_center_frequency

The channel entry is defined, in units of megahertz (MHz), by a channel center frequency.

### `uChannelListSize`

The length, in bytes, of the
**ucChannelListBuffer** array. Each entry in this array is formatted as a ULONG data type.

### `ucChannelListBuffer[1]`

An array containing channel descriptions for the PHY type specified in the
**dot11PhyType** member.

### `uPhyId`

The identifier (ID) of the PHY that the 802.11 station will use for the scan. The PHY ID is the
index within the list of supported PHYs returned by the driver through a query of
[OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types).

**Note** The miniport driver must ignore this member if it is operating in ExtSTA
mode.

## Syntax

```cpp
typedef struct _DOT11_PHY_TYPE_INFO {
  union {
    DOT11_PHY_TYPE dot11PhyType;
    ULONG          uPhyId;
  };
  BOOLEAN             bUseParameters;
  ULONG               uProbeDelay;
  ULONG               uMinChannelTime;
  ULONG               uMaxChannelTime;
  CH_DESCRIPTION_TYPE ChDescriptionType;
  ULONG               uChannelListSize;
  UCHAR               ucChannelListBuffer[1];
} DOT11_PHY_TYPE_INFO, *PDOT11_PHY_TYPE_INFO;
```

## Remarks

The
[DOT11_SCAN_REQUEST_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_scan_request_v2) structure, which
accompanies a set request of
[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request), contains an
array of zero or more DOT11_PHY_TYPE_INFO entries.

For more information about the scan operations performed by a Native 802.11 miniport driver, see
[Native 802.11 Scan
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-scan-operations).

For more information about the ExtSTA operation mode, see
[Extensible Station Operation
Mode](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-operation-mode).

## See also

[DOT11_SCAN_REQUEST_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_scan_request_v2)

[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)