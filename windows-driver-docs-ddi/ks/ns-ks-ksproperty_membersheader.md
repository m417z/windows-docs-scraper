## Description

A driver provides a structure of type **KSPROPERTY_MEMBERSHEADER** to describe the size and type of each element in an array containing property values or ranges.

## Members

### `MembersFlags`

Specifies the type of entries in the members list. The size of valid values is determined by value type, as specified in the **PropTypeSet** member of the [**KSPROPERTY_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description) structure. The number of range pairs is determined by **MembersCount**. This should be one of the values listed in the following table.

| Value | Description |
|---|---|
| KSPROPERTY_MEMBER_RANGES | Indicates that list members are ranges, of type [**KSPROPERTY_BOUNDS_LONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_long) or [KSPROPERTY_BOUNDS_LONGLONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_longlong). |
| KSPROPERTY_MEMBER_STEPPEDRANGES | Indicates that the following members are stepped values within ranges, of type [**KSPROPERTY_STEPPING_LONG**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936838(v=vs.85)) or [**KSPROPERTY_STEPPING_LONGLONG**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936841(v=vs.85)). |
| KSPROPERTY_MEMBER_VALUES | Each entry in the members array is a single value. |

### `MembersSize`

Specifies the size, in bytes, of an individual array element.

### `MembersCount`

Specifies the number of entries in the members array.

### `Flags`

Specifies the type of entries in the members list. The size of valid values is determined by value type, as specified in the **PropTypeSet** member of the [**KSPROPERTY_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description) structure. The number of range pairs is determined by **MembersCount**. This should be one of the values listed in the following table.

| Value | Description |
|---|---|
| KSPROPERTY_MEMBER_RANGES | Indicates that list members are ranges, of type [**KSPROPERTY_BOUNDS_LONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_long) or [**KSPROPERTY_BOUNDS_LONGLONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_longlong). |
| KSPROPERTY_MEMBER_STEPPEDRANGES | Indicates that the following members are stepped values within ranges, of type [KSPROPERTY_STEPPING_LONG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936838(v=vs.85)) or [**KSPROPERTY_STEPPING_LONGLONG**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936841(v=vs.85)). |
| KSPROPERTY_MEMBER_VALUES | Each entry in the members array is a single value. |

## Remarks

The size of the array can be determined by multiplying **MembersCount** by **MembersSize**.

A [**KSPROPERTY_MEMBERSLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist) structure contains a KSPROPERTY_MEMBERSHEADER structure as its first member. The second member, **Members**, points to an array of property values or ranges.

In addition, a [**KSPROPERTY_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description) structure can be followed by a list of KSPROPERTY_MEMBERSHEADER structures.

For more information about KSPROPERTY_MEMBER_FLAG_DEFAULT, see [KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item). For more information about KSPROPERTY_MEMBER_FLAG_BASICSUPPORT_MULTICHANNEL and KSPROPERTY_MEMBER_FLAG_BASICSUPPORT_UNIFORM, see [Exposing Multichannel Nodes](https://learn.microsoft.com/windows-hardware/drivers/audio/exposing-multichannel-nodes) in the Windows Driver Kit (WDK) Audio documentation.

## See also

[**KSPROPERTY_BOUNDS_LONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_long)

[**KSPROPERTY_BOUNDS_LONGLONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_longlong)

[**KSPROPERTY_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description)

[**KSPROPERTY_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)

[**KSPROPERTY_MEMBERSLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist)

[**KSPROPERTY_STEPPING_LONG**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936838(v=vs.85))

[**KSPROPERTY_STEPPING_LONGLONG**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936841(v=vs.85))