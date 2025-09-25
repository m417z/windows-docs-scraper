# FWPS_FIELDS_INBOUND_MAC_FRAME_ETHERNET_ enumeration

## Description

The **FWPS_FIELDS_INBOUND_MAC_FRAME_ETHERNET** enumeration type specifies the data field identifiers for the
FWPS_LAYER_INBOUND_MAC_FRAME_ETHERNET
[run-time filtering layer](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

**Note** In Windows 7 and Windows Server 2008 R2, the name of this enumeration was **FWPS_FIELDS_INBOUND_MAC_FRAME_802_3**.

## Constants

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_INTERFACE_MAC_ADDRESS`

The inbound MAC frame IEEE 802.3 interface MAC address field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_MAC_LOCAL_ADDRESS`

The inbound MAC frame IEEE 802.3 local MAC address field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_MAC_REMOTE_ADDRESS`

The inbound MAC frame IEEE 802.3 remote MAC address field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_MAC_LOCAL_ADDRESS_TYPE`

The inbound MAC frame IEEE 802.3 local MAC address type field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_MAC_REMOTE_ADDRESS_TYPE`

The inbound MAC frame IEEE 802.3 remote MAC address type field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_ETHER_TYPE`

The inbound MAC frame IEEE 802.3 EtherType field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_VLAN_ID`

The inbound MAC frame IEEE 802.3 VLAN identifier field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_INTERFACE`

The inbound MAC frame IEEE 802.3 interface field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_INTERFACE_INDEX`

The inbound MAC frame interface IEEE 802.3 interface index field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_NDIS_PORT`

The inbound MAC frame IEEE 802.3 NDIS port field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_L2_FLAGS`

The inbound MAC frame IEEE 802.3 flags field.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[FWPS_FIELDS_OUTBOUND_MAC_FRAME_ETHERNET](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_fields_outbound_mac_frame_ethernet_)