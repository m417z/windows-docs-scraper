# FWPS_FIELDS_OUTBOUND_MAC_FRAME_ETHERNET_ enumeration

## Description

The **FWPS_FIELDS_OUTBOUND_MAC_FRAME_ETHERNET** enumeration type specifies the data field identifiers for the
FWPS_LAYER_OUTBOUND_MAC_FRAME_ETHERNET
[run-time filtering layer](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

**Note** In Windows 7 and Windows Server 2008 R2, the name of this enumeration was **FWPS_FIELDS_OUTBOUND_MAC_FRAME_802_3**.

## Constants

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_INTERFACE_MAC_ADDRESS`

The outbound MAC frame IEEE 802.3 interface MAC address field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_MAC_LOCAL_ADDRESS`

The outbound MAC frame IEEE 802.3 local MAC address field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_MAC_REMOTE_ADDRESS`

The outbound MAC frame IEEE 802.3 remote MAC address field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_MAC_LOCAL_ADDRESS_TYPE`

The outbound MAC frame IEEE 802.3 local MAC address type field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_MAC_REMOTE_ADDRESS_TYPE`

The outbound MAC frame IEEE 802.3 remote MAC address type field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_ETHER_TYPE`

The outbound MAC frame IEEE 802.3 EtherType field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_VLAN_ID`

The outbound MAC frame IEEE 802.3 VLAN identifier field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_INTERFACE`

The outbound MAC frame IEEE 802.3 interface field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_INTERFACE_INDEX`

The outbound MAC frame IEEE 802.3 interface index field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_NDIS_PORT`

The outbound MAC frame IEEE 802.3 NDIS port field.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_L2_FLAGS`

A bitwise OR of Layer 2 (L2) flags. For a list of filtering condition flags, see [Filtering Condition Flags](https://learn.microsoft.com/windows/win32/fwp/filtering-condition-flags-).

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_COMPARTMENT_ID`

The compartment that the network interface belongs to. Windows supports use of compartments for network stack isolation. You can use this to enable a multi-tenant network stack with network namespaces in different compartments.

> [!NOTE]
> Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[FWPS_FIELDS_INBOUND_MAC_FRAME_ETHERNET](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_fields_inbound_mac_frame_ethernet_)