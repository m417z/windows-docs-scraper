# KSPROPERTY_DESCRIPTION structure

## Description

The **KSPROPERTY_DESCRIPTION** structure specifies the size and type of values contained in a specific property.

## Members

### `AccessFlags`

Specifies the access allowed to this property. A basic-support request sets this member to the bitwise OR of the flags for all the access types that the handler supports for this property. For a list of possible flag values, see [**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `DescriptionSize`

Specifies total size in bytes of the **KSPROPERTY_DESCRIPTION** structure and any values entries that follow it. If the basic-support property request returns no values entries, this member is the size of **KSPROPERTY_DESCRIPTION**.

### `PropTypeSet`

A structure of type [**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier). If supported by the specific property, specifies the type of values contained in this property. This group is uniquely specified by a GUID, such that new types of values may be created without overlapping with extensions to this set. The value types indicate the type of the value (like VT_BOOL, VT_UI4 in the standard set). This is GUID_NULL, with an identifier of zero, if values information is not supported by this property.

### `MembersListCount`

Specifies the number of [**KSPROPERTY_MEMBERSHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader) structures to follow this header.

### `Reserved`

Reserved for future use. Set to zero.

## Remarks

A driver returns the **KSPROPERTY_DESCRIPTION** structure in response to a basic support property request from a client.

The property values type set is specified by a **KSIDENTIFIER** structure. The basic set supported is [**KSPROPSETID_General**](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-general). The identifiers within that set are the standard VARENUM types used for OLE.

The values information that may follow the **KSPROPERTY_DESCRIPTION** structure is described by a list of [**KSPROPERTY_MEMBERSLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist) structures, each of which contains data range information.

For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier)

[**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[**KSPROPERTY_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)

[**KSPROPERTY_MEMBERSHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader)

[**KSPROPERTY_VALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values)