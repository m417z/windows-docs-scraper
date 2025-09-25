# _NDIS_NIC_SWITCH_PARAMETERS structure

## Description

The **NDIS_NIC_SWITCH_PARAMETERS** structure specifies the configuration parameters of a network adapter switch on the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_PARAMETERS_REVISION_1.

### `Flags`

 A ULONG value that contains a bitwise OR of flags. The following flags are defined for this member.

#### NDIS_NIC_SWITCH_PARAMETERS_SWITCH_NAME_CHANGED

This flag specifies that the field that has been updated in the **NDIS_NIC_SWITCH_PARAMETERS** structure is the **SwitchName** member.

**Note** This flag is valid only when this structure is used in an OID set request of [OID_NIC_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-parameters).

### `SwitchType`

An
[NDIS_NIC_SWITCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_nic_switch_type) enumeration value that
specifies the type of the network adapter switch.

**Note** Starting with Windows Server 2012, Windows only supports a switch type of **NdisNicSwitchTypeExternal**. An external switch specifies that the ports connected to this type of switch can access the external network through the physical port on the network adapter. The default virtual port (VPort) on the external switch provides external network connectivity to the virtualization stack that runs in the management operating system of the Hyper-V parent partition.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that contains a switch identifier. The switch identifier is an integer between zero and the number of switches that the network adapter supports. An NDIS_DEFAULT_SWITCH_ID value indicates the default network adapter switch.

**Note** Starting with Windows Server 2012, the single root I/O virtualization (SR-IOV) interface only supports the default network adapter switch on the network adapter. The value of this member must be set to NDIS_DEFAULT_SWITCH_ID.

### `SwitchFriendlyName`

An NDIS_NIC_SWITCH_FRIENDLYNAME value that contains a description for the switch.

### `NumVFs`

A ULONG value that specifies the number of PCI Express (PCIe) Virtual Functions (VFs) that are enabled on the network adapter. VFs are enabled on the adapter when virtualization is enabled through a call to [NdisMEnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismenablevirtualization).

**Note** Before a VF can be attached to a Hyper-V child partition, resources must be allocated for it through an OID method request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

### `NdisReserved1`

Reserved for NDIS.

### `NdisReserved2`

Reserved for NDIS.

### `NdisReserved3`

Reserved for NDIS.

### `NumQueuePairsForDefaultVPort`

## Remarks

The **NDIS_NIC_SWITCH_PARAMETERS** structure is used in OID method requests of [OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch) and [OID_NIC_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-parameters). These OID requests set or query the configuration parameters of a network adapter switch.

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMEnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismenablevirtualization)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)

[OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch)

[OID_NIC_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-parameters)