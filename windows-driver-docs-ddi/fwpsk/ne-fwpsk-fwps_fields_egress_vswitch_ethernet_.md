# FWPS_FIELDS_EGRESS_VSWITCH_ETHERNET_ enumeration

## Description

The FWPS_FIELDS_EGRESS_VSWITCH_ETHERNET (formerly FWPS_FIELDS_EGRESS_VSWITCH_802_3) enumeration type specifies the data field identifiers for the
FWPS_LAYER_EGRESS_VSWITCH_ETHERNET
[run-time filtering layer](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_MAC_SOURCE_ADDRESS`

The virtual switch egress MAC source address field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_MAC_SOURCE_ADDRESS_TYPE`

The virtual switch egress MAC source address type field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_MAC_DESTINATION_ADDRESS`

The virtual switch egress MAC destination address field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_MAC_DESTINATION_ADDRESS_TYPE`

The virtual switch egress MAC destination address type field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_ETHER_TYPE`

The virtual switch egress Ethernet EtherType field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VLAN_ID`

The virtual switch egress virtual LAN (VLAN) identifier field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_TENANT_NETWORK_ID`

The virtual switch egress tenant network identifier field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_ID`

The virtual switch egress Ethernet virtual switch identifier field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_NETWORK_TYPE`

The virtual switch egress Ethernet virtual switch network type field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_SOURCE_INTERFACE_ID`

The virtual switch egress Ethernet virtual switch source identifier field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_SOURCE_INTERFACE_TYPE`

The virtual switch egress Ethernet virtual switch source interface type field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_SOURCE_VM_ID`

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_DESTINATION_INTERFACE_ID`

The virtual switch egress Ethernet virtual switch destination interface identifier field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_DESTINATION_INTERFACE_TYPE`

The virtual switch egress Ethernet virtual switch destination interface type field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_DESTINATION_VM_ID`

The virtual switch egress Ethernet virtual switch destination virtual machine (VM) identifier field.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_L2_FLAGS`

A bitwise OR of Layer 2 (L2) flags. For a list of filtering condition flags, see [Filtering Condition Flags](https://learn.microsoft.com/windows/win32/fwp/filtering-condition-flags-).

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.