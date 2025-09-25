# DOT11_PHY_ATTRIBUTES structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_PHY_ATTRIBUTES structure defines the physical and operating attributes of a PHY on the
802.11 station.

## Members

### `Header`

The type, revision, and size of the DOT11_PHY_ATTRIBUTES structure. This member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_PHY_ATTRIBUTES_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_PHY_ATTRIBUTES).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PhyType`

The type of the PHY as specified by a
[DOT11_PHY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_phy_type) enumerator value.

### `bHardwarePhyState`

A Boolean value that specifies the hardware power state of the PHY. If **TRUE**, the hardware power
state is enabled. If **FALSE**, the hardware power state is disabled.

For more information about the PHY's hardware power state, see
[OID_DOT11_HARDWARE_PHY_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-hardware-phy-state).

**Note** Whenever the PHY's hardware power state changes, the miniport driver must make an
[NDIS_STATUS_DOT11_PHY_STATE_CHANGED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-phy-state-changed) media-specific status indication.

### `bSoftwarePhyState`

A Boolean value that specifies the software power state of the PHY. If **TRUE**, the software power
state is enabled. If **FALSE**, the software power state is disabled.

For more information about the PHY's software power state, see
[OID_DOT11_NIC_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-nic-power-state).

**Note** Whenever the PHY's software power state changes, the miniport driver must make an
[NDIS_STATUS_DOT11_PHY_STATE_CHANGED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-phy-state-changed) media-specific status indication.

### `bCFPollable`

A Boolean value that, if set to **TRUE**, indicates that the 802.11 station supports CF-Poll frames. For
more information about CF-Poll frames, refer to Clause 9.4 of the IEEE 802.11-2012 standard.

This member is not applicable to the Extensible Access Point (ExtAP) operation mode and is ignored
when the NIC is in the ExtAP mode.

### `uMPDUMaxLength`

The maximum length, in bytes, of a media access control (MAC) protocol data unit (MPDU) frame that
the PHY can transmit or receive. For more information, see
[OID_DOT11_MPDU_MAX_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-mpdu-max-length).

**Note** Whenever the PHY's software power state changes, the miniport driver must make an
NDIS_STATUS_DOT11_MPDU_MAX_LENGTH_CHANGED media-specific status indication.

### `TempType`

The PHY's operating temperature range, defined through a
[DOT11_TEMP_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_temp_type) enumeration value.

### `DiversitySupport`

The PHY's type of antenna diversity, defined through a
[DOT11_DIVERSITY_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_diversity_support) enumeration
value.

### `DataRateMappingEntries`

An array of the data rates supported by the PHY. Each entry is formatted as a
[DOT11_DATA_RATE_MAPPING_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_data_rate_mapping_entry) structure.

### `PhySpecificAttributes`

### `PhySpecificAttributes.HRDSSSAttributes`

The PHY-specific attributes of a high-rate direct-sequence spread spectrum (HRDSS) PHY type. The
miniport driver must use this member only if the
**PhyType** member is set to dot11_phy_type_hrdsss.

### `PhySpecificAttributes.OFDMAttributes`

The PHY-specific attributes of an orthogonal frequency division multiplexing (OFDM) PHY type. The
miniport driver must use this member only if the
**PhyType** member is set to dot11_phy_type_ofdm.

### `PhySpecificAttributes.ERPAttributes`

The PHY-specific attributes of an extended-rate PHY (ERP) type. The miniport driver must use this
member only if the
**PhyType** member is set to dot11_phy_type_erp.

### `SupportedDataRatesValue`

An array of the following data rates supported by the PHY:

* The transmit data rates supported by the Physical Layer Convergence Procedure (PLCP) and Physical
  Media Dependent (PMD) sublayer of the PHY.
* The receive data rates supported by the PLCP and PMD of the PHY.

Each entry in the array is formatted as a DOT11_SUPPORTED_DATA_RATES_VALUE_V2 structure.

### `TxPowerLevels`

An array of the supported transmit power levels in units of milliwatts (mWs). Each power level must
be a value from 0 through 1000.

### `uNumDataRateMappingEntries`

The number of data rates within the
**DataRateMappingEntries** array.

### `uNumberSupportedPowerLevels`

The number of power levels within the
**TxPowerLevels** array.
**uNumOfSupportedPowerLevels** must have a value from 1 through 8.

## Syntax

```cpp
typedef struct DOT11_PHY_ATTRIBUTES {
  NDIS_OBJECT_HEADER                  Header;
  DOT11_PHY_TYPE                      PhyType;
  BOOLEAN                             bHardwarePhyState;
  BOOLEAN                             bSoftwarePhyState;
  BOOLEAN                             bCFPollable;
  ULONG                               uMPDUMaxLength;
  DOT11_TEMP_TYPE                     TempType;
  DOT11_DIVERSITY_SUPPORT             DiversitySupport;
  union {
    DOT11_HRDSSS_PHY_ATTRIBUTES HRDSSSAttributes;
    DOT11_OFDM_PHY_ATTRIBUTES   OFDMAttributes;
    DOT11_ERP_PHY_ATTRIBUTES    ERPAttributes;
  };
  ULONG                               uNumberSupportedPowerLevels;
  ULONG                               TxPowerLevels[8];
  ULONG                               uNumDataRateMappingEntries;
  DOT11_DATA_RATE_MAPPING_ENTRY       DataRateMappingEntries[DOT11_RATE_SET_MAX_LENGTH];
  DOT11_SUPPORTED_DATA_RATES_VALUE_V2 SupportedDataRatesValue;
} DOT11_PHY_ATTRIBUTES, *PDOT11_PHY_ATTRIBUTES;
```

## Remarks

The
[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_native_802_11_attributes) structure contains a member (**pExtPhyAttributes**) that specifies the address of an array of DOT11_PHY_ATTRIBUTES structures. When
the miniport driver calls
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes),
the driver sets the
*MiniportAttributes* parameter to the address of driver-allocated block of memory which contains an
NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure along with the array of DOT11_PHY_ATTRIBUTES
structure.

## See also

[DOT11_DIVERSITY_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_diversity_support)

[DOT11_PHY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_phy_type)

[DOT11_OFDM_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_ofdm_phy_attributes)

[DOT11_SUPPORTED_DATA_RATES_VALUE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_data_rates_value_v2)

[DOT11_ERP_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_erp_phy_attributes)

[OID_DOT11_NIC_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-nic-power-state)

[OID_DOT11_HARDWARE_PHY_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-hardware-phy-state)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_native_802_11_attributes)

[DOT11_TEMP_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_temp_type)

[DOT11_DATA_RATE_MAPPING_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_data_rate_mapping_entry)

[DOT11_HRDSSS_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_hrdsss_phy_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)