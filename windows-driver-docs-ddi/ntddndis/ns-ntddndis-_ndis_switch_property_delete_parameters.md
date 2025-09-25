# _NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS structure

## Description

The **NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS** structure specifies the parameters for a Hyper-V extensible switch profile property that will be deleted.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PropertyType`

 An [NDIS_SWITCH_PROPERTY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_property_type) enumeration value that specifies the type of extensible switch property that will be deleted.

### `PropertyId`

A GUID value that identifies the property for the extensible switch.

### `PropertyInstanceId`

An NDIS_SWITCH_OBJECT_INSTANCE_ID value that specifies the instance identifier of the extensible switch property.

## Remarks

The **NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS** structure is used in OID set requests of [OID_SWITCH_PROPERTY_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-property-delete).

For more information about extensible switch policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SWITCH_PROPERTY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_property_type)

[OID_SWITCH_PROPERTY_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-property-delete)