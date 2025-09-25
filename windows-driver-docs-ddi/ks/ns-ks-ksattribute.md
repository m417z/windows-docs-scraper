# KSATTRIBUTE structure

## Description

The KSATTRIBUTE structure defines an additional attribute of a data format or data range that is not covered by the [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) and [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structures or the extended information based on the format and range specifiers.

## Members

### `Size`

Specifies the size of the attribute. This is at least the size of the KSATTRIBUTE structure and may be more if there is extended information based on the identifying GUID in the **Attribute** field.

### `Flags`

Specifies the flags of the attribute. The only used flag is KSATTRIBUTE_REQUIRED; this flag specifies that an attribute is required. If this flag is not set, the attribute is optional. Note that the topmost bit is reserved for internal use in KS.

### `Attribute`

Specifies the unique identifier of the attribute.

## Remarks

Note that KSATTRIBUTE is used in conjunction with data formats and data ranges; attributes on data formats and ranges are taken into consideration when determining if a data format is acceptable to a given pin or if a data range intersects with another data range.

## See also

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))