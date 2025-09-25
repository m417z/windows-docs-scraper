# _NDIS_NIC_SWITCH_INFO structure

## Description

The **NDIS_NIC_SWITCH_INFO** structure specifies the information about a network adapter switch on a network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_INFO_REVISION_1

Original version for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_INFO_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of configuration flags that are enabled on the switch.

**Note** For NDIS 6.30, no configuration flags are defined for the switch. The **Flags** member must be set to zero.

### `SwitchType`

An [NDIS_NIC_SWITCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_nic_switch_type) value that specifies the type of the switch.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that specifies a switch identifier. The switch identifier is an integer between zero and the number of switches that the network adapter supports. An NDIS_DEFAULT_SWITCH_ID value indicates the default network adapter switch.

**Note** Starting with Windows Server 2012, the single root I/O virtualization (SR-IOV) interface only supports the default network adapter switch on the network adapter. The value of this member must be set to NDIS_DEFAULT_SWITCH_ID.

### `SwitchFriendlyName`

An NDIS_NIC_SWITCH_FRIENDLYNAME value that contains the user-friendly description of the switch.

### `NumVFs`

A ULONG value that specifies the number of PCI Express (PCIe) Virtual Functions (VFs) that are enabled on the network adapter. Enabled VFs can be in either an allocated or unallocated state.

### `NumAllocatedVFs`

A ULONG value that specifies the number of VFs that have been allocated on the network adapter switch specified by **SwitchId**. VFs are allocated through OID set requests of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

### `NumVPorts`

A ULONG value that specifies the number of virtual ports (VPorts) that are configured on the network adapter switch specified by **SwitchId**.

This ULONG value is the sum of the following:

* The maximum number of VPorts that can be created through OID set requests of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).
* The default VPort attached to the Physical Function (PF).

### `NumActiveVPorts`

A ULONG value that specifies the number of VPorts that have been created on the network adapter switch specified by **SwitchId**.

**Note** This ULONG value includes the default VPort, in addition to the nondefault VPorts created through OID set requests of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

### `NumQueuePairsForDefaultVPort`

A ULONG value that specifies the number of queue pairs allocated for the default VPort. The default VPort is always attached to the PF.

A queue pair consists of a transmit queue and receive queue. The miniport driver associates one or more queue pairs with the default VPort at the time of switch creation through an OID method request of [OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch).

**Note** Starting with NDIS 6.30, there can only be one queue pair that can be configured for the default VPort.

### `NumQueuePairsForNonDefaultVPorts`

A ULONG value that specifies the number of queue pairs allocated for the nondefault VPorts. A nondefault VPort can be attached to either the PF or any VF of the network adapter.

The miniport driver associates one or more queue pairs with a nondefault VPort through an OID method request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

### `NumActiveDefaultVPortMacAddresses`

A ULONG value that specifies the number of unicast MAC address filters that are currently set on the default VPort that is attached to the PF of the network adapter.

### `NumActiveNonDefaultVPortMacAddresses`

A ULONG value that specifies the number of unicast MAC address filters that are currently set on nondefault VPorts.

### `NumActiveDefaultVPortVlanIds`

A ULONG value that specifies the number of virtual local area network (VLAN) identifier filters that are currently set on the default VPort.

### `NumActiveNonDefaultVPortVlanIds`

A ULONG value that specifies the number of VLAN identifier filters that are currently set on the nondefault VPorts.

## Remarks

The **NDIS_NIC_SWITCH_INFO** structure is used in OID query requests of [OID_NIC_SWITCH_ENUM_SWITCHES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-switches). This OID request is used to enumerate the network adapter switches on a network adapter. When this OID request is issued, one or more **NDIS_NIC_SWITCH_INFO** structures are returned within an [NDIS_NIC_SWITCH_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info_array) structure.

**Note** Starting with NDIS 6.30, only the **NDIS_NIC_SWITCH_INFO** that describes the information about the default network adapter switch is returned through an OID request of [OID_NIC_SWITCH_ENUM_SWITCHES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-switches).

An **NDIS_NIC_SWITCH_INFO** structure contains information about a network adapter switch that was previously created through an OID method request of OID_NIC_SWITCH_CREATE_SWITCH.

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

## See also

[NDIS_NIC_SWITCH_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info_array)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch)

[OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport)