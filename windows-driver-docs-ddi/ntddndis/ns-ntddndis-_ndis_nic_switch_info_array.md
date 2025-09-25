# _NDIS_NIC_SWITCH_INFO_ARRAY structure

## Description

The **NDIS_NIC_SWITCH_INFO_ARRAY** structure specifies an array. Each element in the array specifies the attributes of a network adapter switch that has been created on the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_INFO_ARRAY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

NDIS sets the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_INFO_ARRAY** structure, NDIS sets the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_INFO_ARRAY_REVISION_1

Original version for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_INFO_ARRAY_REVISION_1.

### `FirstElementOffset`

A ULONG value that specifies the offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_NIC_SWITCH_INFO_ARRAY** structure up to the beginning of the first element. Each element in the array is an [NDIS_NIC_SWITCH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info) structure.

**Note** If **NumElements** is set to zero, this member is ignored.

### `NumElements`

A ULONG value that specifies the number of elements that follow the **NDIS_NIC_SWITCH_INFO_ARRAY** structure.

### `ElementSize`

A ULONG value that specifies the size, in bytes, of each element that follows the **NDIS_NIC_SWITCH_INFO_ARRAY** structure.

## Remarks

NDIS returns an **NDIS_NIC_SWITCH_INFO_ARRAY** structure in the following ways:

* When NDIS handles an OID query request of [OID_NIC_SWITCH_ENUM_SWITCHES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-switches), it returns a pointer to an **NDIS_NIC_SWITCH_INFO_ARRAY** structure in the **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request).
* When NDIS calls the [ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)
  function, NDIS passes a pointer to an [NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure in the *BindParameters* parameter. NDIS sets the **NicSwitchArray** member of the **NDIS_BIND_PARAMETERS** structure to a pointer to an **NDIS_NIC_SWITCH_INFO_ARRAY** structure.
* When NDIS calls the [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)
  function, NDIS passes a pointer to an [NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure in the *AttachParameters* parameter. NDIS sets the **NicSwitchArray** member of the **NDIS_FILTER_ATTACH_PARAMETERS** structure to a pointer to an **NDIS_NIC_SWITCH_INFO_ARRAY** structure.

Each
element in the array that follows the **NDIS_NIC_SWITCH_INFO_ARRAY** structure is an
[NDIS_NIC_SWITCH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info) structure.

**Note** Starting with NDIS 6.30, only the **NDIS_NIC_SWITCH_INFO** that describes the information about the default network adapter switch is returned through an OID query request of [OID_NIC_SWITCH_ENUM_SWITCHES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-switches).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_NIC_SWITCH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_ENUM_SWITCHES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-switches)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)