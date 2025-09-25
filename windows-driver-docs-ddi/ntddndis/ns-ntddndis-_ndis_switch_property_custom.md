# _NDIS_SWITCH_PROPERTY_CUSTOM structure

## Description

The **NDIS_SWITCH_PROPERTY_CUSTOM** structure specifies a custom profile property for the Hyper-V extensible switch.

Independent software vendors (ISVs) define the format for the custom properties. The format of the custom property is proprietary to the ISV.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PROPERTY_CUSTOM** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PROPERTY_CUSTOM** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PROPERTY_CUSTOM_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PROPERTY_CUSTOM_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PropertyBufferLength`

A ULONG value that specifies the size, in bytes, of the buffer that contains the custom extensible switch property.

### `PropertyBufferOffset`

A ULONG value that specifies the offset, in bytes, to the property buffer. The offset is measured from the start of the **NDIS_SWITCH_PROPERTY_CUSTOM** structure up to the beginning of the property buffer.

## Remarks

The **NDIS_SWITCH_PROPERTY_CUSTOM** structure is used in the following OID set requests:

* [OID_SWITCH_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-property-add)
* [OID_SWITCH_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-property-update)

The **NDIS_SWITCH_PROPERTY_CUSTOM** structure follows the [NDIS_SWITCH_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_parameters) structure in the buffer that is associated with these OID set requests. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this buffer.

Extensible switch extensions can access the custom extensible switch property buffer that is specified by an **NDIS_SWITCH_PROPERTY_CUSTOM** structure by using the [NDIS_SWITCH_PROPERTY_CUSTOM_GET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-property-custom-get-buffer) macro.

For more information about extensible switch policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_PROPERTY_CUSTOM_GET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-property-custom-get-buffer)

[NDIS_SWITCH_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_parameters)

[OID_SWITCH_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-property-add)

[OID_SWITCH_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-property-update)