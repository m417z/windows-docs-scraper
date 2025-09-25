# _NDIS_SWITCH_PORT_PROPERTY_PARAMETERS structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure specifies the parameters for a policy property of a Hyper-V extensible switch port.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PortId`

 An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port to which the property is assigned.

### `PropertyType`

 An [NDIS_SWITCH_PORT_PROPERTY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_property_type) enumeration value that specifies the type of port property that is contained within the property buffer.

### `PropertyId`

A GUID value that identifies the property for the extensible switch port.

For more information, see the Remarks section.

**Note** The extensible switch extension must ignore this member unless the **PropertyType** member is set to **NdisSwitchPortPropertyTypeCustom**.

### `PropertyVersion`

An NDIS_SWITCH_OBJECT_VERSION value that identifies the version of the property for the extensible switch port.

### `SerializationVersion`

An NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION value that identifies the format version of the serialized port property data. This data is serialized for access by the extension from the Managed Object Format (MOF) file that defined the property.

**Note** For Windows Server 2012, the **SerializationVersion** member must be set to NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION_1.

### `PropertyInstanceId`

An NDIS_SWITCH_OBJECT_INSTANCE_ID value that identifies the instance of the property for the extensible switch port.

### `PropertyBufferLength`

A ULONG value that specifies the size, in bytes, of the property buffer.

### `PropertyBufferOffset`

A ULONG value that specifies the offset, in bytes, to the property buffer that follows the **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure. The offset is measured from the start of the **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure up to the beginning of the property buffer.

### `Reserved`

Reserved for future use.

## Remarks

The **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure is used in the following OID set requests:

* [OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)
* [OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)

The property buffer contains a structure that is associated with the **PropertyType** member. The property buffer follows the **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure in the information buffer that is associated with these OID set requests. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this information buffer.

The extensible switch extension must follow these guidelines when it processes an **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure:

* If the **PropertyType** member is set to **NdisSwitchPortPropertyTypeSecurity**, the property buffer is formatted as an [NDIS_SWITCH_PORT_PROPERTY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_security) structure.
* If the **PropertyType** member is set to **NdisSwitchPortPropertyTypeVlan**, the property buffer is formatted as an [NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan) structure.
* If the **PropertyType** member is set to **NdisSwitchPortPropertyTypeProfile**, the property buffer is formatted as an [NDIS_SWITCH_PORT_PROPERTY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_profile) structure.
* If the **PropertyType** member is set to **NdisSwitchPortPropertyTypeCustom**, the **PropertyId** member must be set to the GUID value the independent software vendor (ISV) created for the custom port property. The property buffer is formatted as a [NDIS_SWITCH_PORT_PROPERTY_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_custom) structure that contains the parameters for the custom port property as defined by the ISV.

Extensible switch extensions can access the custom port property inside an **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure by using the [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-parameters-get-property) macro.

For more information about extensible switch policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_PORT_PROPERTY_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_custom)

[NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-property-parameters-get-property)

[NDIS_SWITCH_PORT_PROPERTY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_profile)

[NDIS_SWITCH_PORT_PROPERTY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_security)

[NDIS_SWITCH_PORT_PROPERTY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_property_type)

[NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan)

[OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)

[OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)