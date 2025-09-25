# KSPROPERTY_MEMBERSLIST structure

## Description

The KSPROPERTY_MEMBERSLIST structure contains a list of legal values or ranges for a property.

## Members

### `MembersHeader`

Indicates a structure of type [KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader) that specifies the size and type of information contained in the **Members** array.

### `Members`

Points to an array of entries that specify legal values or ranges for a property. Each entry describes a value or a set of a values.

## Remarks

The type of structures pointed to in the **Members** array depends on the value of **MembersHeader.MembersFlags**. See [KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader) for details on possible flag values.

The [KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values) structure contains a pointer to an array of KSPROPERTY_MEMBERSLIST structures that specify valid range and value information for a property. In turn, a [KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item) structure contains a pointer to a KSPROPERTY_VALUES structure.

For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[KSPROPERTY_BOUNDS_LONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_long)

[KSPROPERTY_BOUNDS_LONGLONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_longlong)

[KSPROPERTY_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description)

[KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)

[KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader)

[KSPROPERTY_STEPPING_LONG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936838(v=vs.85))

[KSPROPERTY_STEPPING_LONGLONG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn936841(v=vs.85))

[KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values)