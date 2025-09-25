# _NDIS_SWITCH_PORT_PROPERTY_VLAN structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_VLAN** structure specifies a virtual local area network (VLAN) policy property for a Hyper-V extensible switch port.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_VLAN** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_VLAN** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_VLAN_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PORT_PROPERTY_VLAN_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `OperationMode`

An [NDIS_SWITCH_PORT_VLAN_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_vlan_mode) enumeration value that specifies the operation mode of the VLAN.

### `VlanProperties`

A structure that specifies the properties of a VLAN with an operation mode of **NdisSwitchPortVlanModeAccess** or **NdisSwitchPortVlanModeTrunk**. This structure contains the following members:

### `VlanProperties.AccessVlanId`

A UINT16 value that specifies the VLAN identifier for the extensible switch port that operates in VLAN access mode.

**Note** This member is only valid if the **OperationMode** member is set to **NdisSwitchPortVlanModeAccess**.

### `VlanProperties.NativeVlanId`

A UINT16 value that specifies the VLAN identifier for the extensible switch port that operates in VLAN trunk mode.

### `VlanProperties.PruneVlanIdArray`

An array of UINT64 elements that specifies VLAN identifiers whose packets are blocked on an extensible switch port.

The array has 64 UINT64 elements that represent 4096 consecutive bits.
Each bit that has a value of one specifies a VLAN identifier whose packets are blocked from being sent or received on an extensible switch port. For example, if bit three is set to one, packet traffic from VLAN identifier three is blocked on a port. Similarly, if bit 64 is set to zero, packet traffic from VLAN identifier 64 is not blocked on a port.

**Note** VLANS with identifiers that map to a bit value of one are
always blocked. This overrides the equivalent bit setting for the VLAN identifier in the **TrunkVlanIdArray** member.

### `VlanProperties.TrunkVlanIdArray`

An array of UINT64 elements that specifies VLAN identifiers whose packets are allowed on an extensible switch port.

The array has 64 UINT64 elements that represent 4096 consecutive bits.
Each bit that has a value of one specifies a VLAN identifier whose packets are allowed to be sent or received on an extensible switch port. For example, if bit two is set to one, packet traffic from VLAN identifier two is allowed on a port. Similarly, if bit 1954 is set to zero, packet traffic from VLAN identifier 1954 is not allowed on a port.

### `PvlanProperties`

A structure that specifies the properties of a VLAN with an operation mode of **NdisSwitchPortVlanModePrivate**. This structure contains the following members:

### `PvlanProperties.PvlanMode`

An [NDIS_SWITCH_PORT_PVLAN_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_pvlan_mode) enumeration value that specifies the operation mode of the PVLAN.

### `PvlanProperties.PrimaryVlanId`

A UINT16 value that specifies the primary VLAN identifier for an extensible switch port.

**Note** This member is only valid if the **PvlanMode** member is set to **NdisSwitchPortPvlanModeCommunity**.

### `PvlanProperties.SecondaryVlanId`

A UINT16 value that specifies the secondary VLAN identifier for an extensible switch port.

**Note** This member is only valid if the **PvlanMode** member is set to **NdisSwitchPortPvlanModeIsolated** or **NdisSwitchPortPvlanModeCommunity**.

### `PvlanProperties.SecondaryVlanIdArray`

An array of UINT64 elements that specify the secondary VLAN identifiers for an extensible switch port.

The array has 64 UINT64 elements, which represent 4096 consecutive bits.
Each bit that has a value of one specifies a secondary VLAN identifier for the extensible switch port. For example, if bit five is set to one, the secondary VLAN identifier is five. Similarly, if bit 128 is set to zero, 128 cannot be used as a secondary VLAN identifier.

**Note** This member is only valid if the **PvlanMode** member is set to **NdisSwitchPortPvlanModePromiscuous**.

### `SupportedModes`

A UINT64 value that contains a bitwise OR of the flags that specify the VLAN operation modes that are supported on the extensible switch port. The following bits specify the supported operation modes:

#### Bit 0

Specifies a VLAN access operation mode in which packets from a single VLAN can be sent or received over the port. These packets could be forwarded from other ports on the extensible switch.

#### Bit 1

Specifies a VLAN truck operation mode where packets from multiple VLANs and non-VLAN packets can be sent or received over the port. These packets could be forwarded from other ports on the extensible switch.

#### Bit 2

Specifies an operation mode where packets from a single VLAN can be sent or received over the port. These packets cannot be forwarded from other ports on the extensible switch.

## Remarks

The **NDIS_SWITCH_PORT_PROPERTY_VLAN** structure is used in the following OID set requests:

* [OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)
* [OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)

The **NDIS_SWITCH_PORT_PROPERTY_VLAN** structure follows the [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure in the buffer that is associated with these OID set requests. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this buffer.

Port properties, such as **NDIS_SWITCH_PORT_PROPERTY_VLAN**, are enforced by the extensible switch extension that is installed as a forwarding extension. This type of extension enforces its own rules for forwarding packets, OIDs, and status indications through the extensible switch driver stack. There can be only one forwarding extension per each instance of an extensible switch.

For more information on forwarding extensions, see [Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions).

**Note** If a forwarding extension is not installed, the extensible switch interface enforces the port property itself.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters)

[NDIS_SWITCH_PORT_VLAN_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_vlan_mode)

[OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)

[OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)