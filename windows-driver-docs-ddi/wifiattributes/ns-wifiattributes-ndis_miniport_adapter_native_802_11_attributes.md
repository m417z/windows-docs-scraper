# _NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure defines the physical and operating
attributes of the Native 802.11 miniport driver and 802.11 station.

## Members

### `Header`

The type, revision, and size of the NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure. This
member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES.

#### Revision

For the Windows Vista or Windows Server 2008 operating systems, this member must be set to
NDIS_MINIPORT_ADAPTER_802_11_ATTRIBUTES_REVISION_1.

For later versions of the Windows operating systems, this member must be set to
NDIS_MINIPORT_ADAPTER_802_11_ATTRIBUTES_REVISION_2.

#### Size

For the Windows Vista or Windows Server 2008 operating systems, this member must be set to
NDIS_SIZEOF_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES_REVISION_1.

For later versions of the Windows operating systems, this member must be set to
NDIS_SIZEOF_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES_REVISION_2.

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `OpModeCapability`

A bitmask of the miniport driver's supported operation modes. This bitmask is defined through the
following:

#### DOT11_OPERATION_MODE_EXTENSIBLE_AP

Specifies that the miniport driver supports the Extensible Access Point (ExtAP) operation mode.

This value is available beginning with Windows 7.

#### DOT11_OPERATION_MODE_EXTENSIBLE_STATION

Specifies that the miniport driver supports the Extensible Station (ExtSTA) operation
mode.

#### DOT11_OPERATION_MODE_NETWORK_MONITOR

Specifies that the miniport driver supports the Network Monitor (NetMon) operation mode.

For more information about operation modes, see
[Native 802.11 Operation
Modes](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-operation-modes).

### `NumOfTXBuffers`

The maximum number of media access control (MAC) service data unit (MSDU) packets that the 802.11
station can hold in its transmit queue. The miniport driver must support a minimum transmit queue depth
of 64.

The value of this member must not include the number of transmit buffers that the 802.11 station uses
to send packets on its own, such as Beacon packets or 802.11 control packets.

### `NumOfRXBuffers`

The maximum number of MSDU packets that the 802.11 station can buffer in its receive queue. The
miniport driver must support a minimum receive queue depth of 64.

### `MultiDomainCapabilityImplemented`

A Boolean value that, if **TRUE**, specifies that the 802.11 station can operate in multiple
regulatory domains. For more information about 802.11 regulatory domains, refer to the IEEE 802.11d-2001
standard.

### `NumSupportedPhys`

The number of PHYs on the 802.11 station.

### `SupportedPhyAttributes`

A pointer to an array of
[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes) structures. This
array must have
**NumSupportedPhys** entries and must be sorted in the same order as the list of PHY types returned
through a query of
[OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types).

### `ExtSTAAttributes`

A pointer to a
[DOT11_EXTSTA_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_extsta_attributes) structure
that specifies the attributes of the miniport driver and 802.11 station when operating in Extensible
Station (ExtSTA) mode. For more information about this operation mode, see
[Extensible Station Operation
Mode](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-operation-mode).

### `VWiFiAttributes`

A pointer to a
[DOT11_VWIFI_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_vwifi_attributes) structure
that specifies the attributes of the miniport driver and 802.11 station when it operates in Virtual
WiFi mode.

This member is available beginning with Windows 7.

### `ExtAPAttributes`

A pointer to a
[DOT11_EXTAP_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_extap_attributes) structure
that specifies the attributes of the miniport driver and 802.11 station when it operates in Extensible
Access Point (ExtAP) mode.

This member is available beginning with Windows 7.

### `WFDAttributes`

A pointer to a
[DOT11_WFD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_attributes) structure
that specifies the attributes of the miniport driver and 802.11 station when it operates in Wi-Fi Direct (WFD) mode.

This member is available beginning with Windows 8.

## Syntax

```cpp
typedef struct {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    OpModeCapability;
  ULONG                    NumOfTXBuffers;
  ULONG                    NumOfRXBuffers;
  BOOLEAN                  MultiDomainCapabilityImplemented;
  ULONG                    NumSupportedPhys;
  PDOT11_PHY_ATTRIBUTES    SupportedPhyAttributes;
  PDOT11_EXTSTA_ATTRIBUTES ExtSTAAttributes;
#if (NDIS_SUPPORT_NDIS620)
  PDOT11_VWIFI_ATTRIBUTES  VWiFiAttributes;
  PDOT11_EXTAP_ATTRIBUTES  ExtAPAttributes;
#endif
#if (NDIS_SUPPORT_NDIS630)
  PDOT11_WFD_ATTRIBUTES    WFDAttributes;
#endif
} NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES, *PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES;
```

## Remarks

When its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function is
called, the miniport driver must call the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function to define the Native 802.11 attributes of the driver and 802.11
station. The miniport driver must follow these guidelines when it makes the call to
**NdisMSetMiniportAttributes**:

* The
  *MiniportAttributes* parameter must be set to the address of a driver-allocated block of memory
  that contains an NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure along with the ExtSTA
  attributes and an array of PHY attributes.
* The
  **SupportedPhyAttributes** member must be the address of the array of
  [DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes) structures. This
  array must be within the driver-allocated memory block referenced by the
  *MiniportAttributes* parameter.
* The
  **ExtSTAAttributes** member must be the address of a
  [DOT11_EXTSTA_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_extsta_attributes) structure.
  This structure must be within the driver-allocated memory block referenced by the
  *MiniportAttributes* parameter.

For more information about the initialization requirements for a Native 802.11 miniport driver, see
[Native 802.11 Miniport
Driver Initialization](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-miniport-drivers2).

## See also

[Extensible Station Operation
Mode](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-operation-mode)

[Native 802.11 Operation Modes](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-operation-modes)

[DOT11_EXTAP_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_extap_attributes)

[DOT11_EXTSTA_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_extsta_attributes)

[OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types)

[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes)

[Native 802.11 Miniport
Driver Initialization](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-miniport-drivers2)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[DOT11_WFD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_attributes)

[DOT11_VWIFI_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_vwifi_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)