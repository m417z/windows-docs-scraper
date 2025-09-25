# _NDIS_SWITCH_NIC_ARRAY structure

## Description

The **NDIS_SWITCH_NIC_ARRAY** structure specifies an array of network adapter configuration parameters. Each element in the array specifies the parameters for a network adapter that is connected to a port on a Hyper-V extensible switch. Each element is formatted as an [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structure.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_NIC_ARRAY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_NIC_ARRAY** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_NIC_ARRAY_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_NIC_ARRAY_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `FirstElementOffset`

A USHORT value that specifies the offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_SWITCH_NIC_ARRAY** structure up to the beginning of the first element. Each element in the array is an [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structure.

**Note** If **NumElements** is set to zero, this member is ignored.

### `NumElements`

A ULONG value that specifies the number of [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) elements that follow the **NDIS_SWITCH_NIC_ARRAY** structure.

### `ElementSize`

A ULONG value that specifies the size, in bytes, of the [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) elements that follows the **NDIS_SWITCH_NIC_ARRAY** structure.

## Remarks

The **NDIS_SWITCH_NIC_ARRAY** structure is returned in OID query requests of [OID_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-array). An array of [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structures follows the **NDIS_SWITCH_NIC_ARRAY** structure in the information buffer that is associated with the OID query request. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this information buffer.

Extensible switch extensions can access individual [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structures inside an **NDIS_SWITCH_NIC_ARRAY** structure by using the [NDIS_SWITCH_NIC_AT_ARRAY_INDEX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-nic-at-array-index) macro.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SWITCH_NIC_AT_ARRAY_INDEX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-nic-at-array-index)

[NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters)

[OID_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-array)