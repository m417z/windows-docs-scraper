# _NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM structure

## Description

The **NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM** structure specifies the custom status information for a Hyper-V extensible switch port. This information is known as *feature status* information. The format of this information is defined by the independent software vendor (ISV).

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `FeatureStatusBufferLength`

A ULONG value that specifies the size, in bytes, of the feature status buffer.

### `FeatureStatusBufferOffset`

A ULONG value that specifies the offset, in bytes, to the feature status buffer that follows the **NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM** structure. The offset is measured from the start of the **NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM** structure up to the beginning of the feature status buffer.

## Remarks

The [NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_parameters) structure is used in OID method requests of [OID_SWITCH_PORT_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-feature-status-query). This OID request returns the following structures in the information buffer that is associated with the OID request:

* An [NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_parameters) structure that specifies the parameters for the feature status information that is to be returned for an extensible switch port. The switch extension populates the **FeatureStatusVersion** member of the structure to reflect the version of the custom status being returned in the NDIS_SWITCH_FEATURE_STATUS_CUSTOM buffer. The Hyper-v Extensible switch populates all other members when issuing the query OID.
* An **NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM** structure that contains the feature status data for the specified extensible switch port. The switch extension populates the **FeatureStatusCustomBufferLength** member of the structure to reflect the size of the custom status being returned. The Hyper-v Extensible switch populates all other members when issuing the query OID.

The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this information buffer.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_feature_status_parameters)

[OID_SWITCH_PORT_FEATURE_STATUS_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-feature-status-query)