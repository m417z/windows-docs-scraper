# KSPROPERTY_VALUES structure

## Description

The **KSPROPERTY_VALUES** structure describes the type and acceptable default values of a property.

## Members

### `PropTypeSet`

Specifies a **KSIDENTIFIER** structure (see [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)) that identifies the data type of the property. The **Set** member of a **KSIDENTIFIER** structure indicates the set of value types supported, and the **Id** member of the same structure identifies the type within the set.

### `MembersListCount`

Specifies the number of entries in the array pointed to by **MembersList**.

### `MembersList`

Points to an array of [KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist) structures. Each entry specifies a list of possible values or sets of values that the property may assume.

## Remarks

**PropTypeSet.Set** almost always equals KSPROPTYPESETID_General. The individual value types in **KSPROPTYPESETID_General** correspond to the [**VARENUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-varenum) enumeration types.

Possible values for PropTypeSet.Id in streaming media (audio/camera) include:

| Value | Data type |
|--|--|
| VT_BLOB | Length-prefixed bytes. |
| VT_BOOL | A Boolean value. True is -1 and false is 0. |
| VT_CLSID | A class ID. |
| VT_I4 | A 4-byte integer. |
| VT_ILLEGAL | An illegal value. |
| VT_LPWSTR | A wide null-terminated string. |
| VT_R8 | An 8-byte real. |
| VT_UI1 | An unsigned character. |
| VT_UI2 | An unsigned short. |
| VT_UI4 | An unsigned 4-byte integer. |
| VT_UI8 | An unsigned 8-byte integer. |

For more information, see the [**VARENUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-varenum) enumeration.

A driver can specify a pointer to a **KSPROPERTY_VALUES** structure in the relevant **KSPROPERTY_ITEM** for a property.

For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[**KSEVENT**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)

[**KSPROPERTY_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description)

[**KSPROPERTY_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)

[**KSPROPERTY_MEMBERSLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist)

[**VARENUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-varenum)