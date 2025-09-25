## Description

The **FWPS_FIELDS_INGRESS_VSWITCH_ETHERNET** (formerly **WPS_FIELDS_INGRESS_VSWITCH_802_3**) enumeration type specifies the data field identifiers for the [FWPS_LAYER_INGRESS_VSWITCH_ETHERNET](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) run-time filtering layer.

## Constants

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_MAC_SOURCE_ADDRESS`

The virtual switch ingress MAC source address field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_MAC_SOURCE_ADDRESS_TYPE`

The virtual switch ingress MAC source address type field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_MAC_DESTINATION_ADDRESS`

The virtual switch ingress MAC destination address field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_MAC_DESTINATION_ADDRESS_TYPE`

The virtual switch ingress MAC destination address type field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_ETHER_TYPE`

The virtual switch ingress Ethernet EtherType field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VLAN_ID`

The virtual switch ingress virtual LAN (VLAN) identifier field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VSWITCH_TENANT_NETWORK_ID`

The virtual switch ingress tenant network identifier field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VSWITCH_ID`

The virtual switch ingress identifier field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VSWITCH_NETWORK_TYPE`

The virtual switch ingress network type field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VSWITCH_SOURCE_INTERFACE_ID`

The virtual switch ingress source interface identifier field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VSWITCH_SOURCE_INTERFACE_TYPE`

The virtual switch ingress source interface type field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VSWITCH_SOURCE_VM_ID`

The virtual switch ingress source virtual machine (VM) identifier field.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_L2_FLAGS`

A bitwise OR of Layer 2 (L2) flags. For a list of filtering condition flags, see [Filtering condition flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_COMPARTMENT_ID`

The compartment that the network interface belongs to.

Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

## See also