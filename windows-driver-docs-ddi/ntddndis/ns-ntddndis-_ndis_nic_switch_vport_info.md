# _NDIS_NIC_SWITCH_VPORT_INFO structure

## Description

The **NDIS_NIC_SWITCH_VPORT_INFO** structure specifies the configuration for a virtual port (VPort) on a network adapter switch of the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_VPORT_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_VPORT_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_VPORT_INFO_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_VPORT_INFO_REVISION_1.

### `VPortId`

An NDIS_NIC_SWITCH_VPORT_ID value that uniquely identifies the virtual port (VPort) on the network adapter.

A value of NDIS_DEFAULT_VPORT_ID specifies the default VPort on the switch. The default VPort is always attached to the PCI Express (PCIe) Physical Function (PF) of the network adapter.

**Note** A nondefault VPort with the specified **VPortId** value must have previously been created through an OID method request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that uniquely identifies a network adapter switch that was created on the network adapter. The VPort identified through the **VPortId** member is created on the switch specified by the **SwitchId** member.

The switch identifier is an integer between zero and the number of switches that the network adapter supports. A value of NDIS_DEFAULT_SWITCH_ID indicates the default network adapter switch.

**Note** Starting with Windows Server 2012, the single root I/O virtualization (SR-IOV) interface only supports the default network adapter switch on the network adapter. The value of this member must be set to NDIS_DEFAULT_SWITCH_ID.

### `VPortName`

An NDIS_VPORT_NAME value that specifies the name of the VPort that was created on the network adapter switch. This member contains the user-friendly description of the VPort.

### `AttachedFunctionId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the identifier of a VF or the PF to which the VPort is attached.

**Note** If this value is NDIS_PF_FUNCTION_ID, the VPort is attached to the PF.

### `NumQueuePairs`

A ULONG value that specifies the number of queue pairs configured for this VPort.

A queue pair consists of a transmit queue and receive queue. Queue pairs associated with the default VPort are configured at the time of switch creation through an OID method request of [OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch).
One or more queue pairs are configured on a nondefault VPort through an OID method request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

### `InterruptModeration`

An [NDIS_NIC_SWITCH_VPORT_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_nic_switch_vport_interrupt_moderation) value that specifies the interrupt moderation setting of the VPort.

### `VPortState`

An [NDIS_NIC_SWITCH_VPORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_nic_switch_vport_state) value that specifies the state of the VPort.

### `ProcessorAffinity`

A [GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) value that specifies the group number and a bitmap of the CPUs that this VPort can be associated with.

This member is valid only for the VPorts attached to the PF. This field is not valid for nondefault VPorts that are attached to a VF.

### `LookaheadSize`

This member is reserved for future use. This member must be set to zero.

### `NumFilters`

A ULONG value that specifies the number of receive filters that have been configured on the network adapter.

**Note** Starting with NDIS 6.30, the miniport driver must maintain a counter for the current number of receive filters that are set on the network adapter. The driver must increment the counter each time a receive filter is set through an OID set request of [OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter). The driver must also decrement the counter each time a receive filter is cleared through an OID set request of [OID_RECEIVE_FILTER_CLEAR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-clear-filter).

## Remarks

An **NDIS_NIC_SWITCH_VPORT_INFO** structure contains information about one of the following:

* A nondefault VPort that was previously created through an OID method request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).
* The default VPort that is attached to the PF. The default VPort always exists and cannot be deleted.

One or more **NDIS_NIC_SWITCH_VPORT_INFO** structures are returned through the [NDIS_NIC_SWITCH_VPORT_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info_array) structure.

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

## See also

[NDIS_NIC_SWITCH_VPORT_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info_array)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport)

[OID_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vport-parameters)