# WcmRestrictionFacets enumeration

## Description

Enumerates the facet values that may be returned by the [ISettingsItem::GetRestrictionFacets](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getrestrictionfacets) method. The facet values are combined by performing an **OR** operation to provide a full identification of the facets that are defined on the base type for a particular setting. This enumeration type is also used as an input to the [ISettingsItem::GetRestriction](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getrestriction) method to specify a facet and retrieve the corresponding information for that facet.

The facet values roughly conform to the restrictions defined in [Data Type Facets](https://learn.microsoft.com/previous-versions/ms256149(v=vs.85)). Simple data types (both built-in and derived) have facets. A facet is a single defining aspect that helps determine the set of values for a simple type. For example, *MaxLength*, *minInclusive*, and *maxInclusive* are common facets for the built-in data types. All of the facets for a simple type define the set of legal values for that simple type.

## Constants

### `restrictionFacetMaxLength:0x1`

Maximum number of units of length. Units of length depend on the data type. This value must be a nonNegativeInteger.

### `restrictionFacetEnumeration:0x2`

Specified set of values. This limits a data type to the specified values.

### `restrictionFacetMaxInclusive:0x4`

Maximum value. This value must be the same data type as the inherited data type.

### `restrictionFacetMinInclusive:0x8`

Lower bound value (all values are greater than this value). This value must be the same data type as the inherited data type.