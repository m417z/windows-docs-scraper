# _NDIS_NIC_SWITCH_DELETE_VPORT_PARAMETERS structure

## Description

The **NDIS_NIC_SWITCH_DELETE_VPORT_PARAMETERS** structure specifies the information about a virtual port (VPort) that will be deleted from a network adapter switch on the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_DELETE_VPORT_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_DELETE_VPORT_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_DELETE_VPORT_PARAMETERS_REVISION_1

Original version for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_DELETE_VPORT_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `VPortId`

An NDIS_NIC_SWITCH_VPORT_ID value that uniquely identifies the virtual port (VPort) to be deleted. The VPort with the specified NDIS_NIC_SWITCH_VPORT_ID value must have previously been created through an OID set request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

**Note** The default VPort that is attached to the PCI Express (PCIe) Physical Function (PF) cannot be deleted. The **VPortId** member must not be set to DEFAULT_PORT_NUMBER.

## Remarks

The NDIS_NIC_SWITCH_DELETE_PORT_PARAMETERS structure is used in OID set requests of [OID_NIC_SWITCH_DELETE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-delete-vport).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport)

[OID_NIC_SWITCH_DELETE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-delete-vport)