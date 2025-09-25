# _NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure contains information about a Hyper-V extensible switch port policy property.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PropertyVersion`

An NDIS_SWITCH_OBJECT_VERSION value that identifies the version of the property for the extensible switch port.

### `PropertyInstanceId`

An NDIS_SWITCH_OBJECT_INSTANCE_ID value that specifies the instance identifier for the extensible switch port property.

### `QwordAlignedPropertyBufferLength`

A ULONG value that specifies the aligned size, in bytes, of the property buffer.

### `PropertyBufferLength`

A ULONG value that specifies the actual size, in bytes, of the property buffer.

**Note** This value must be less than or equal to the value of the **QwordAlignedPropertyBufferLength** member.

### `PropertyBufferOffset`

A ULONG value that specifies the offset, in bytes, to the property buffer that follows the **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure. The offset is measured from the start of the [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure up to the beginning of the property buffer.

## Remarks

The **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure is used in OID method requests of [OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum). An array of **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structures follow the [NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_parameters) structure in the information buffer that is associated with this OID request. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this information buffer.

Extensible switch extensions can access the next **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** element that follows an **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure in the array by using the [NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_GET_NEXT](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-enum-info-get-next) macro.

Extensible switch extensions can access the port property buffer that is specified by an **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure by using the [NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-enum-info-get-property) macro.

For more information about extensible switch policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_GET_NEXT](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-enum-info-get-next)

[NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-enum-info-get-property)

[NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_parameters)

[OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum)