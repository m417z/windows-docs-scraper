# _NDIS_SWITCH_FEATURE_STATUS_PARAMETERS structure

## Description

The **NDIS_SWITCH_FEATURE_STATUS_PARAMETERS** structure specifies the parameters for the custom status information of a Hyper-V extensible switch. This information is known as *feature status* information. The format of this information is defined by the independent software vendor (ISV).

The status information is specified through an [NDIS_SWITCH_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_feature_status_custom) structure that is returned through an object identifier (OID) method request of [OID_SWITCH_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-feature-status-query).

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_FEATURE_STATUS_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_FEATURE_STATUS_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_FEATURE_STATUS_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_FEATURE_STATUS_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `FeatureStatusType`

An [NDIS_SWITCH_FEATURE_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_feature_status_type) enumeration value that specifies the type of the feature status information for the extensible switch.

**Note** Starting with NDIS 6.30, this member must be set to **NdisSwitchFeatureStatusTypeCustom**.

### `FeatureStatusId`

A GUID value that identifies the feature status information for the extensible switch.

This value is defined in the managed object format (MOF) class definition for the feature status information. For more information, see [Custom Switch Property Definition and Registration](https://learn.microsoft.com/windows-hardware/drivers/network/custom-switch-property-definition-and-registration).

### `FeatureStatusInstanceId`

An NDIS_SWITCH_OBJECT_INSTANCE_ID value that identifies the instance of the feature status information for the extensible switch.

### `FeatureStatusVersion`

An NDIS_SWITCH_OBJECT_VERSION value that identifies the version of the feature status information for the extensible switch. This value is defined in the MOF class definition for the feature status information.

### `SerializationVersion`

An NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION value that identifies the format version of the serialized status information for the feature status information. This data is serialized for access by the extension from the MOF file that defined the property.

**Note** For Windows Server 2012, the **SerializationVersion** member must be set to NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION_1.

### `FeatureStatusBufferOffset`

A ULONG value that specifies the offset, in bytes, to the feature status buffer that follows the **NDIS_SWITCH_FEATURE_STATUS_PARAMETERS** structure. The status buffer contains an [NDIS_SWITCH_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_feature_status_custom) structure.

The offset is measured from the start of the **NDIS_SWITCH_FEATURE_STATUS_PARAMETERS** structure up to the beginning of the [NDIS_SWITCH_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_feature_status_custom) structure.

### `FeatureStatusBufferLength`

A ULONG value that specifies the size, in bytes, of the feature status buffer.

## Remarks

The **NDIS_SWITCH_FEATURE_STATUS_PARAMETERS** structure is used in OID method requests of [OID_SWITCH_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-feature-status-query). This OID request returns the following structures in the information buffer that is associated with the OID request:

* An **NDIS_SWITCH_FEATURE_STATUS_PARAMETERS** structure that specifies the status parameters for the feature status information of the extensible switch. The switch extension populates the **FeatureStatusVersion** member of the structure to reflect the version of the custom status being returned in the NDIS_SWITCH_FEATURE_STATUS_CUSTOM buffer. The Hyper-v Extensible switch populates all other members when issuing the query OID.
* An [NDIS_SWITCH_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_feature_status_custom) structure that contains the feature status information for the extensible switch. The switch extension populates the **FeatureStatusCustomBufferLength** member of the structure to reflect the size of the custom status being returned. The Hyper-v Extensible switch populates all other members when issuing the query OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SWITCH_FEATURE_STATUS_CUSTOM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_feature_status_custom)

[NDIS_SWITCH_FEATURE_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_feature_status_type)

[OID_SWITCH_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-feature-status-query)