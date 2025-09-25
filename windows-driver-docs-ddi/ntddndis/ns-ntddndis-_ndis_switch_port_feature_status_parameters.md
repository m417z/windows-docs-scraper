# _NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS structure

## Description

The **NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS** structure specifies the parameters for the custom status information of a Hyper-V extensible switch port. This information is known as *feature status* information. The format of this information is defined by the independent software vendor (ISV).

The status information is specified through an [NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_custom) structure and is returned through an OID method request of [OID_SWITCH_PORT_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-feature-status-query).

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PortId`

 An NDIS_SWITCH_PORT_ID value that specifies the numeric identifier for an extensible switch port. This value uniquely identifies the port on the extensible switch for which feature status information is to be returned.

### `FeatureStatusType`

An [NDIS_SWITCH_PORT_FEATURE_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_feature_status_type) enumeration value that specifies the type of the status information for a custom extensible switch port profile property.

**Note** Starting with NDIS 6.30, this member must be set to **NdisSwitchPortPropertyTypeCustom**.

### `FeatureStatusId`

An NDIS_SWITCH_OBJECT_ID value that identifies the profile property for the extensible switch port.

### `FeatureStatusVersion`

An NDIS_SWITCH_OBJECT_VERSION value that identifies the version of the profile property for the extensible switch port.

### `SerializationVersion`

An NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION value that identifies the format version of the serialized port property data. This data is serialized for access by the extension from the Managed Object Format (MOF) file that defined the property.

**Note** For Windows Server 2012, the **SerializationVersion** member must be set to NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION_1.

### `FeatureStatusInstanceId`

An NDIS_SWITCH_OBJECT_INSTANCE_ID value that identifies the instance of the feature status information for the extensible switch port.

### `FeatureStatusBufferLength`

A ULONG value that specifies the size, in bytes, of the feature status buffer.

### `FeatureStatusBufferOffset`

A ULONG value that specifies the offset, in bytes, to the feature status buffer that follows the **NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS** structure. The feature status buffer contains an [NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_custom) structure.

The offset is measured from the start of the **NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS** structure up to the beginning of the [NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_custom) structure.

### `Reserved`

Reserved for future use.

## Remarks

The **NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS** structure is used in OID method requests of [OID_SWITCH_PORT_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-feature-status-query). This OID request returns the following structures in the information buffer that is associated with the OID request:

* An **NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS** structure that specifies the parameters for a custom property of an extensible switch port for which status information is to be returned. The switch extension populates the **FeatureStatusVersion** member of the structure to reflect the version of the custom status being returned in the NDIS_SWITCH_FEATURE_STATUS_CUSTOM buffer. The Hyper-v Extensible switch populates all other members when issuing the query OID.
* An [NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_custom) structure that contains the status information for the extensible switch port property. The switch extension populates the **FeatureStatusCustomBufferLength** member of the structure to reflect the size of the custom status being returned. The Hyper-v Extensible switch populates all other members when issuing the query OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_custom)

[NDIS_SWITCH_PORT_PROPERTY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_property_type)

[OID_SWITCH_PORT_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-feature-status-query)