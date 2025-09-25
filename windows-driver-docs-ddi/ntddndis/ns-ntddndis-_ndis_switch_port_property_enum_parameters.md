# _NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure specifies an array of policy properties for a Hyper-V extensible switch port. Each element in the array is formatted as an [NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) structure.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PortId`

 An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port for which properties are enumerated.

### `PropertyType`

 An [NDIS_SWITCH_PORT_PROPERTY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_property_type) enumeration value that specifies the port property type. When an OID method request of [OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum) is issued, the extensible switch extension returns port properties that match this property type.

### `PropertyId`

A GUID value that identifies the property for the extensible switch port.

### `SerializationVersion`

An NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION value that identifies the format version of the serialized port property data. This data is serialized for access by the extension from the Managed Object Format (MOF) file that defined the property.

**Note** For Windows Server 2012, the **SerializationVersion** member must be set to NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION_1.

### `FirstPropertyOffset`

A USHORT value that specifies the offset, in bytes, to the first [NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) element that follows the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure. The offset is measured from the start of the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure up to the beginning of the first element of the array.

**Note** If the value of **NumProperties** is zero, this member is ignored.

### `NumProperties`

A ULONG value that specifies the number of [NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) elements that follow the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure.

### `Reserved`

Reserved for future use.

## Remarks

The **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure is used in OID method requests of [OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum). An array of [NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) structures follow the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure in the information buffer that is associated with these OID set requests. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this information buffer.

Extensible switch extensions can access the first [NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) structure that is specified by the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure by using the [NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_GET_FIRST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-enum-parameters-get-first-info) macro.

For more information about extensible switch policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info)

[NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_GET_FIRST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-enum-parameters-get-first-info)

[OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum)