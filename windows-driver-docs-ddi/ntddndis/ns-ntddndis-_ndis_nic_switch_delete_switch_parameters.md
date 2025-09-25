# _NDIS_NIC_SWITCH_DELETE_SWITCH_PARAMETERS structure

## Description

The **NDIS_NIC_SWITCH_DELETE_SWITCH_PARAMETERS** structure specifies the information about the network adapter switch that will be deleted from the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_DELETE_SWITCH_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_DELETE_SWITCH_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value.

#### NDIS_NIC_SWITCH_DELETE_SWITCH_PARAMETERS_REVISION_1

Original version for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_PARAMETERS_REVISION_1.

### `Flags`

 A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that specifies a switch identifier. The switch identifier is an integer between zero and the number of switches that the network adapter supports. An NDIS_DEFAULT_SWITCH_ID value indicates the default network adapter switch.

**Note** Starting with Windows Server 2012, SR-IOV only supports the default network adapter switch on the network adapter. This member must be set to NDIS_DEFAULT_SWITCH_ID.

## Remarks

The **NDIS_NIC_SWITCH_DELETE_SWITCH_PARAMETERS** structure is used in OID method requests of [OID_NIC_SWITCH_DELETE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-delete-switch).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_DELETE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-delete-switch)